/*
ID: wangbn11
LANG: C
TASK: fracdec
*/
#include <stdio.h>

#define NUM 100001
#define USACO


int main()
{
#ifdef USACO
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
#endif
    int N, D;
    scanf("%d %d", &N, &D);
    
    int decimal[NUM], integer, countD, visited[NUM], i, begin, lengthInt;
    countD = lengthInt = 0;
    begin = -1;

    integer = N / D;
    N = N % D;
    int fakeinteger = integer;
    
    while (fakeinteger != 0) {
        lengthInt++;
        fakeinteger /= 10;
    }
    lengthInt = lengthInt == 0 ? 1 : lengthInt;

    for (i = 0; i < NUM; i++)
        visited[i] = -1;
    while (N != 0) {
        int temp;
        visited[N] = countD;
        temp = N * 10 / D;
        decimal[countD++] = temp;
        N = N * 10 - temp * D;
        if (visited[N] != -1) {
            begin = visited[N];
            break;
        }
    }
    
    printf("%d.", integer);
    lengthInt++;
    if (countD == 0) {
        printf("0\n");
        return 0;
    }
    if (begin != -1) {
       for (i = 0; i < begin; i++) {
            printf("%d", decimal[i]);
            lengthInt++;
            if (lengthInt % 76 == 0)
                printf("\n");
       }
        printf("(");
        lengthInt++;
        if (lengthInt % 76 == 0)
            printf("\n");
        for (i = begin; i < countD; i++) {
            printf("%d", decimal[i]);
            lengthInt++;
            if (lengthInt % 76 == 0)
                printf("\n");
        }
        printf(")\n");
    }else {
        for (i = 0; i < countD; i++) {
            printf("%d", decimal[i]);
            lengthInt++;
            if (lengthInt % 76 == 0)
                printf("\n");
        }
        printf("\n");
    }
    return 0;
}
