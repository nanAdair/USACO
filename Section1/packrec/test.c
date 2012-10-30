#include <stdio.h>
#include <string.h>

#define ri(p) (p & 0x08) >> 3
#define rj(p) (p & 0x04) >> 2
#define rk(p) (p & 0x02) >> 1
#define rl(p) (p & 0x01)

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
    printf("min: %d\n", min);
    
    for(i = 0; i < 4; i++)
        fscanf(fin, "%d %d", &in[i].side[0], &in[i].side[1]);
    
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(i == j)
                continue;
            for(k = 0; k < 4; k++){
                if(k == i || k == j)
                    continue;
                l = 6 - i - j - k;
                for(p = 0; p < 16; p++){
                    int h1, w1, h2, w2, h3, w3, h4, w4;
                    h1 = in[i].side[1 - ri(p)];
                    printf("------------------\n");
                    printf("%d %d %d %d\n", h1, i, ri(p), in[0].side[1]);
                    w1 = in[i].side[ri(p)];
                    h2 = in[j].side[1 - rj(p)];
                    w2 = in[j].side[rj(p)];
                    h3 = in[k].side[1 - rk(p)];
                    w3 = in[k].side[rk(p)];
                    h4 = in[l].side[1 - rl(p)];
                    w4 = in[l].side[rl(p)];
                    printf("xxx: %d %d %d %d\n", i, j, k, l);
                    printf("ddd: %d %d %d %d %d\n", p, ri(p), rj(p), rk(p), rl(p));
                    printf("%d: %d %d %d %d %d %d %d %d\n",index, w1, h1, w2, h2, w3, h3, w4, h4);
                    int t;
/*                      printf("-----------------\n");
                    for(t = 0; t < 4; t++){
                        printf("%d %d\n", in[t].side[0], in[t].side[1]);
                    }
                    printf("-----------------\n");
 */                   
                    index++;
                }
            }
        }
    }
}
