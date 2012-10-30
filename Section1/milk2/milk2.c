/*
ID: wangbn11
LANG: C
TASK: milk2
*/
#include <stdio.h>

struct time{
    int start;
    int end;
};

void insertionSort(struct time *, int);

int main()
{
    FILE *fin = fopen("milk2.in", "r");
    FILE *fout = fopen("milk2.out", "w");
    
    struct time cow[5001];
    int number;
    fscanf(fin, "%d", &number);
    
    int i;
    for(i = 0; i < number; i++){
        fscanf(fin, "%d %d", &cow[i].start, &cow[i].end);
    }
    insertionSort(cow, number);
    
    int startTime = cow[0].start;
    int endTime = cow[0].end;
    
    int con = endTime - startTime;
    int idle = 0;
    for(i = 0; i < number - 1; i++){
        if(endTime >= cow[i + 1].start){
            endTime = endTime < cow[i+1].end ? cow[i + 1].end : endTime;
        }
        else{
            idle = idle < cow[i + 1].start - endTime ? (cow[i + 1].start - endTime) : idle;
            con = con < endTime - startTime ? (endTime - startTime) : con;
            startTime = cow[i + 1].start;
            endTime = cow[i + 1].end;
        }
    }
    con = con < cow[i].end - cow[i].start ? (cow[i].end - cow[i].start) : con;
    
    fprintf(fout, "%d %d\n", con, idle);
    
    fclose(fin);
    fclose(fout);
}

void insertionSort(struct time *cow, int number)
{
    int i, j;
    for(i = 0; i < number; i++){
        int start = cow[i].start;
        int end = cow[i].end;
        for(j = i - 1; j >= 0 && cow[j].start > start; j--){
            cow[j + 1].start = cow[j].start;
            cow[j + 1].end = cow[j].end;
        }
        cow[j+1].start = start;
        cow[j+1].end = end;
    }
}
