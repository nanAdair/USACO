/*
ID: wangbn11
LANG: C
TASK: transform
*/
#include <stdio.h>
#include <string.h>

void rotate90(char s[][10]);
void rotate180(char s[][10]);
void rotate270(char s[][10]);
void reflection(char s[][10]);
int combination(char s[][10], char t[][10]);
int cmpX(char s[][10], char t[][10]);

int number;

int main()
{
    char stiles[10][10];
    char ttiles[10][10];
    FILE *fin = fopen("transform.in", "r");
    FILE *fout = fopen("transform.out", "w");
    
    fscanf(fin, "%d", &number);
    int i;
    for(i = 0; i < number; i++)
        fscanf(fin, "%s", stiles[i]);
    for(i = 0; i < number; i++)
        fscanf(fin, "%s", ttiles[i]);
   /*   
    if(cmpX(stiles, ttiles)){
        fprintf(fout, "6\n");
        return 0;
    }
   */ 
    rotate90(stiles);
    if(cmpX(stiles, ttiles)){
        fprintf(fout, "1\n");
        return 0;
    }
    rotate270(stiles);
    
    rotate180(stiles);
    if(cmpX(stiles, ttiles)){
        fprintf(fout, "2\n");
        return 0;
    }
    rotate180(stiles);
    
    rotate270(stiles);
    if(cmpX(stiles, ttiles)){
        fprintf(fout, "3\n");
        return 0;
    }
    rotate90(stiles);
    
    reflection(stiles);
    if(cmpX(stiles, ttiles)){
        fprintf(fout, "4\n");
        return 0;
    }
    reflection(stiles);
    
   if(combination(stiles, ttiles)){
       fprintf(fout, "5\n");
       return 0;
   } 
   
   fprintf(fout, "7\n");
   return 0;
}

void rotate90(char s[][10])
{
    char temp[10][10];
    int i, j;
    for(i = 0; i < number; i++){
        for(j = 0; j < number; j++)
            temp[i][j] = s[i][j];
    }
    
    for(i = 0; i < number; i++){
        for(j = 0; j < number; j++){
            s[i][j] = temp[number - j - 1][i];
        }
    }
}

void rotate180(char s[][10])
{
    int i;
    for(i = 0; i < 2; i++)
        rotate90(s);
}

void rotate270(char s[][10])
{
    int i;
    for(i = 0; i < 3; i++)
        rotate90(s);
}

void reflection(char s[][10])
{
    char temp[10][10];
    int i, j;
    for(i = 0; i < number; i++){
        for(j = 0; j < number; j++)
            temp[i][j] = s[i][j];
    }
    
    for(i = 0; i < number; i++){
        for(j = 0; j < number; j++)
            s[i][j] = temp[i][number- 1 -j];
    }
}

int combination(char s[][10], char t[][10])
{
    int re = 0;
    reflection(s);
    
    rotate90(s);
    if(cmpX(s, t))
        return 1;
    rotate270(s);
    
    rotate180(s);
    if(cmpX(s, t))
        return 1;
    rotate180(s);
    
    rotate270(s);
    if(cmpX(s, t))
        return 1;
    
    return 0;
}

int cmpX(char s[][10], char t[][10])
{
    int i, j;
    for(i = 0; i < number; i++){
        for(j = 0; j < number; j++){
            if(s[i][j] != t[i][j])
                return 0;
        }
    }
    return 1;
}

