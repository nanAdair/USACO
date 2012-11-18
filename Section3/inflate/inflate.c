/*
ID: wangbn11
LANG: C
TASK: inflate
*/
#include <stdio.h>

int main()
{
    FILE *fin = fopen("inflate.in", "r");
    FILE *fout = fopen("inflate.out", "w");
    int limit, number;
    fscanf(fin, "%d %d", &limit, &number);
    int points[1000000], i, j;
    
    for (i = 0; i < number; i++) {
        int single, minut;
        fscanf(fin, "%d %d", &single, &minut);
        for (j = 0; j <= limit; j++) {
            if (points[j + minut] < points[j] + single)
                points[j + minut] = points[j] + single;
        }
    }
    
    int max = 0;
    for (i = 0; i <= limit; i++) {
        max = max < points[i] ? points[i] : max;
    }
    
    fprintf(fout, "%d\n", max);
    
    fclose(fin);
    fclose(fout);
}
