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

    int res;
    res = judge(8, 1, 5, 7);
    printf("%d\n",res);
    
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
