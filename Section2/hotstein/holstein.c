/*
ID: wangbn11
LANG: C
TASK: holstein
*/
#include <stdio.h>

int limit, find, types, lowerbound[25], used[16], mark[16];
void comp(int [16][25], int index, int depth, int count);
int judge(int [16][25], int depth);

int main()
{
    FILE *fin = fopen("holstein.in", "r");
    FILE *fout = fopen("holstein.out", "w");
    int i, j, cur[16][25];
    fscanf(fin, "%d", &types);
    for (i = 0; i < types; i++)
        fscanf(fin, "%d", lowerbound+i);
    fscanf(fin, "%d", &limit);
    for (i = 1; i <= limit; i++)
        for (j = 0; j < types; j++)
            fscanf(fin, "%d", &cur[i][j]);
    
    find = 0;
    for (j = 0; j < 16; j++)
        used[j] = mark[j] = 0;
    for (i = 1; i <= limit; i++){
        comp(cur, 1, i, 0);
        if(find == 1)
            break;
    }
    
    fprintf(fout, "%d ", i);
    for (j = 0; j < i-1; j++)
        fprintf(fout, "%d ", mark[j]);
    fprintf(fout, "%d\n", mark[i-1]);
    
    fclose(fin);
    fclose(fout);
}

void comp(int cur[16][25], int index, int depth, int count)
{
    if (find == 1)
        return ;
    if (count < depth){
        int i;
        for (i = index; i <= limit; i++){
            if (used[i] == 0 && find == 0){
                used[i] = 1;
                mark[count] = i;
                comp(cur, i, depth, count+1);
                used[i] = 0;
            }
        }
    }else if (count == depth){
        //int i;
        //for (i = 0; i < depth; i++)
        //    printf("%d ", mark[i]);
        //printf("\n");
        if(judge(cur, depth))
            find = 1;
    }
}

int judge(int cur[16][25], int depth)
{
    int i, j, temp[25];
    for (i = 0; i < 25; i++)
        temp[i] = 0;
    for (i = 0; i < types; i++){
        for (j = 0; j < depth; j++)
            temp[i] += cur[mark[j]][i];
    }
    for (i = 0; i < types; i++)
        if (temp[i] < lowerbound[i])
            return 0;
    return 1;
}
