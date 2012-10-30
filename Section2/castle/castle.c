/*
ID: wangbn11
LANG: C
TASK: castle
*/
#include <stdio.h>
/*
 * 注意位运算优先级在比较运算符后面
 * */

struct modules{
    int num;
    int ans;
    int color;           // 0 for white, 1 for gray, 2 for black
};

struct modules ins[51][51];
int area, M, N;
int store[2501];
int mark[2501];
int max, delx, dely;
char c;             // mark the wall to be destroied

void dfs(int x, int y, int ans);
void insertionSort(int *, int);
void findDel();

int main()
{
    int i, j, count;
    FILE *fin = fopen("castle.in", "r");
    FILE *fout = fopen("castle.out", "w");
    fscanf(fin, "%d %d", &M, &N);
    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++){
            fscanf(fin, "%d", &ins[i][j].num);
            ins[i][j].ans = 0;
            ins[i][j].color = 0;
        }
    
    count = 0;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++){
            if(ins[i][j].color == 0){
                area = 1;
                ins[i][j].ans = (i-1)*M + j;
                dfs(i, j, ins[i][j].ans);
                store[count++] = area;
                mark[(i-1)*M+j] = area;
                printf("%d %d\n", count, area);
            }
        }
    
    insertionSort(store, count);
    
    fprintf(fout, "%d\n", count); //number of rooms
    fprintf(fout, "%d\n", store[0]); //largest room
    
    max = 0;
    findDel();
    
    fprintf(fout, "%d\n", max);
    fprintf(fout, "%d %d %c\n", delx, dely, c);
    
    fclose(fin);
    fclose(fout);
}

void dfs(int x, int y, int ans)
{
    ins[x][y].color = 1;
    ins[x][y].ans = ans;
    int temp = ins[x][y].num;
    
    if((temp & 0x1) == 0 && (y-1 >= 1) && (ins[x][y-1].color == 0)){
        area++;
        dfs(x, y-1, ans);
    }
    if((temp & 0x2) == 0 && (x-1 >= 1) && (ins[x-1][y].color == 0)){
        area++;
        dfs(x-1, y, ans);
    }
    if((temp & 0x4) == 0 && (y+1 <= M) && (ins[x][y+1].color == 0)){
        area++;
        dfs(x, y+1, ans);
    }
    if((temp & 0x8) == 0 && (x+1 <= N) && (ins[x+1][y].color == 0)){
        area++;
        dfs(x+1, y, ans);
    }
    
    ins[x][y].color = 2;
}

void insertionSort(int *store, int count)
{
    int i, j;
    for(i = 0; i < count; i++){
        int temp = store[i];
        for(j = i-1; j >= 0 && store[j] < temp; j--)
            store[j+1] = store[j];
        store[j+1] = temp;
    }
}

void findDel()
{
    int i, j;
    for(j = 1; j <= M; j++){
        for(i = N; i >= 1; i--){
            int temp = ins[i][j].num;
            if((temp & 0x1) != 0 && j-1 >= 1){
                if(ins[i][j].ans != ins[i][j-1].ans){
                    int areaNow;
                    areaNow = mark[ins[i][j].ans] + mark[ins[i][j-1].ans];
                    if(areaNow > max){
                        max = areaNow;
                        delx = i;
                        dely = j-1;
                        c = 'E';
                    }
                }
            }
        }
        for(i = N; i >= 1; i--){
            int temp = ins[i][j].num;
            if((temp & 0x2) != 0 && i-1 >= 1){
                if(ins[i][j].ans != ins[i-1][j].ans){
                    int areaNow;
                    areaNow = mark[ins[i][j].ans] + mark[ins[i-1][j].ans];
                    if(areaNow > max){
                        max = areaNow;
                        delx = i;
                        dely = j;
                        c = 'N';
                    }
                }
            }
        }
    }
    
}
