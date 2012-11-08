/*
ID: wangbn11
LANG: C
TASK: comehome
*/
#include <stdio.h>

#define INF 0x1000000

int distance[52][52], number, visited[52];

//#define USACO

int dijsk(int [52][52]);
int findMin(int [52][52]);
void update(int [52][52], int);

int main()
{
#ifdef USACO
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
#endif
    FILE *fin = fopen("comehome.in", "r");
    FILE *fout = fopen("comehome.out", "w");
    fscanf(fin, "%d\n", &number);
    int i, j;
    
    for (i = 0; i < 52; i++) {
        for (j = 0; j < 52; j++)
            distance[i][j] = INF;
    }
    for (i = 0; i < number; i++) {
        int a, b, val;
        char c, d;
        fscanf(fin, "%c %c %d\n", &c, &d, &val);
        a = c >= 'a' ? c - 'A' - 6 : c - 'A'; 
        b = d >= 'a' ? d - 'A' - 6 : d - 'A';
        if (distance[a][b] > val)
            distance[a][b] = distance[b][a] = val;
    }
    
    int res;
    res = dijsk(distance);
    
    fprintf(fout, "%c %d\n", res + 'A', distance[25][res]);
    fclose(fin);
    fclose(fout);
}

int dijsk(int dist[52][52]) 
{
    int i, j, count, max, res;
    
    dist[25][25] = 0;
    count = 0;
    while (count < 52) {
        int index;
        index = findMin(dist);
        update(dist, index);
        visited[index] = 1;
        count++;
    }
    
    max = INF;
    for (i = 0; i < 25; i++) {
        if (max > distance[25][i]) {
            max = distance[25][i];
            res = i;
        }
    }
        
    return res;
}

int findMin(int dist[52][52])
{
    int i, max, res;
    max = INF;
    res = 0;
    for (i = 0; i < 52; i++) {
        if (max > dist[25][i] && visited[i] == 0) {
            max = dist[25][i];
            res = i;
        }
    }
    return res;
}

void update(int dist[52][52], int index)
{
    int i;
    for (i = 0; i < 52; i++) {
        if (dist[25][index] + dist[index][i] < dist[25][i])
            dist[25][i] = dist[25][index] + dist[index][i];
    }
}
