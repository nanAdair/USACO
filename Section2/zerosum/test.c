#include <stdio.h>

char ari[] = {' ', '+', '-'};
char mark[] = {'+', '-', '+', '-', '-', '+'};
FILE *fin, *fout;

int judge(int);
void print(int);
void dfs(int, int);

int main()
{
   int number = 6;
   int res = judge(6);
   printf("%d\n", res);
}

int judge(int number)
{
    int i, count, sum, j;
    int digit[10];
    count = 0;
    
    digit[0] = 1;
    for (i = 1; i <= number; i++) {
        printf("%d %c %d\n", i, mark[i-1], count);
        if (mark[i-1] != ' ') {
            digit[++count] = i+1;
        }else {
            digit[count] = digit[count]*10 + i + 1;
        }
    }
    
    sum = digit[0];
    j = 1;
    for (i = 0; i < number; i++) {
        printf("sum now: %c %d %d\n", mark[i], j, sum);
        if (mark[i] == '+') {
            sum += digit[j++];
        }else if (mark[i] == '-') {
            sum -= digit[j++];
        }
    }
    
    for(i = 0; i <= count; i++)
        printf("%d ", digit[i]);
    printf("\n");
    printf("%d\n", sum);
    
    int c = (sum == 0) ? 1 : 0;
    return c;
}

