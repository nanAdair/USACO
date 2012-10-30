/*
ID: wangbn11
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <string.h>

int right(char *s, int index);
int left(char *s, int index);

int main()
{
    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");
    
    int number;
    char beads[351];
    fscanf(fin, "%d\n%s", &number, beads);
    
    int max = 0;
    int i;
    for(i = 0; i <number; i++){
        int c;
        c = left(beads, i) + right(beads, (i + 1)%number);
        max = c > max ? c : max;
    }
    fprintf(fout, "%d\n", max < number ? max : number);
    
    fclose(fin);
    fclose(fout);
}

int right(char *s, int index)
{
    char sign = s[index];
    int number = 1;
    int temp = (index + 1) % strlen(s);
    
    while(sign == s[temp] || s[temp] == 'w' || sign == 'w'){
        if(s[temp] != 'w')
            sign = s[temp];
        number++;
        temp = (temp + 1) % strlen(s);
        if(temp == index)
            break;
    }
    
    return number;
}

int left(char *s, int index)
{
    char sign = s[index];
    int number = 1;
    int temp = (index - 1 + strlen(s)) % strlen(s);
    
    while(sign == s[temp] || s[temp] == 'w' || sign == 'w'){
        if(s[temp] != 'w')
            sign = s[temp];
        number++;
        temp = (temp - 1 + strlen(s)) % strlen(s);
        if(temp == index)
            break;
    }
    
    return number;
}
