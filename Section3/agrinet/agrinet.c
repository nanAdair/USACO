/*
ID: wangbn11
LANG: C
TASK: agrinet
*/
#include <stdio.h>

#define INF 10000000
//#define USACO
int distance[101][101], sum, in[101], distree[101], number;

int findMin(int *);
int main()
{
#ifdef USACO
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
#endif
    FILE *fin = fopen("agrinet.in", "r");
    FILE *fout = fopen("agrinet.out", "w");
    int i, j, count;
    fscanf(fin, "%d", &number);
    for (i = 0; i < number; i++) {
        for (j = 0; j < number; j++) {
            fscanf(fin, "%d", &distance[i][j]);
        }
        in[i] = 0;
        distree[i] = INF;
    }
    
    sum = count = 0;
    in[0] = 1;
    distree[0] = 0;
    for (i = 0; i < number; i++)
        distree[i] = distance[0][i];
    count++;
    
    while (count < number) {
        int temp, i;
        temp = findMin(distree);
        in[temp] = 1;
        count++;
        sum += distree[temp];
        for (i = 0; i < number; i++) {
            if (distance[temp][i] < distree[i])
                distree[i] = distance[temp][i];
        }
    }
    
    fprintf(fout, "%d\n", sum);
    fclose(fin);
    fclose(fout);
}

int findMin(int *distree)
{
    int i, dist, res;
    dist = INF;
    for (i = 0; i < number; i++) {
        if (distree[i] < dist && in[i] == 0) {
            res = i;
            dist = distree[i];
        }
    }
    return res;
}
