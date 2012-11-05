/*
ID: wangbn11
LANG: C
TASK: subset
*/
/*
 * 动态规划，前i个数的和是j，
 * 可以j是否包含i来计算，这种情况出现的种数
 * */
#include <stdio.h>

unsigned long count;
void dfs(int, int, int);

int main()
{
    FILE *fin = fopen("subset.in", "r");
    FILE *fout = fopen("subset.out", "w");
    int number, sum, i, j;
    fscanf(fin, "%d", &number);
    count = 0;
    sum = (1 + number) * number / 2;
    if (sum % 2 == 0) {
        sum /= 2;
        unsigned long mark[40][391];
        mark[1][1] = 1;
        mark[1][0] = 1;
    
        for (i = 2; i <= number; i++) {
            for (j = 0; j <= sum; j++) {
                if (i <= j)
                    mark[i][j] = mark[i-1][j] + mark[i-1][j-i];
                else if (i > j)
                    mark[i][j] = mark[i-1][j];
            }
        }
        count = mark[number][sum];
        fprintf(fout, "%ld\n", count/2);
    }else 
        fprintf(fout, "0\n");
    
    fclose(fin);
    fclose(fout);
}

