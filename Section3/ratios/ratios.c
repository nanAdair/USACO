/*
ID: wangbn11
LANG: C
TASK: ratios
*/
#include <stdio.h>

int inter[3][3], goal[3];
int main()
{
    int i, j, k, l, found, bigger;
    FILE *fin = fopen("ratios.in", "r");
    FILE *fout = fopen("ratios.out", "w");
    fscanf(fin, "%d %d %d", goal, goal+1, goal+2);
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            fscanf(fin, "%d", &inter[i][j]);
    
    found = bigger = 0;
    for (i = 1; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            for (k = 0; k < 100; k++) {
                for (l = 0; l < 100; l++) {
                    int res;
                    res = judge(j, k, l, i);
                    if (res == 1)
                        found = 1;
                    if (found == 1)
                        break;
                }
                if (found == 1)
                    break;
            }
            if (found == 1)
                break;
        }
        if (found == 1)
            break;
    }
    
    if (found == 1)
        fprintf(fout, "%d %d %d %d\n", j, k, l, i);
    else
        fprintf(fout, "NONE\n");
    
    fclose(fin);
    fclose(fout);
}

int judge(int j, int k, int l, int i)
{
    int m, n, found, bigger, small;
    found = bigger = small = 0;
    for (m = 0; m < 3; m++) {
        int left, right;
        left = j * inter[0][m] + k * inter[1][m] + l * inter[2][m];
        right = i * goal[m];
        if (left > right) {
            bigger = 1;
        }else if (left < right) {
            small = 1;
        }
    }
    if (bigger == 0 && small == 0)
        found = 1;
    if (found == 1)
        return 1;
    if (bigger == 1)
        return 2;
    return 0;
}
