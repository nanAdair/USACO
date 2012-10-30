/*
ID: wangbn11
LANG: C
TASK: milk3
*/
#include <stdio.h>

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

int flag[21][21] = {0};
int volc[21] = {0};
int maxa, maxb, maxc;

void dfs(int, int, int);

int main()
{
    FILE *fin = fopen("milk3.in", "r");
    FILE *fout = fopen("milk3.out", "w");
    fscanf(fin, "%d %d %d", &maxa, &maxb, &maxc);
    
    dfs(0, 0, maxc);
    int i;
    for(i = 0; i < maxc; i++)
        if(volc[i] == 1)
            fprintf(fout, "%d ", i);
    fprintf(fout, "%d\n", maxc);
    
    fclose(fin);
    fclose(fout);
}

void dfs(int a, int b, int c)
{
    if(flag[a][b] == 1)
        return ;
    flag[a][b] = 1;
    if(a == 0)
        volc[c] = 1;
    
    if(a > 0 && b < maxb)
        dfs(max(0, a-(maxb-b)), min(a+b, maxb), c);
    if(a > 0 && c < maxc)
        dfs(max(0, a-(maxc-c)), b, min(a+c, maxc));
    if(b > 0 && a < maxa)
        dfs(min(a+b, maxa), max(0, b-(maxa-a)), c);
    if(b > 0 && c < maxc)
        dfs(a, max(0, b-(maxc-c)), min(b+c, maxc));
    if(c > 0 && a < maxa)
        dfs(min(a+c, maxa), b, max(0, c-(maxa-a)));
    if(c > 0 && b < maxb)
        dfs(a, min(b+c, maxb), max(0, c-(maxb-b)));
}
