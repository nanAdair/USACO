/*
ID: wangbn11
LANG: C
TASK: concom
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int digit;
    struct node *next;
};

int main()
{
    int comp[110][110];
    int pos, neg, val, i, j, number;
    FILE *fin = fopen("concom.in", "r");
    FILE *fout = fopen("concom.out", "w");
    fscanf(fin, "%d", &number);
    struct node *store[110];
    
    for (i = 1; i < 110; i++) 
        for (j = 1; j < 110; j++)
            comp[i][j] = 0;
    for (i = 1; i <= number; i++) {
        fscanf(fin, "%d %d %d", &pos, &neg, &val);
        comp[pos][neg] = val;
        if (store[neg] == NULL) {
            store[neg] = (struct node *)malloc(sizeof(struct node));
            store[neg]->digit = pos;
            store[neg]->next = NULL;
        }else {
            struct node *temp;
            temp = (struct node *)malloc(sizeof(struct node));
            temp->digit = pos;
            temp->next = store[neg];
            store[neg] = temp;
        }
    }
    
    for (i = 1; i < 110; i++) {
        for (j = 1; j < 110; j++) {
            struct node *now = store[i];
            while (now != NULL) {
                comp[now->digit][j] += comp[i][j] * comp[now->digit][i] / 100;
                now = now->next;
            }
        }
    }
    
    for (i = 1; i < 110; i++) {
        for (j = 1; j < 110; j++) {
            if (comp[i][j] > 50 && i != j)
                fprintf(fout, "%d %d\n", i, j);
        }
    }
    
    fclose(fin);
    fclose(fout);
}
    
