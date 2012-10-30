/*
ID: wangbn11
LANG: C
TASK: packrec
*/
#include <stdio.h>
#include <string.h>
/*记住define的东西在使用的时候要加上括号，他是纯粹替代的
 *利用位操作和数组来遍历多种情况*/

#define ri(p) (p & 0x8) >> 3
#define rj(p) (p & 0x4) >> 2
#define rk(p) (p & 0x2) >> 1
#define rl(p) (p & 0x1)

struct rec{
    int side[2];
};

int max2(int, int);
int max3(int, int, int);
int max4(int, int, int, int);
void store(struct rec*, int *, int, int, int *);
void insertionSort(struct rec*, int);

int main()
{
    FILE *fin = fopen("packrec.in", "r");
    FILE *fout = fopen("packrec.out", "w");
    int i, j, k, l, p, index;
    int min = 0x7fff;
    index = 0;
    struct rec in[4], out[100];
    
    for(i = 0; i < 4; i++)
        fscanf(fin, "%d %d", &in[i].side[0], &in[i].side[1]);
    
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4 && i != j; j++){
            for(k = 0; k < 4 && k != i && k !=j; k++){
                l = 6 - i - j - k;
                for(p = 0; p < 16; p++){
                    int h1, w1, h2, w2, h3, w3, h4, w4;
                    h1 = in[i].side[1 - (ri(p))];
                    w1 = in[i].side[ri(p)];
                    h2 = in[j].side[1 - (rj(p))];
                    w2 = in[j].side[rj(p)];
                    h3 = in[k].side[1 - (rk(p))];
                    w3 = in[k].side[rk(p)];
                    h4 = in[l].side[1 - (rl(p))];
                    w4 = in[l].side[rl(p)];
                    
                    int win, hin;
                    win = w1 + w2 + w3 + w4;
                    hin = max4(h1, h2, h3, h4);
                    store(out, &index, win, hin, &min); 

                    win = max2(w1+w2+w3, w4);
                    hin = max3(h1, h2, h3)+h4;
                    store(out, &index, win, hin, &min);
                    
                    win = max2(w1+w2, w3)+w4;
                    hin = max3(h1+h3, h2+h3, h4);
                    store(out, &index, win, hin, &min);
                    
                    win = w1+w4+max2(w2, w3);
                    hin = max3(h1, h2+h3, h4);
                    store(out, &index, win, hin, &min);
                    
                    if(h3 >= h2+h4)
                        win = max3(w1, w2+w3, w3+w4);
                    else if(h3 > h4 && h3 < h2+h4)
                        win = max3(w1+w2, w2+w3, w3+w4);
                    else if(h3 < h4 && h2+h4 <= h1+h3)
                        win = max3(w1+w2, w1+w4, w3+w4);
                    else if(h4 >= h1+h3)
                        win = max3(w2, w1+w4, w3+w4);
                    else if(h3 == h4)
                        win = max2(w1+w2, w3+w4);
                    hin = max2(h1+h3, h2+h4);
                    store(out, &index, win, hin, &min);
                }
            }
        }
    }
    
    insertionSort(out, index);
    fprintf(fout, "%d\n", min);
    for(i = 0; i < index; i++){
        if(i != 0 && out[i].side[0] == out[i-1].side[0])
            continue;
        fprintf(fout, "%d %d\n", out[i].side[0], out[i].side[1]);
    }
    
    fclose(fin);
    fclose(fout);
}

int max2(int a, int b)
{
    return a > b ? a : b;
}

int max3(int a, int b, int c)
{
    return max2(max2(a, b), c);
}

int max4(int a, int b, int c, int d)
{
    return max2(max3(a, b, c), d);
}


void store(struct rec* out, int *index, int win, int hin, int *min)
{
    int area;
    area = win * hin;
    if(area > *min)
        return ;
    if(area == *min){
        out[*index].side[0] = win < hin ? win : hin;
        out[*index].side[1] = win > hin ? win : hin;
        *index += 1;
    }
    else{
        *index = 0;
        out[0].side[0] = win < hin ? win : hin;
        out[0].side[1] = win > hin ? win : hin;
        *min = area;
    }
    if(*min == 20)
        printf("xxx: %d %d\n", win, hin);
}

void insertionSort(struct rec* out, int number)
{
    int i, j;
    for(i = 0; i < number; i++){
        int w, h;
        w = out[i].side[0];
        h = out[i].side[1];
        for(j = i - 1; j >= 0 && out[j].side[0] > w; j--){
            out[j+1].side[0] = out[j].side[0];
            out[j+1].side[1] = out[j].side[1];
        }
        out[j+1].side[0] = w;
        out[j+1].side[1] = h;
    }
}
