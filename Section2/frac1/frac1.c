/*
ID: wangbn11
LANG: C
TASK: frac1
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fraction{
    int a;
    int b;
    float c;
};

int judge(int a, int b);
int qfsort(struct fraction*, int, int);
int partition(struct fraction *, int, int);
void swap(struct fraction *, struct fraction *);

int main()
{
    FILE *fin = fopen("frac1.in", "r");
    FILE *fout = fopen("frac1.out", "w");
    int number, i, j;
    fscanf(fin, "%d", &number);
    
    struct fraction cur[25601];
    int k = 0;
    for(i = 0; i <= number; i++){
        for(j = 0; j <= i; j++){
            if(judge(j, i)){
                cur[k].a = j;
                cur[k].b = i;
                cur[k++].c = (float)j/(float)i;
            }
        }
    }
    
    qfsort(cur, 0, k-1);
    for(i = 0; i < k; i++)
        fprintf(fout, "%d/%d\n", cur[i].a, cur[i].b);
    
    fclose(fin);
    fclose(fout);
}

int judge(int a, int b)
{
    if(a == 1 && b==1)
        return 1;
    while(a != 0 && b != 0){
        if(a < b)
            b = b%a;
        else
            a = a%b;
    }
    if((a == 0 && b == 1) || (a == 1 && b == 0))
        return 1;
    return 0;
}

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
    for(j = p; j <= r-1; j++){
        if(cur[j].c < x){
            i += 1;
            swap(cur+i, cur+j);
        }
    }
    swap(cur+i+1, cur+r);
    return i+1;
}

void swap(struct fraction *m, struct fraction *n)
{
    struct fraction *temp;
    temp = (struct fraction *)malloc(sizeof(struct fraction));
    temp->a = m->a;
    temp->b = m->b;
    temp->c = m->c;
    m->a = n->a;
    m->b = n->b;
    m->c = n->c;
    n->a = temp->a;
    n->b = temp->b;
    n->c = temp->c;
}
