/*
ID: wangbn11
LANG: C
TASK: nocows
*/
#include <stdio.h>

int tree[101][202];
int small_tree[101][202];

void manage(int, int);

int main()
{
    FILE *fin = fopen("nocows.in", "r");
    FILE *fout = fopen("nocows.out", "w");
    int nodes, height;
    fscanf(fin, "%d %d", &nodes, &height);
    
    manage(nodes, height);
    
    int i, j;
    for (i = 1; i <= height; i++) {
        for (j = 1; j <= nodes; j+=2) {
            printf("%d %d: %d %d\n", i, j, tree[i][j], small_tree[i][j]);
        }
    }
    
    fprintf(fout, "%d\n", tree[height][nodes]);
    
    fclose(fin);
    fclose(fout);
}

void manage(int nodes, int height)
{
    int i, j;
    
    tree[1][1] = 1;
    for (i = 2; i <= height; i++) {
        for (j = 1; j <= nodes; j += 2) {
            int k;
            tree[i][j] = 0;
            for (k = 1; k <= j-1-k; k += 2) {
                //通过判断节点的个数是否相同来判断对称与否,不对称的时候，深度相同也是不同的选择
                int c;
                if (k != j-1-k)
                    c = 2;
                else
                    c = 1;
                tree[i][j] += c * (
                        small_tree[i-2][k] * tree[i-1][j-1-k]
                        + tree[i-1][k] * small_tree[i-2][j-1-k]
                        + tree[i-1][k] * tree[i-1][j-1-k]
                        );
                tree[i][j] %= 9901;
            }
        }
        //重要！！一个深度可以有多个节点，所以都要更新
        for (j = 0; j <= nodes; j++) {
            small_tree[i-1][j] += small_tree[i-2][j] + tree[i-1][j];
            small_tree[i-1][j] %= 9901;
        }
    }
}
