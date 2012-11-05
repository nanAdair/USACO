/*
ID: wangbn11
LANG: C
TASK: money
*/
//注意输出的时候也要配合long long
#include <stdio.h>

int main()
{
    FILE *fin = fopen("money.in", "r");
    FILE *fout = fopen("money.out", "w");
    int number, res;
    long long int ways[10001];
    fscanf(fin, "%d %d", &number, &res);
    
    int i, j;
    ways[0] = 1;
    
    for (i = 1; i <= res; i++)
        ways[i] = 0;
    for (i = 0; i < number; i++) {
        int c;
        fscanf(fin, "%d", &c);
        for (j = c; j <= res; j++)
            ways[j] += ways[j-c];
    }
    
    fprintf(fout, "%lld\n", ways[res]);
    fclose(fin);
    fclose(fout);
}
