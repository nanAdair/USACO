/*
ID: wangbn11
LANG: C
TASK: numtri
*/
#include <stdio.h>
#include <stdlib.h>

#define N 1001
#define max(a,b) (a > b ? a : b)

void cal(int [][N], int [][N], int);

int main()
{
    FILE *fin = fopen("numtri.in", "r");
    FILE *fout = fopen("numtri.out", "w");
    int count;
    fscanf(fin, "%d", &count);
    int i, j;
    int number[N][N], res[N][N];
    
    for(i = 1; i <= count; i++){
        for(j = 0; j < i; j++)
            fscanf(fin, "%d", &number[i][j]);
    }
    
    cal(number, res, count);
    fprintf(fout, "%d\n", res[1][0]);
    fclose(fin);
    fclose(fout);
}

void cal(int number[N][N], int res[N][N], int count)
{
    int i;
    for(i = 0; i < count; i++)
        res[count][i] = number[count][i];
    
    i = count-1;
    while(i > 0){
        int j;
        for(j = 0; j < i; j++)
            res[i][j] = max(res[i+1][j], res[i+1][j+1])+number[i][j];
        i--;
    }

}

