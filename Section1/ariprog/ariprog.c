/*
ID: wangbn11
LANG: C
TASK: ariprog
*/
#include <stdio.h>

struct arr{
    int a;
    int b;
};

struct arr res[10000];

void insertionSort(int *, int);
void insertion(struct arr *, int);
void mark(struct arr *, int, int, int);
int check(int *, int, int, int);
void out(FILE *, struct arr *, int);

int main()
{
    FILE *fin = fopen("ariprog.in", "r");
    FILE *fout = fopen("ariprog.out", "w");
    int length, upper;
    fscanf(fin, "%d\n%d", &length, &upper);
    
    int number[1000000];
    int flag[1000000] = {0};
    int i, j;
    int sum;
    sum = 0;
    for(i = 0; i <= upper; i++){
        for(j = i; j <= upper; j++)
            number[sum++] = i * i + j * j;
    }
    insertionSort(number, sum);
    int k = 0;
    for(i = 0; i < sum; i++){
        flag[number[i]] = 1;
        if(i != 0 && number[i] != number[i-1])
            number[k++] = number[i];
        else if(i == 0)
            number[k++] = number[0];
    }
    sum = k;
    
    int sumRes = 0;
    for(i = 0; i < sum; i++){
        for(j = i + 1; j < sum; j++){
            int a, b;
            a = number[i];
            b = number[j] - number[i];
            
            if(check(flag, a, b, length)){
                mark(res, a, b, sumRes);
                sumRes += 1;
            }
        }
    }
    
    if(sumRes == 0)
        fprintf(fout, "NONE\n");
    else{
        insertion(res, sumRes);
        out(fout, res, sumRes);
    }
    
    fclose(fin);
    fclose(fout);
}

int check(int *flag, int a, int b, int length)
{
    int i;
    for(i = 0; i < length; i++){
        int temp;
        temp = a + b * i;
        if(flag[temp] != 1)
            return 0;
    }
    return 1;
}

void mark(struct arr *res, int a, int b, int sumRes)
{
    res[sumRes].a = a;
    res[sumRes].b = b;
}

void out(FILE *fout, struct arr *res, int sumRes)
{
    int i;
    for(i = 0; i < sumRes; i++)
        fprintf(fout, "%d %d\n", res[i].a, res[i].b);
}

void insertionSort(int *number, int leng)
{
    int i, j;
    for(i = 0; i < leng; i++){
        int temp = number[i];
        for(j = i-1; j >= 0 && number[j] > temp; j--)
            number[j+1] = number[j];
        number[j+1] = temp;
    }
}

void insertion(struct arr *res, int leng)
{
    int i, j;
    for(i = 0; i < leng; i++){
        int a, b;
        a = res[i].a;
        b = res[i].b;
        for(j = i-1; j >=0 && res[j].b > b; j--){
            res[j+1].a = res[j].a;
            res[j+1].b = res[j].b;
        }
        res[j+1].a = a;
        res[j+1].b = b;
    }
}
