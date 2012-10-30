/*
ID: wangbn11
LANG: C
TASK: sort3
*/
#include <stdio.h>

int main()
{
    FILE *fin = fopen("sort3.in", "r");
    FILE *fout = fopen("sort3.out", "w");
    int number[1001];
    int count, i;
    fscanf(fin, "%d", &count);
    int mount[4] = {0,0,0,0};
    for(i = 0; i < count; i++){
        fscanf(fin, "%d", number+i);
        mount[number[i]]++;
    }
    int temp, temp2;
    temp = temp2 = 0;
    int change = 0;
    for(i = 0; i < mount[1]; i++){
        if(number[i] != 1)
            change++;
        if(number[i] == 3)
            temp++;
    }
    for(i = count-1; i > count-1-mount[3]; i--){
        if(number[i] != 3)
            change++;
        if(number[i] == 1)
            temp2++;
    }
    int xxx = temp < temp2 ? temp : temp2;
    fprintf(fout, "%d\n", change-xxx);
    
    fclose(fin);
    fclose(fout);
}
