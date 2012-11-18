/*
ID: wangbn11
LANG: C
TASK: stamps
*/
#include <stdio.h>

int compCount[2000000];

void insertionSort(int *stamps, int number);
int form(int, int *, int, int);

int main()
{
    FILE *fin = fopen("stamps.in", "r");
    FILE *fout = fopen("stamps.out", "w");
    int stamps[51], limit, number;
    
    fscanf(fin, "%d %d", &limit, &number);
    int i;
    for (i = 0; i < number; i++) {
        fscanf(fin, "%d", &stamps[i]);
        compCount[stamps[i]] = 1;
    }
    
    insertionSort(stamps, number);
    
    int digit = 1;
    compCount[0] = 0;
    while (1) {
        if (form(digit, stamps, number, limit))
            digit++;
        else
            break;
    } 
    
    fprintf(fout, "%d\n", digit-1);
    fclose(fin);
    fclose(fout);
}

void insertionSort(int *stamps, int number)
{
    int i, j;
    for (i = 0; i < number; i++) {
        int temp = stamps[i];
        for (j = i-1; j >= 0 && stamps[j] > temp; j--) {
            stamps[j+1] = stamps[j];
        }
        stamps[j+1] = temp;
    }
}

int form(int digit, int *stamp, int number, int limit)
{
    int min, i;
    min = 300;
    for (i = 0; i < number; i++) {
        int last, time;
        last = digit - stamp[i];
        if (last < 0)
            continue;
        time = compCount[last] + 1;
        min = min < time ? min : time;
    }
    
    compCount[digit] = min;
    if (min > limit)
        return 0;
    return 1;
}
