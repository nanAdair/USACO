/*
ID: wangbn11
LANG: C
TASK: barn1
*/
#include <stdio.h>

void insertionSort(int *, int);
int sumOfIntern(int *, int);

int main()
{
    FILE *fin = fopen("barn1.in", "r");
    FILE *fout = fopen("barn1.out", "w");
    int boards, stalls, cows, i;
    fscanf(fin, "%d %d %d", &boards, &stalls, &cows);
    
    int numberOfStall[201];
    int internal[201];
    
    if(boards < cows){
    for(i = 0; i < cows; i++)
        fscanf(fin, "%d", &numberOfStall[i]);
    insertionSort(numberOfStall, cows);
    int total;
    total = numberOfStall[0] - numberOfStall[cows - 1] + 1;
    
    for(i = 0; i < cows - 1; i++)
        internal[i] = numberOfStall[i] - numberOfStall[i + 1] - 1;
    
    insertionSort(internal, cows - 1);
    
    total -= sumOfIntern(internal, boards - 1);
    fprintf(fout, "%d\n", total);
    }
    else{
        fprintf(fout, "%d\n", cows);
    }
    
    fclose(fin);
    fclose(fout);
}

void insertionSort(int *internal, int number)
{
    int i, j;
    for(i = 0; i < number; i++){
        int temp;
        temp = internal[i];
        for(j = i - 1; j >= 0 && internal[j] < temp; j--){
            internal[j + 1] = internal[j];
        }
        internal[j + 1] = temp;
    }
}

int sumOfIntern(int * internal, int number)
{
   int i, sum;
   sum = 0;
   for(i = 0; i < number; i++)
       sum += internal[i];
   return sum;
}
