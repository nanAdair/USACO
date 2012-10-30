#include <stdio.h>
#include <string.h>

int move[10] = {0, 4310, 210, 5421, 630, 75431, 852, 7643, 876, 8754};
long long int minWalk = 999999999;

int check(int *);
void rotate(int *, int d);
void change(int *, int depth);
void print(FILE*, int);

int main()
{
    FILE *fin = fopen("clocks.in", "r");
    FILE *fout = fopen("clocks.out", "w");
    int clock[9];
    int i;
    for(i = 0; i < 9; i++){
        fscanf(fin, "%d", &clock[i]);
        clock[i] = clock[i] / 3 % 4;
    }
    
    rotate(clock, 4);
    rotate(clock, 5);
    rotate(clock, 8);
    rotate(clock, 9);
    printf("sss: %d\n", check(clock));
    
}

int check(int *clock)
{
    int i;
    for(i = 0; i < 9; i++){
        if(clock[i] != 0)
            return 0;
    }
    return 1;
}

int mark[10] = {0};
void change(int *clock, int depth)
{
    if(depth < 10){
        int i;
        for(i = 0; i < 4; i++)
            mark[depth] = i;
        change(clock, depth+1);
    }
    else if(depth == 10){
        int temp[9];
        int i, j, walk;
        walk = 0;
        for(i = 0; i < 9; i++)
            temp[i] = clock[i];
        
        for(i = 1; i < 10; i++){
            for(j = 0; j < mark[i]; j++){
                rotate(temp, i);
                walk = walk * 10 + i;
            }
        }
        if(check(temp)){
            minWalk = walk > minWalk ? minWalk : walk;
            printf("xxx: %d\n", minWalk);
        }
    }
}

void rotate(int *clock, int temp)
{
    int choice = move[temp];
    do{
        int i;
        i = choice % 10;
        clock[i] = (clock[i] + 1) % 4;
    }while(choice /= 10);
}

void print(FILE *fout, int res)
{
    int temp[36];
    int i, j;
    i = 0;
    do{
        temp[i++] = res % 10;
    }while(res /= 10);
    
    for(j = i - 1; j >= 0; j--){
        if(j != 0)
            fprintf(fout, "%d ", temp[j]);
        else
            fprintf(fout, "%d\n", temp[j]);
    }
}
