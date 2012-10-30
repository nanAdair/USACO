/*
ID: wangbn11
LANG: C
TASK: hamming
*/

#include <stdio.h>

int judge(int *, int count, int num, int distance);

int main()
{
    FILE *fin = fopen("hamming.in", "r");
    FILE *fout = fopen("hamming.out", "w");
    int i, count, limit, number, length, distance, store[256];
    fscanf(fin, "%d %d %d", &number, &length, &distance);
    limit = (1 << (length+1));
    count = 0;
    
    for (i = 0; i <limit; i++){
        if (i == 0)
            store[count++] = 0;
        if (judge(store, count, i, distance)){
            store[count++] = i;
        }
        if (count == number)
            break;
    }
    
    for (i = 0; i < number-1; i++){
        char c = (i+1)%10 == 0 ? '\n' : ' ';
        fprintf(fout, "%d%c", store[i], c);
    }
    fprintf(fout, "%d\n", store[number-1]);
    
    fclose(fin);
    fclose(fout);
}

int judge(int *store, int count, int num, int distance)
{
    int i;
    for (i = 0; i < count; i++) {
        if(!test(store[i], num, distance))
            return 0;
    }
    return 1;
}

int test(int a, int b, int distance)
{
    int temp, count;
    temp = a ^ b;
    count = 0;
    while (temp != 0) {
        if(temp % 2 == 1)
            count++;
        temp /= 2;
    }
    if(count >= distance)
        return 1;
    else
        return 0;
}
