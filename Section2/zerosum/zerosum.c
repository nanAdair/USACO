/*
ID: wangbn11
LANG: C
TASK: zerosum
*/
//注意全局变量使用的时候，如果在函数中地方用错不会报错，还是少用全局变量
#include <stdio.h>

char ari[] = {' ', '+', '-'};
char mark[10];
FILE *fin, *fout;

int judge(int);
void print(int);
void dfs(int, int);

int main()
{
    fin = fopen("zerosum.in", "r");
    fout = fopen("zerosum.out", "w");
    int number;
    fscanf(fin, "%d", &number);
   
    dfs(0, number-1);
    
    fclose(fin);
    fclose(fout);
}

void dfs(int depth, int limit)
{
    if (depth < limit) {
        int i;
        for (i = 0; i < 3; i++) {
            mark[depth] = ari[i];
            dfs(depth+1, limit);
        }
    }else if (depth == limit) {
        if (judge(depth))
            print(depth);
    }
}

int judge(int number)
{
    int i, count, sum, j;
    int digit[10];
    count = 0;
    j = 1;
    
    digit[0] = 1;
    for (i = 1; i <= number; i++) {
        if (mark[i-1] != ' ') {
            digit[++count] = i+1;
        }else {
            digit[count] = digit[count]*10 + i + 1;
        }
    }
    
    sum = digit[0];
    for (i = 0; i < number; i++) {
        if (mark[i] == '+') {
            sum += digit[j++];
        }else if (mark[i] == '-') {
            sum -= digit[j++];
        }
    }
    
    int c = (sum == 0) ? 1 : 0;
    return c;
}

void print(int number)
{
    int i;
    for (i = 0; i < number; i++) {
        fprintf(fout, "%d%c", i+1, mark[i]);
    }
    fprintf(fout, "%d\n", number+1);
}
