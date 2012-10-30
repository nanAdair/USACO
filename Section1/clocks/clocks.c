/*
ID: wangbn11
LANG: C
TASK: clocks
*/
#include <stdio.h>
#include <string.h>
/* 注意在此题中1-9谁先谁后都是一样的
 * 可以用DFS来整体记录
 * */

int move[10] = {0, 4310, 210, 5421, 630, 75431, 852, 7643, 876, 8754};
int res[27];
int number = 28;

int check(int *);
void rotate(int *, int d);
void change(int *, int depth);
void print(FILE*, int *);
void comp(int *res, int *proc, int number);

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
    
    change(clock, 1);
    print(fout, res);
    
    fclose(fin);
    fclose(fout);
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
        for(i = 0; i < 4; i++){
            mark[depth] = i;
            change(clock, depth+1);
        }
    }
    else if(depth == 10){
        int temp[9], proc[27];
        int i, j, walk;
        walk = 0;
        for(i = 0; i < 9; i++)
            temp[i] = clock[i];
        
        for(i = 1; i < 10; i++){
            for(j = 0; j < mark[i]; j++){
                rotate(temp, i);
                proc[walk++] = i;
            }
        }
        if(check(temp)){
            if(walk < number){
                number = walk;
                for(i = 0; i < walk; i++)
                    res[i] = proc[i];
            }
            else if(walk == number){
                comp(res, proc, number);
            }
        }
    }
}

void comp(int *res, int *walk, int number)
{
    int i;
    for(i = 0; i < number; i++){
        if(walk[i] < res[i]);
        break;
    }
    if(i == number){
        for(i = 0; i < number; i++)
            res[i] = walk[i];
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

void print(FILE *fout, int *res)
{
    int i;
    for(i = 0; i < number; i++){
        if(i != number -1)
            fprintf(fout, "%d ", res[i]);
        else
            fprintf(fout, "%d\n", res[i]);
    }
}
