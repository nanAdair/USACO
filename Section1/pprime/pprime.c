/*
ID: wangbn11
LANG: C
TASK: pprime
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int);
void create(int length, int index);

int num[10];
int begin, end;
FILE *fout;

int main()
{
    FILE *fin = fopen("pprime.in", "r");
    fout = fopen("pprime.out", "w");
    fscanf(fin, "%d %d", &begin, &end);
    
    int minleng, maxleng;
    minleng = maxleng = 0;
    int tempBegin, tempEnd;
    tempBegin = begin;
    tempEnd = end;
    while(tempBegin){
        minleng++;
        tempBegin /= 10;
    }
    while(tempEnd){
        maxleng++;
        tempEnd /= 10;
    }
    minleng = minleng % 2 == 0 ? minleng+1 : minleng;
    maxleng = maxleng % 2 == 0 ? maxleng-1 : maxleng;
    
    int i;
    for(i = minleng; i <= maxleng; ){
        create(i, 1);
        if(i == 1 || i == 2)
            i++;
        else
            i += 2;
    }
    
    fclose(fin);
    fclose(fout);
}

void create(int length, int index)
{
    if(index <= (length+1)/2){
        int i;
        for(i = 0; i <10; i++){
            if(index == 1 && i % 2 == 0)
                continue;
            num[index] = num[length-index+1] = i;
            create(length, index+1);
        }
    }
    else{
        int sum = 0;
        int i;
        for(i = 1; i <= length; i++)
            sum = sum * 10 + num[i];
        if(isPrime(sum) && sum >= begin && sum <= end)
            fprintf(fout, "%d\n", sum);
    }
}
  
int isPrime(int a)
{
    int temp = sqrt(a);
    int i;
    for(i = 2; i <=temp; i++)
        if(a % i == 0)
            return 0;
    return 1;
}

