/*
ID: wangbn11
LANG: C
TASK: runround
*/
#include <stdio.h>

int judge(unsigned long, int [10], int *, int);
void manage(unsigned long, int [10], int *, int *);
void reverse(int *, int);
int unique(unsigned long);

int main()
{
    FILE *fin = fopen("runround.in", "r");
    FILE *fout = fopen("runround.out", "w");
    unsigned long number;
    fscanf(fin, "%ld", &number);
    int find = 0;
    
        number = 140;
        if (unique(number)) {
            int i, mark[10], digit[11], length;
            manage(number, mark, digit, &length);
            find = judge(number, mark, digit, length);
        }
        printf("%d\n", find);
    
    fclose(fin);
    fclose(fout);
}

int unique(unsigned long number)
{
    int i, digit[10];
    for (i = 0; i < 10; i++)
        digit[i] = 0;
    
    while (number) {
        int temp;
        temp = number % 10;
        digit[temp]++;
        number /= 10;
    }
    
    for (i = 0; i < 10; i++) {
        if (digit[i] > 1)
            return 0;
    }
    return 1;
}

void manage(unsigned long number, int mark[10], int *digit, int *length)
{
    int i, j;
    for (i = 0; i < 10; i++) 
        mark[i] = 0;
    i = 0;
    while (number) {
        int temp;
        temp = number % 10;
        mark[temp]++;
        digit[i++] = temp;
        number /= 10;
    }
    reverse(digit, i);
    *length = i;
}

void reverse(int *digit, int limit)
{
    int i;
    for (i = 0; i < limit/2; i++) {
        int temp = digit[i];
        digit[i] = digit[limit - 1 - i];
        digit[limit - 1 - i] = temp;
    }
}

int judge(unsigned long number, int mark[10], int *digit, int length)
{
    int index, step, i;
    index = 0;
    for (i = 0; i < length; i++) {
        if (mark[digit[index]] != 0) {
            mark[digit[index]]--;
            step = digit[index];
            index = (index + step) % length;
        }else
            return 0;
    }
    printf("test\n");
    printf("%d\n", index);
    if (index  == 0)
        return 1;
    else
        return 0;
}
