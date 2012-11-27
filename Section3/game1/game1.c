/*
ID: wangbn11
LANG: C
TASK: game1
*/
/*
 * =====================================================================================
 *
 *       Filename:  game1.c
 *
 *    Description:  dp  注意两个范围的二维数组，可以用偏移量作为一个循环值
 *
 *        Version:  1.0
 *        Created:  11/26/2012 02:29:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wangbn (nan adair), wangbn15@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b);

int main()
{
    FILE *fin = fopen("game1.in", "r");
    FILE *fout = fopen("game1.out", "w");
    int number, i, j;
    fscanf(fin, "%d", &number);
    int sum[101][101], f[101][101], digit[101];
    for (i = 0; i < number; i++)
        fscanf(fin, "%d", &digit[i]);
    
    for (i = 0; i < number; i++) {
        for (j = i; j < number; j++) {
            if (i == j)
                sum[i][j] = digit[i];
            else {
                sum[i][j] = sum[i][j-1] + digit[j];
            }
            /*printf("%d %d %d\n", i, j, sum[i][j]);*/
        }
    }
    
    for (i = 0; i < number; i++)
        f[i][i] = digit[i];
    for (i = 1; i < number; i++) {
        for (j = 0; i + j < number; j++) {
            f[j][i+j] = sum[j][i+j] - min(f[j+1][i+j], f[j][i+j-1]);
        }
    }
    
    fprintf(fout, "%d %d\n", f[0][number-1], sum[0][number-1]-f[0][number-1]);
    
    fclose(fin);
    fclose(fout);
}

int min(int a, int b)
{
    return a > b ? b : a;
}
