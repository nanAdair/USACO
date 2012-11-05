/*
ID: wangbn11
LANG: C
TASK: prefix
*/
#include <stdio.h>
#include <string.h>
/* 
 * 字符串比较 c和"." 不可以
 * 记得字符串最后一个位置留给'\0',开大数组
 * */

int main()
{
    FILE *fin = fopen("prefix.in", "r");
    FILE *fout = fopen("prefix.out", "w");
    char list[201][20], str[200001], line[100], c[20];
    int mark[200001], numberPri, numberStr, count, i, j;
    numberPri = numberStr = count = i = 0;
    count = -1;
    
    while (fscanf(fin, "%s", c) && c[0] != '.') {
        for (i = 0; i < strlen(c); i++)
            list[numberPri][i] = c[i];
        list[numberPri++][i] = '\0';
    }
    while (fscanf(fin, "%s", line) > 0) {
        for (i = 0; i < strlen(line); i++) {
            str[numberStr++] = line[i];
        }
    }
    
    //printf("%d %d\n", numberPri, numberStr);
    for (i = 0; i < numberStr; i++)
        mark[i] = 0;
    
    for (i = 0; i < numberStr; i++) {
        for (j = 0; j < numberPri; j++) {
            int length = strlen(list[j]);
            if (i + 1 - length < 0 || (mark[i - length] == 0 && i - length >= 0))
                continue;
            int k;
            for (k = 0; k < length; k++) {
                if (str[i + 1 - length + k] != list[j][k])
                    break;
            }
            if (k == length) {
                mark[i] = 1;
                count = i;
                break;
            }
        }
    }
    
    fprintf(fout, "%d\n", count+1);
    
    fclose(fin);
    fclose(fout);
}
