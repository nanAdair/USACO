/*
ID: wangbn11
LANG: C
TASK: humble
*/
#include <stdio.h>
/* 
 * 从1开始往上组合humble数。。。对每个Prime用mark数组记录他已经乘的倍数的下标
 * 每次选择乘出来的最小的数写到humble中去
 * */
#define INF 0x7fffffff

int main()
{
    FILE *fin = fopen("humble.in", "r");
    FILE *fout = fopen("humble.out", "w");
    int K, N;
    fscanf(fin, "%d %d", &K, &N);
    int humble[100002], set[101], mark[101], count, i;
    
    for (i = 0; i < K; i++) {
        fscanf(fin, "%d", set+i);
        mark[i] = 0;
    }
    humble[0] = 1;
    
    count = 0;
    while (count < N) {
        int min = INF;
        for (i = 0; i < K; i++) {
            while (set[i] * humble[mark[i]] <= humble[count])
                mark[i]++;
            min = min < set[i] * humble[mark[i]] ? min : set[i] * humble[mark[i]];
        }
        humble[++count] = min;
    }
    
    fprintf(fout, "%d\n", humble[N]);
    
    fclose(fin);
    fclose(fout);
} 
