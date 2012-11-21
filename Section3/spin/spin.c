/*
ID: wangbn11
LANG: C
TASK: spin
*/
#include <stdio.h>
#include <string.h>
/*
 * 简单模拟过程
 * 用一个degree数组中每个度数的一位来表示轮子的缺口是否到这里
 * */

int degree[360], speed[5], postion[5], wedgeStart[5][5], wedgeLen[5][5];

void markDegree(int);

int main()
{
    FILE *fin = fopen("spin.in", "r");
    FILE *fout = fopen("spin.out", "w");
    int i, wCount, j, found, time;
    for (i= 0; i < 5; i++) {
        fscanf(fin, "%d %d", speed+i, &wCount);
        for (j = 0; j < wCount; j++) {
            fscanf(fin, "%d %d", &wedgeStart[i][j], &wedgeLen[i][j]);
        }
        for (; j < 5; j++) {
            wedgeLen[i][j] = -1;
        }
        postion[i] = 0;
    }
    
    time = found = 0;
    while (time < 360) {
        memset(degree, 0, sizeof(degree));
        
        for (i = 0; i < 5; i++)
            markDegree(i);
        for (i = 0; i < 360; i++) {
            if (degree[i] == 31)
                found = 1;
        }
        if (found)
            break;
        
        for (i = 0; i < 5; i++) {
            postion[i] = (postion[i] + speed[i]) % 360;
        }
        time++;
    }
    
    if (found)
        fprintf(fout, "%d\n", time);
    else
        fprintf(fout, "none\n");
    
    fclose(fin);
    fclose(fout);
}

void markDegree(int w)
{
    int i;
    for (i = 0; i < 5; i++) {
        int j, length;
        length = wedgeLen[w][i];
        if (length == -1)
            break;
        for (j = 0; j <= length; j++) {
            int pos;
            pos = (postion[w] + wedgeStart[w][i] + j) % 360;
            degree[pos] |= (1 << w);
        }
    }
}
