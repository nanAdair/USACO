/*
ID: wangbn11
LANG: C
TASK: cowtour
*/
#include <stdio.h>
#include <math.h>

#define NUM 151
#define INF 1000000

struct point {
    int x;
    int y;
    int visited;
};

struct point pas[NUM];         //point on the map
double distance[NUM][NUM];
int number, connect[NUM][NUM];

void ff();
double  wallshall();
double dist(int, int);
double findMax();

#define USACO
int main()
{
#ifdef USACO
//    freopen("cowtour.in", "r", stdin);
//    freopen("cowtour.out", "w", stdout);
#endif
    FILE *fin = fopen("cowtour.in", "r");
    FILE *fout = fopen("cowtour.out", "w");
    int i, j;
    double diameter, maxnow;
    fscanf(fin, "%d", &number);
    for (i = 0; i < number; i++)
        fscanf(fin, "%d %d", &pas[i].x, &pas[i].y);
    
    for (i = 0; i < number; i++) {
        char buffer[NUM+1];
        fscanf(fin, "%s", buffer);
        for (j = 0; j < number; j++) {
            connect[i][j] = buffer[j] - '0';
        }
    }
    
    diameter = INF;
    ff();
    maxnow = wallshall();
    
    /*  
    for (i = 0; i < number; i++) {
        for(j = 0; j < number; j++) {
            printf("%.1f ", distance[i][j]);
        }
        printf("\n");
    }
    */
    
    for (i = 0; i < number; i++) {
        for (j = 0; j < number && i != j && distance[i][j] == INF; j++) {
            double tempDist;
            tempDist = findMax(i, j);
            tempDist = tempDist > maxnow ? tempDist : maxnow;
            diameter = diameter > tempDist ? tempDist : diameter;
        }
    }
    
    fprintf(fout, "%.6f\n", diameter);
    
    fclose(fin);
    fclose(fout);
}

double findMax(int a, int b)
{
    double temp = 0;
    int i, j;
    double add = dist(a, b);
    
    for (i = 0; i < number; i++) {
        for (j = 0; j < number; j++) {
            if ((distance[i][a] == INF && i!= a) || (distance[b][j] == INF && j != b))
                continue;
            double aa, bb, length;
            aa = distance[i][a];
            bb = distance[b][j];
            if (i == a)
                aa = 0;
            if (j == b)
                bb = 0;
            length = aa + add + bb;
            temp = temp < length ? length : temp;
        }
    }

    return temp;
}
double wallshall()
{
    int i, j, k;
    double temp[NUM][NUM];
    
    for (k = 0; k < number; k++) {
        for (i = 0; i < number; i++) {
            for (j = 0; j < number; j++) {
                if (i == j)
                    continue;
                if (distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }
      
    double max = 0;
    for (i = 0; i < number; i++) {
        for (j = 0; j < number; j++) {
            if (i == j || distance[i][j] == INF)
                continue;
            max = max > distance[i][j] ? max : distance[i][j];
        }
    }
    
    return max;
}

double dist(int a, int b)
{
    double length;
    length = pow(abs((pas[a].x - pas[b].x)), 2.0) + pow(abs((pas[a].y - pas[b].y)), 2.0);
    length = sqrt(length);
    return length;
}

void ff()
{
    int i, j;
    for (i = 0; i < number; i++) {
        for (j = 0; j < number; j++) {
            if (connect[i][j] == 0)
                distance[i][j] = INF;
            else
                distance[i][j] = dist(i, j);
        }
    }
}
