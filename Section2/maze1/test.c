#include <stdio.h>

struct grid {
    int distance;
    int visited;
};
int col, row, exit1r, exit1c, exit2r, exit2c, findOne;
int matrix[201][79];

void generateMap(FILE *);
void lookForExit();
void findMin(struct grid [101][39]);
void updateDis(struct grid [101][39], int, int);
void dijkstra(struct grid [101][39], int, int);

int main()
{
    FILE *fin = fopen("maze1.in", "r");
    FILE *fout = fopen("maze1.out", "w");
    fscanf(fin, "%d %d\n", &col, &row);
    
    generateMap(fin);
    findOne = 0;
    lookForExit();
    findOne = 1;
    lookForExit();
    printf("%d %d\n", exit1r, exit1c);
    printf("%d %d\n", exit2r, exit2c);
    
    struct grid exit1[101][39], exit2[101][39];
    dijkstra(exit1, exit1r, exit1c);
    dijkstra(exit2, exit2r, exit2c);
    
    int i, j, max;
    

    printf("-------------------------\n");
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            printf("%d %d\n", exit1[i][j].distance, exit2[i][j].distance);
        }
    }
    max = 0;
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            int temp;
            temp = exit1[i][j].distance > exit2[i][j].distance ? exit2[i][j].distance : exit1[i][j].distance;
            max = max > temp ? max : temp;
        }
    }
    fprintf(fout, "%d\n", max);
    
    fclose(fin);
    fclose(fout);
}

void generateMap(FILE *fin)
{
   int i, j, rowLength, colLength;
   rowLength = row * 2 + 1;
   colLength = col * 2 + 1;
   
   char buffer[81];
   for (i = 0; i < rowLength; i++) {
       fgets(buffer, 81, fin);
       printf("%s", buffer);
       if (i % 2 == 0) {
           for (j = 1; j < colLength; j += 2) {
               if (buffer[j] == '-')
                   matrix[i][j] = 0;
               else
                   matrix[i][j] = 1;
           }
       }else {
           for (j = 0; j < colLength; j += 2) {
               if (buffer[j] == '|')
                   matrix[i][j] = 0;
               else
                   matrix[i][j] = 1;
           }
       }
   }
   
   for (i = 0; i < rowLength; i++) {
       if (i % 2 == 0) {
           for (j = 1; j < colLength; j += 2)
               printf("%d ", matrix[i][j]);
           printf("\n");
       }else {
           for (j = 0; j < colLength; j += 2)
               printf("%d ", matrix[i][j]);
           printf("\n");
       }
   }
}

void lookForExit()
{
    int i, j, rowLength, colLength;
    rowLength = row * 2 + 1;
    colLength = col * 2 + 1;
    for (j = 1; j < colLength; j += 2) {
        if (matrix[0][j] == 1) {
            if (findOne == 0) {
                findOne = 1;
                exit1r = 1;
                exit1c = (j+1) / 2;
                return ;
            }else {
                if (exit1r != 1 || exit1c != (j+1)/2) {
                    exit2r = 1;
                    exit2c = (j+1) / 2;
                }
            }
        }
        if (matrix[rowLength-1][j] == 1) {
            if (findOne == 0) {
                findOne = 1;
                exit1r = rowLength / 2;
                exit1c = (j+1) / 2;
                return ;
            }else {
                if (exit1r != rowLength/2 || exit1c != (j+1)/2) {
                    exit2r = rowLength / 2;
                    exit2c = (j+1) / 2;
                }
            }
        }
    }
    for (j = 1; j < rowLength; j += 2) {
        if (matrix[j][0] == 1) {
            if (findOne == 0) {
                findOne = 1;
                exit1r = (j+1) / 2;
                exit1c = 1;
                return ;
            }else {
                if (exit1r != (j+1)/2 || exit1c != 1) {
                    exit2r = (j+1) / 2;
                    exit2c = 1;
                }
            }
        }
        if (matrix[j][colLength-1] == 1) {
            if (findOne == 0) {
                findOne = 1;
                exit1r = (j+1) / 2;
                exit1c = colLength / 2;
                return ;
            }else {
                if (exit1r != (j+1)/2 || exit1c != colLength/2) {
                    exit2r = (j+1) / 2;
                    exit2c = colLength / 2;
                }
            }
        }
    }
}

int nowr, nowc;
void dijkstra(struct grid exit[101][39], int sourcer, int sourcel)
{
    int i, j, num;
    num = 0;
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            exit[i][j].distance = 10000;
            exit[i][j].visited = 0;
        }
    }
    while (num < row * col) {
        if (num == 0) {
            exit[sourcer][sourcel].distance = 1;
            exit[sourcer][sourcel].visited = 1;
            updateDis(exit, sourcer, sourcel);
            num++;
            continue;
        }
        findMin(exit);
        exit[nowr][nowc].visited = 1;
        updateDis(exit, nowr, nowc);
        num++;
    }
}

void updateDis(struct grid exit[101][39], int rr, int cc)
{
    int dist = exit[rr][cc].distance + 1;
    //up
    if (2*rr-2 >= 2 && matrix[2*rr-2][2*cc-1] == 1 && dist < exit[rr-1][cc].distance)
        exit[rr-1][cc].distance = dist;
    //right
    if (2*cc <= 2*col-2 && matrix[2*rr-1][2*cc] == 1 && dist < exit[rr][cc+1].distance)
        exit[rr][cc+1].distance = dist;
    //down
    if (2*rr <= 2*row-2 && matrix[2*rr][2*cc-1] == 1 && dist < exit[rr+1][cc].distance)
        exit[rr+1][cc].distance = dist;
    //left
    if (2*cc-2 >= 2 && matrix[2*rr-1][2*cc-2] == 1 && dist < exit[rr][cc-1].distance)
        exit[rr][cc-1].distance = dist;
}

void findMin(struct grid exit[101][39])
{
    int i, j, min;
    min = 10001;
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            if (exit[i][j].distance < min && exit[i][j].visited == 0) {
                nowr = i;
                nowc = j;
                min = exit[i][j].distance;
            }
        }
    }
}
