/*
ID: wangbn11
LANG: C
TASK: lamps
*/
#include <stdio.h>

int number, countOn, countOff;
void manage(int lamp[170][1010], int *);
int judge(int, int lamp[170][1010], int *, int *);

int main()
{
    int i, j, k, l, c, lamp[170][1010], button[4], cur[101], on[101], off[101];
    FILE *fin = fopen("lamps.in", "r");
    FILE *fout = fopen("lamps.out", "w");
    fscanf(fin, "%d", &number);
    fscanf(fin, "%d", &c);
    if (c > 4 && c % 2 == 0)
        c = 4;
    else if(c > 4 && c % 2 == 1)
        c = 3;
    countOn = countOff = 0;
    
    int temp;
    while (fscanf(fin, "%d", &temp) && temp != -1) 
        on[countOn++] = temp;
    while (fscanf(fin, "%d", &temp) && temp != -1)
        off[countOff++] = temp;
    for (i = 1; i <= number; i++)
        cur[i] = 1;
    
    for (i = 0; i < 4; i++) 
        button[i] = 0;
    manage(lamp, button);
    for (i = 0; i < 4; i++) {
        button[i] = 1;
        manage(lamp, button);
        button[i] = 0;
    }
    
    for (i = 0; i < 4; i++) {
        button[i] = 1;
        for (j = i+1; j < 4; j++) {
            button[j] = 1;
            manage(lamp, button);
            button[j] = 0;
        }
        button[i] = 0;
    }
    
    for (i = 0; i < 4; i++) {
        button[i] = 1;
        for (j = i+1; j < 4; j++) {
            button[j] = 1;
            for (k = j+1; k < 4; k++) {
                button[k] = 1;
                manage(lamp, button);
                button[k] = 0;
            }
            button[j] = 0;
        }
        button[i] = 0;
    } 
    
    for (i = 0; i < 4; i++)
        button[i] = 1;
    manage(lamp, button);
    
    if (c == 0) {
        if (judge(0, lamp, on, off)) {
            int i;
            for (i = 1; i <= number; i++)
                fprintf(fout, "%d", cur[i]);
            fprintf(fout, "\n");
        } else
            fprintf(fout, "IMPOSSIBLE\n");
    }
    if (c == 1) {
        int index[4] = {1, 2, 4, 8};
        int i, j;
        for (i = 0; i < 4; i++) {
            if (judge(index[i], lamp, on, off)) {
                for (j = 1; j <= number; j++)
                    fprintf(fout, "%d", lamp[index[i]][j]);
                fprintf(fout, "\n");
            }
        }
    }
    if (c == 2) {
        int index[7] = {0, 3, 5, 6, 9, 10, 12};
        int i, j;
        for (i = 0; i < 7; i++) {
            if (judge(index[i], lamp, on, off)) {
                for (j = 1; j <= number; j++)
                    fprintf(fout, "%d", lamp[index[i]][j]);
                fprintf(fout, "\n");
            }
        }
    }
    if (c == 3) {
        int index[8] = {1, 2, 4, 7, 8, 11, 13, 14};
        int i, j;
        for (i = 0; i < 8; i++) {
            if (judge(index[i], lamp, on, off)) {
                for (j = 1; j <= number; j++)
                    fprintf(fout, "%d", lamp[index[i]][j]);
                fprintf(fout, "\n");
            }
        }
    }
    if (c == 4) {
        int index[8] = {0, 3, 5, 6, 9, 10, 12, 15};
        int i, j;
        for (i = 0; i < 8; i++) {
            if (judge(index[i], lamp, on, off)) {
                for (j = 1; j <= number; j++)
                    fprintf(fout, "%d", lamp[index[i]][j]);
                fprintf(fout, "\n");
            }
        }
    }
}

void manage(int lamp[170][1010], int *button)
{
    int index = 0;
    int i, side;
    side = 1;
    for (i = 0; i < 4; i++) {
        if (i != 0)
            side *= 2;
        index += button[i] * side;
    }
    
    for (i = 1; i <= number; i++) 
        lamp[index][i] = 1;
    if (button[0] == 1) {
        for (i = 1; i <= number; i++)
            lamp[index][i] ^= 1;
    }
    if(button[1] == 1) {
        for (i = 1; i <= number; i+=2)
            lamp[index][i] ^= 1;
    }
    if(button[2] == 1) {
        for (i = 2; i <= number; i+=2)
            lamp[index][i] ^= 1;
    }
    if(button[3] == 1) {
        for (i = 1; i <= number; i+=3) 
            lamp[index][i] ^= 1;
    }
}

int judge(int index, int lamp[170][1010], int *on, int *off)
{
    int i;
    for (i = 0; i < countOn; i++)
        if (lamp[index][on[i]] != 1)
            return 0;
    for (i = 0; i < countOff; i++)
        if (lamp[index][off[i]] != 0)
            return 0;
    return 1;
}
