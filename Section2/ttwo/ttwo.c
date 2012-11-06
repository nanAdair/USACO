/*
ID: wangbn11
LANG: C
TASK: ttwo
*/
#include <stdio.h>

//注意一个字符字符读入的时候会把最后的回车符读入
//注意行和列谁加谁减
char grid[10][10];
int movey[] = {0, 1, 0, -1};
int movex[] = {-1, 0, 1, 0};

void move(int *, int *, int *);

int main()
{
    FILE *fin = fopen("ttwo.in", "r");
    FILE *fout = fopen("ttwo.out", "w");
    int i, j, fx, fy, cx, cy;
    for (i = 0; i < 10; i++) {
        char buffer[11];
        fscanf(fin, "%s", buffer);
        for (j = 0; j < 10; j++) {
            char c = buffer[j];
            grid[i][j] = c;
            if (c == 'F') {
                fx = i;
                fy = j;
                grid[i][j] = '.';
            }else if (c == 'C') {
                cx = i;
                cy = j;
                grid[i][j] = '.';
            }
        }
    }
    
    int directF, directC;
    directF = directC = 0;
    for (i = 0; i < 160000 && (fx != cx || fy != cy); i++) {
        move(&fx, &fy, &directF);
        move(&cx, &cy, &directC);
    }
    
    if (fx == cx && fy == cy)
        fprintf(fout, "%d\n", i);
    else
        fprintf(fout, "%d\n", 0);
    
    fclose(fin);
    fclose(fout);
}

void move(int *x, int *y, int *direct)
{
    int nx, ny;
    nx = *x + movex[*direct];
    ny = *y + movey[*direct];
    if (nx < 0 || nx > 9 || ny < 0 || ny > 9 || grid[nx][ny] == '*')
        *direct = (*direct + 1) % 4;
    else {
        *x = nx;
        *y = ny;
    }
}
