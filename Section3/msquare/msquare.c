/*
ID: wangbn11
LANG: C
TASK: msquare
*/
#include <stdio.h>
/* 
 * 康托定理，把全排列的状态映射到自然数上
 * */

struct ms {
    int x;
    int y;
    char c;
    int parent;
    int step;
};
int key[41000];
FILE *fout;

void opa(int *, int *);
void opb(int *, int *);
void opc(int *, int *);
int encode(int x, int y);
int isIn(int, int);
int comp(int resx, int resy, int x, int y, char c, int index, struct ms *square, int *inNow);
void print(struct ms *square, int index);

int main()
{
    FILE *fin = fopen("msquare.in", "r");
    fout = fopen("msquare.out", "w");
    int x1, x2, x3, x4, y1, y2, y3, y4;
    fscanf(fin, "%d %d %d %d %d %d %d %d", &x1, &x2, &x3, &x4, &y1, &y2, &y3, &y4);
    int resx, resy;
    resx = x1 * 1000 + x2 * 100 + x3 * 10 + x4;
    resy = y4 * 1000 + y3 * 100 + y2 * 10 + y1;
      
    if (resx == 1234 && resy == 8765) {
        fprintf(fout, "0\n\n");
        fclose(fin);
        fclose(fout);
        return ;
    }
    
    struct ms square[41000];
    square[0].x = 1234;
    square[0].y = 8765;
    square[0].parent = -1;
    square[0].step = 0;
    key[encode(1234, 8765)] = 1;
    
    int flag, index, inNow;
    flag = index = inNow = 0;
    while (!flag) {
        int x, y;
        x = square[index].x;
        y = square[index].y;
        opa(&x, &y);
        if (!isIn(x, y)) {
            if (comp(resx, resy, x, y, 'A', index, square, &inNow))
                flag = 1;
        }
        if (!flag) {
            x = square[index].x;
            y = square[index].y;
            opb(&x, &y);
            if (!isIn(x, y)) {
                if (comp(resx, resy, x, y, 'B', index, square, &inNow))
                    flag = 1;
            }
        }
        if (!flag) {
            x = square[index].x;
            y = square[index].y;
            opc(&x, &y);
            if (!isIn(x, y)) {
                if (comp(resx, resy, x, y, 'C', index, square, &inNow))
                    flag = 1;
            }
        }
        index++;
    }
    
    fprintf(fout, "%d\n", square[inNow].step);
    print(square, inNow);
    fprintf(fout, "\n");

    fclose(fin);
    fclose(fout);
}

void opa(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void opb(int *x, int *y)
{
    int temp;
    temp = *x % 10 * 1000 + *x / 10;
    *x = temp;
    temp = *y % 10 * 1000 + *y / 10;
    *y = temp;
}

void opc(int *x, int *y)
{
    int i, a[4], b[4];
    i = 0;
    while (*x) {
        a[i++] = *x % 10;
        *x /= 10;
    }
    i = 0;
    while (*y) {
        b[i++] = *y % 10;
        *y /= 10;
    }
    *x = a[3] * 1000 + b[2] * 100 + a[2] * 10 + a[0];
    *y = b[3] * 1000 + b[1] * 100 + a[1] * 10 + b[0];
}

int encode(int x, int y)
{
    int mul[7] = {5040, 720, 120, 24, 6, 2, 1};
    int number[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int digit[8], i;
    i = 0;
    while (y) {
        digit[i++] = y % 10;
        y /= 10;
    }
    while (x) {
        digit[i++] = x % 10;
        x /= 10;
    }
    
    int res = 0;
    for (i = 7; i > 0; i--) {
        int small, j;
        small = 0;
        for (j = 1; j < digit[i]; j++) {
            if (number[j] == 0)
                small++;
        }
        res += small * mul[7 - i];
        number[digit[i]] = 1;
    }
    return res;
}

int isIn(int x, int y)
{
    int index;
    index = encode(x, y);
    if (key[index] == 1)
        return 1;
    key[index] = 1;
    return 0;
}

int comp(int resx, int resy, int x, int y, char c, int index, struct ms *square, int *inNow)
{
    *inNow += 1;
    square[*inNow].x = x;
    square[*inNow].y = y;
    square[*inNow].c = c;
    square[*inNow].parent = index;
    square[*inNow].step = square[index].step + 1;
    
    if (resx == x && resy == y)
        return 1;
    return 0;
}

void print(struct ms *square, int index)
{
    if (square[index].parent != 0)
        print(square, square[index].parent);
    fprintf(fout, "%c", square[index].c);
}
