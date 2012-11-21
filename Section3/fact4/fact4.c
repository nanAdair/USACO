/*
ID: wangbn11
LANG: C
TASK: fact4
*/
#include <stdio.h>
/* 
 * 对10取余数，则数有几个5的因子，就有多少2
 * */

int main()
{
    int number;
    FILE *fin = fopen("fact4.in", "r");
    FILE *fout = fopen("fact4.out", "w");
    fscanf(fin, "%d", &number);
    int digit[5000], time, i;
    time = 0;
    
    for (i = 1; i <= number; i++) {
        digit[i] = i;
        while (digit[i] % 5 == 0) {
            time++;
            digit[i] /= 5;
        }
    }
    for (i = 1; i <= number; i++) {
        while (digit[i] % 2 == 0 && time > 0) {
            time--;
            digit[i] /=2;
        }
    }
    int tail = 1;
    for (i = 1; i <= number; i++) {
        tail = tail * digit[i] % 10;
    }
    
    fprintf(fout, "%d\n", tail);
    fclose(fin);
    fclose(fout);
}
