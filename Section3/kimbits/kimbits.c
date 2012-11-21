/*
ID: wangbn11
LANG: C
TASK: kimbits
*/
#include <stdio.h>
/* 
 * 之前理解错题意了！整个的排列还是按大小Order来的。比如11000
 * 在10011后面，但是01111不会在10011前面，因为1的个数要多。
 * 注意输出时，printbits的递归实现方法
 * */

long long str[33][33];  //行代表string长度，列代表1，0的个数
FILE *fout;

void initStr();
void printbits(int, int, long long);

int main()
{
    FILE *fin = fopen("kimbits.in", "r");
    fout = fopen("kimbits.out", "w");
    int length, number, i;
    long long index;
    fscanf(fin, "%d %d %lld\n", &length, &number, &index);
    
    initStr();
    //for (i = 1; i <= 19; i++) {
    printbits(length, number, index-1);
    fprintf(fout, "\n");
    //}
    
    fclose(fin);
    fclose(fout);
}

void initStr()
{
    int i, j;
    for (i = 0; i < 33; i++)
        str[0][i] = 1;
    for (i = 1; i < 33; i++) {
        for (j = 0; j < 33; j++) {
            if (j == 0) {
                str[i][j] = 1;
                continue;
            }
            str[i][j] = str[i-1][j-1] + str[i-1][j];
        }
    }
}

void printbits(int length, int number, long long index)
{
    if (length == 0)
        return ;
    long long count;
    count = str[length-1][number];
    
    if (count <= index) {
        fprintf(fout, "1");
        printbits(length-1, number-1, index-count);
    }else {
        fprintf(fout, "0");
        printbits(length-1, number, index);
    }
}
