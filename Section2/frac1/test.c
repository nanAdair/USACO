#include <stdio.h>
#include <stdlib.h>

struct fraction{
    int a;
    int b;
    float c;
};
int qfsort(struct fraction*, int, int);
int partition(struct fraction *, int, int);
void swap(struct fraction *, struct fraction *);

int count = 0;
int qfsort(struct fraction *cur, int p, int r)
{
    if(p < r){
        int q;
        q = partition(cur, p, r);
        qfsort(cur, p, q-1);
        qfsort(cur, q+1, r);
    }
}

int partition(struct fraction *cur, int p, int r)
{
    int i, j;
    float x = cur[r].c;
    i = p-1;
    printf("-------------------------\n");
    for(j = p; j <= r-1; j++){
        if(cur[j].c < x){
            i += 1;
            printf("bbb: %f %f\n", cur[j].c, x);
            swap(cur+i, cur+j);
        }
        else
            printf("aaa: %f %f\n", cur[j].c, x);
    }
    swap(cur+i+1, cur+r);
    printf("--%d %d %d %d %f--\n", count++, i+1, p, r, x);
    for(j = p; j <= r; j++)
        printf("%d/%d ", cur[j].a, cur[j].b);
    printf("\n");
    return i+1;
}

void swap(struct fraction *m, struct fraction *n)
{
    struct fraction temp;
    temp.a = m->a;
    temp.b = m->b;
    temp.c = m->c;
    m->a = n->a;
    m->b = n->b;
    m->c = n->c;
    n->a = temp.a;
    n->b = temp.b;
    n->c = temp.c;
}

int main()
{
    FILE *fin = fopen("frac1.out.bk", "r");
    struct fraction cur[256001];
    int i, j, k;
    for(i = 0; i < 11; i++)
        fscanf(fin, "%d/%d %f", &cur[i].a, &cur[i].b, &cur[i].c);
    for(i = 0; i < 11; i++)
        printf("%d/%d %f\n", cur[i].a, cur[i].b, cur[i].c);
    
    qfsort(cur, 0, 10);
    printf("------------------\n");
    for(i = 0; i < 11; i++)
        printf("%d/%d %f\n", cur[i].a, cur[i].b, cur[i].c);
    
    float x = (float)1/(float)4;
    float y = (float)2/(float)5;
    printf("%d\n", x > y);
    
}
