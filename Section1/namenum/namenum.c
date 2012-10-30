/*
ID: wangbn11
LANG: C
TASK: namenum
*/
#include <stdio.h>
#include <string.h>
/* Text Here:
 * 1. using index marks instead of fullfil a sanlie
 * 2. when there have to be many for to iterate the item, notice using dfs to
 * make it alive
 * */

int calculate(char *s, char *t, int dim, int depth, char valid[][13], FILE *);
int test(char *s, char valid[][13]);

char *ch[10] = {
    " ", " ",
    "ABC",
    "DEF",
    "GHI",
    "JKL",
    "MNO",
    "PRS",
    "TUV",
    "WXY"
};
/*
struct name {
    char *s;
    struct name *next;
};*/

int match = 0;
int charBegin[27] = {0};

int main()
{
    FILE *fin = fopen("namenum.in", "r");
    FILE *fout = fopen("namenum.out", "w");

    char valid[5000][13];
    FILE *data = fopen("dict.txt", "r");
    char c = 'A';
    int i, j;
    i = j = 0;
    while(fscanf(data, "%s", *(valid+i)) > 0){
        if(*(valid + i)[0] != c){
            c = *(valid + i)[0];
            charBegin[++j] = i;
        }
        i++;
    }
    fclose(data);
    
    char number[13];
    fscanf(fin, "%s", number);
    int depth = strlen(number) -1;
    char name[13];
    
    if(!calculate(number, name, 0, depth, valid, fout))
        fprintf(fout, "NONE\n");
    fclose(fin);
    fclose(fout);
}

int calculate(char *s, char *t, int dim, int depth, char valid[][13], FILE *fout)
{
    if(dim < depth){
        int i;
        for(i = 0; i < 3; i++){
            t[dim] = ch[s[dim] - '0'][i];
            calculate(s, t, dim + 1, depth, valid, fout);
        }
    }
    else if(dim == depth){
        int i;
        for(i = 0; i < 3; i++){
            t[dim] = ch[s[dim] - '0'][i];
            t[dim + 1] = '\0';
            if(test(t, valid)){
                match = 1;
                fprintf(fout, "%s\n", t);
            }
        }
    }
    return match;
}

int test(char *t, char valid[][13])
{
    int i = 0;
    while(t[0] != valid[charBegin[i]][0])
        i++;
    int j;
    
    for(j = charBegin[i]; j < charBegin[i+1]; j++){
        if(strcmp(t, valid[j]) == 0)
            return 1;
    }
    
    return 0;
}
