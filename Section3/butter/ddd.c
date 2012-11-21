/*
ID: wangbn11
LANG: C
TASK: butter
*/
#include <stdio.h>

#define INF 10000000

struct node {
    int dist;
    int label;
};

int pasture[1000];                      //用来表示cow在哪个节点处
int distance[1000][1000];                //用来表示两个直连节点之间的距离
int directConnect[1000][1000];           //用来记录一个节点都和哪些节点直连
int numberOfConnect[1000];              //用来记录一个节点共有多少条直连的边
int labelPos[1000];                    //每一个节点在堆中的位置
int distanceInit[1000][1000];
int heapSize;

void buildHeap(struct node *cur, int number);
void minHeapify(struct node *cur, int index, int number);
void swap(struct node *cur, int a, int b);
void extractMin(struct node *cur);
void updateHeap(struct node *cur, int index);
int dijsk(struct node *cur, int index, int number);

int main()
{
    FILE *fin = fopen("butter.in", "r");
    FILE *fout = fopen("butter.out", "w");
    int i, k, cows, pasts, paths;
    for (i = 1; i < 1000; i++) {
        for (k = 1; k < 1000; k++) {
            distance[i][k] = INF;
            if (i == k)
                distance[i][k] = 0;
        }
    }
    fscanf(fin, "%d %d %d", &cows, &pasts, &paths);
    for (i = 0; i < cows; i++) {
        int num;
        fscanf(fin, "%d", &num);
        pasture[num] += 1;
    }
    for (i = 0; i < paths; i++) {
        int sour, dest, length;
        fscanf(fin, "%d %d %d", &sour, &dest, &length);
        distance[dest][sour] = distance[sour][dest] = length;
        distanceInit[sour][dest] = distanceInit[dest][sour] = length;
        directConnect[sour][numberOfConnect[sour]] = dest;
        directConnect[dest][numberOfConnect[dest]] = sour;
        numberOfConnect[sour] += 1;
        numberOfConnect[dest] += 1;
    }
    /*
    for (i = 1; i <= pasts; i++) {
        for (k = 1; k <= pasts; k++) {
            printf("%d ", distance[i][k]);
        }
        printf("\n");
    }
    */
    
    int max = INF;
    for (i = 1; i <= pasts; i++) {
        struct node cur[1000];            //用来构建堆，记录各个节点到单源的距离
        int j;
        for (j = 1; j <= pasts; j++) {
            if (j == i) {
                cur[j].dist = 0;
                cur[j].label = j;
            }else {
                cur[j].dist = INF;
                cur[j].label = j;
            }
            labelPos[j] = j;
        }
        int sum;
        sum = dijsk(cur, i, pasts);
        if (i == 799)
        printf("sum: %d ", sum);
        max = max > sum ? sum : max;
    }
    
    /*
    for (i = 1; i <= pasts; i++) {
        for (k = 1; k <= pasts; k++) {
            printf("%d ", distance[i][k]);
        }
        printf("\n");
    }
    */
    fprintf(fout, "%d\n", max);
    
    fclose(fin);
    fclose(fout);
}

void buildHeap(struct node *cur, int number)
{
    int i;
    for (i = number / 2; i >= 1; i--)
        minHeapify(cur, i, number);
}

void minHeapify(struct node *cur, int index, int number)
{
    int left, right;
    left = 2 * index;
    right = 2 * index + 1;
    int minest;
    if (left <= number && cur[index].dist > cur[left].dist)
        minest = left;
    else
        minest = index;
    if (right <= number && cur[minest].dist > cur[right].dist)
        minest = right;
    if (minest != index) {
        swap(cur, index, minest);
        minHeapify(cur, minest, number);
    }
}

void swap(struct node *cur, int a, int b)
{
    int dist, label;
    dist = cur[a].dist;
    label = cur[a].label;
    cur[a].dist = cur[b].dist;
    cur[a].label = cur[b].label;
    cur[b].dist = dist;
    cur[b].label = label;
    labelPos[cur[a].label] = a;
    labelPos[cur[b].label] = b;
}

void extractMin(struct node *cur)
{
    cur[1].dist = cur[heapSize].dist;
    cur[1].label = cur[heapSize].label;
    heapSize -= 1;
    minHeapify(cur, 1, heapSize);
}

void updateHeap(struct node *cur, int index)
{
    int parent;
    parent = index / 2;
    while (index > 1 && cur[parent].dist > cur[index].dist) {
        swap(cur, index, parent);
        index = parent;
        parent = index / 2;
    }
}

int dijsk(struct node *cur, int index, int number)
{
    int count = 0;
    heapSize = number;
    buildHeap(cur, heapSize);
    while (count < number) {
        int minElement;
        minElement = cur[1].label;
        //printf("%d, %d\n", minElement, numberOfConnect[minElement]);
        distance[index][minElement] = cur[1].dist;
        extractMin(cur);
        int j;
        for (j = 0; j < numberOfConnect[minElement]; j++) {
            int indexNow;
            indexNow = directConnect[minElement][j];
            if (index == 799) {
            printf("%d ", indexNow);
           printf("1: %d %d %d\n", index, indexNow, distance[index][indexNow]);
           printf("2: %d %d %d\n", index, minElement, distance[index][minElement]);
           printf("3: %d %d %d\n", minElement, indexNow, distance[minElement][indexNow]);
            }
            if (distance[index][indexNow] >= distance[index][minElement] + distanceInit[minElement][indexNow]) {
                distance[index][indexNow] = distance[index][minElement] + distanceInit[minElement][indexNow];
                int indexInHeap = labelPos[indexNow];
                cur[indexInHeap].dist = distance[index][indexNow];
                updateHeap(cur, indexInHeap);
            }
        }
        count++;
    }
    int i, sum = 0;
    for (i = 1; i <= number; i++) {
        sum += distance[index][i] * pasture[i];
    }
    
    return sum;
}

