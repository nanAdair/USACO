/*
ID: wangbn11
LANG: C
TASK: rect1
*/
#include <stdio.h>

#define NUM 1001
int x1[NUM], y1[NUM], x2[NUM], y2[NUM], color[NUM], res[2501], number;
/*
 * 漂浮法
 * 从最后面倒序，减去后面出现的重叠的那部分
 * */

void cover(int, int, int, int, int, int);

int main()
{
    FILE *fin = fopen("rect1.in", "r");
    FILE *fout = fopen("rect1.out", "w");
    fscanf(fin, "%d %d %d", &x2[0], &y2[0], &number);
    x1[0] = y1[0] = 0;
    color[0] = 1;
    
    int i;
    for (i = 1; i <= number; i++) {
        fscanf(fin, "%d %d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i], &color[i]);
    }
    
    for (i = number; i >= 0; i--) 
        cover(x1[i], y1[i], x2[i], y2[i], color[i], i + 1);
    
    for (i = 1; i < 2501; i++) {
        if (res[i] != 0) {
            fprintf(fout, "%d %d\n", i, res[i]);
        }
    }
    
    fclose(fin);
    fclose(fout);
}

void cover(int lx, int ly, int rx, int ry, int col, int k)
{
    while (k <= number && (lx >= x2[k] || ly >= y2[k] || rx <= x1[k] || ry <= y1[k]))
        k++;
    
    if (k > number) {
        res[col] = res[col] + (rx - lx) * (ry - ly);
        return ;
    }
    if (lx <= x1[k]) {
        cover(lx, ly, x1[k], ry, col, k+1);
        lx = x1[k];
    }
    if (ly <= y1[k]) {
        cover(lx, ly, rx, y1[k], col, k+1);
        ly = y1[k];
    }
    if (rx >= x2[k]) {
        cover(x2[k], ly, rx, ry, col, k+1);
        rx = x2[k];
    }
    if (ry >= y2[k]) {
        cover(lx, y2[k], rx, ry, col, k+1);
        ry = y2[k];
    }
}
