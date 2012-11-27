/*
ID: wangbn11
LANG: C
TASK: range
*/
/*
 * =====================================================================================
 *
 *       Filename:  range.c
 *
 *    Description:  dp -- caculate the max length one square can make; do from the
 *    right corner.
 *
 *        Version:  1.0
 *        Created:  11/26/2012 01:48:58 PM
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

int area[251][251], length[251][251];

int min(int a, int b, int c);
int main()
{
    FILE *fin = fopen("range.in", "r");
    FILE *fout = fopen("range.out", "w");
    int i, j, number, count[251];
    fscanf(fin, "%d", &number);
    for (i = 0; i < number; i++) {
        char buffer[252];
        fscanf(fin, "%s", buffer);
        for (j = 0; j < number; j++) {
            if (buffer[j] == '0')
                area[i][j] = 0;
            else 
                area[i][j] = 1;
        }
    }
    
    for (i = 0; i <= 251; i++)
        count[i] = 0;
    for (i = 0; i < number; i++)
        length[number-1][i] = length[i][number-1] = 1;
    
    for (i = number-2; i >= 0; i--) {
        for (j = number-2; j >= 0; j--) {
            if (area[i+1][j] == 1 && area[i][j+1] == 1 && area[i+1][j+1] == 1 && area[i][j] == 1)
                length[i][j] = min(length[i+1][j], length[i][j+1], length[i+1][j+1]) + 1;
            else
                length[i][j] = 1;
            int k;
            for (k = 2; k <= length[i][j]; k++)
                count[k]++;
        }
    }
    
    i = 2;
    while (count[i] > 0) {
        fprintf(fout, "%d %d\n", i, count[i]);
        i++;
    }
    
    fclose(fin);
    fclose(fout);
} 

int min(int a, int b, int c)
{
    int d;
    d = a > b ? b : a;
    d = d > c ? c : d;
    return d;
}
