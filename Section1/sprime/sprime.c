/*
ID: wangbn11
LANG: C
TASK: sprime
*/
#include <stdio.h>
#include <math.h>

int isPrime(int);
int check(int);
void makePrime(int);
int make[9][2];
int number[1000000];

int main()
{
    int i;
    FILE *fin = fopen("sprime.in", "r");
    FILE *fout = fopen("sprime.out", "w");
    int length;
    fscanf(fin, "%d", &length);
    
    int begin, end, mul;
    begin = 2;
    end = 8;
    mul = 1;
    for(i = 1; i <= length; i++)
        makePrime(i);
    
    for(i = make[length][0]; i <= make[length][1]; i++)
        fprintf(fout, "%d\n", number[i]);
    
    fclose(fin);
    fclose(fout);
}

void makePrime(int leng)
{
    if(leng == 1){
        int i, count;
        count = 0;
        make[1][0] = 0;
        for(i = 2; i < 10; i++)
            if(isPrime(i))
                number[count++] = i;
        make[1][1] = count-1;
    }
    else{
        int i, begin, count;
        begin = make[leng-1][1];
        count = make[leng][0] = begin+1;
        for(i = make[leng-1][0]; i <= make[leng-1][1]; i++){
            int digit, j;
            digit = number[i];
            for(j = 1; j < 10; j+=2){
                int temp;
                temp = digit*10 + j;
                if(isPrime(temp))
                    number[count++] = temp;
            }
        }
        make[leng][1] = count-1;
    }
    
}

int isPrime(int a)
{
    int i, j;
    j = sqrt(a);
    for(i = 2; i <= j; i++){
        if(a % i == 0)
            return 0;
    }
    return 1;
}

