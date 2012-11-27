/*
ID: wangbn11
LANG: C
TASK: fence
*/
#include <stdio.h>
#include <stdlib.h>

/* 
 * 注意图的临接表表示时，构造图的时候传入的参数应该是**
 * 当数组的元素是指针的时候，要把这个数组传参，就要用指针的指针了
 * *优先级低于->
 * */
struct fence {
    int mark;
    struct fence *next;
};

int position[10000];
int pos;
int count[501];

void insert(struct fence **node, int mark);
int delete(struct fence **node);
void deleteByValue(struct fence **node, int mark);
void findEuler(struct fence *node[501], int index);
void findCircuit(struct fence **node, int index);

int main()
{
    FILE *fin = fopen("fence.in", "r");
    FILE *fout = fopen("fence.out", "w");
    int i, number, begin;
    begin = 501;
    fscanf(fin, "%d\n", &number);
    struct fence *node[501];
    
    for (i = 0; i < 501; i++) {
        node[i] = NULL;
        count[i] = 0;
    }
    for (i = 0; i < number; i++) {
        int sour, dest;
        fscanf(fin, "%d %d", &sour, &dest);
        insert(&node[sour], dest);
        insert(&node[dest], sour);
        count[sour] += 1;
        count[dest] += 1;
        begin = begin < sour ? begin : sour;
        begin = begin < dest ? begin : dest;
    }
    for (i = 0; i < 501; i++) {
        if (count[i] % 2 == 1) {
            begin = i;
            break;
        }
    }
    
    /*
    printf("----------------------\n");
    for (i = 1; i < 501; i++) {
        printf("%d: ", i);
        while (node[i] != NULL) {
            printf("%d ", node[i]->mark);
            node[i] = node[i]->next;
        }
        printf("\n");
    }*/
    
    findEuler(node, begin);
    
    for (i = pos-1; i >= 0; i--) {
        fprintf(fout, "%d\n", position[i]);
    }
    
    fclose(fin);
    fclose(fout);
}

void findEuler(struct fence **node, int index)
{
    pos = 0;
    findCircuit(node, index);
}

int depth = 0;
void findCircuit(struct fence **node, int index)
{
    if (node[index] == NULL) {
        position[pos] = index;
        pos += 1;
        return ;
    }
    
    while (node[index] != NULL) {
        depth++;
        int mark;
        mark = node[index]->mark;
        int both;
        both = delete(&node[index]);
        deleteByValue(&node[both], index);
        findCircuit(node, mark);
    }
    position[pos] = index;
    pos += 1;
}

void deleteByValue(struct fence **node, int mark)
{
    if ((*node)->mark == mark) {
        delete(node);
        return ;
    }
    struct fence *current = *node;
    while (current->next != NULL && current->next->mark != mark)
        current = current->next;
    if (current->next != NULL)
        current->next = current->next->next;
}

int delete(struct fence **node)
{
    int mark;
    mark = (*node)->mark;
    if ((*node)->next == NULL) {
        *node = NULL;
    }else 
        *node = (*node)->next;
    return mark;
}

void insert(struct fence **node, int mark)
{
    /*
     * 头的地址要变的时候要用**
     * 后面的添加不能改变头的地址
     * */
    struct fence *temp;
    temp = (struct fence *)malloc(sizeof(struct fence));
    temp->mark = mark;
    temp->next = NULL;
    
    if (*node == NULL) {
        *node = temp;
        return ;
    }
    struct fence **head = node;
    if ((*head)->mark > mark) {
        temp->next = *head;
        *head = temp;
        return ;
    }
    struct fence *current = *head;
    while (current->next != NULL && current->next->mark < mark)
        current = current->next;
    temp->next = current->next;
    current->next = temp;
    /* 错误，把head覆盖了会 
    while ((*head)->next != NULL && (*head)->next->mark < mark) {
        *head = (*head)->next;
    }
    temp->next = (*head)->next;
    (*head)->next = temp;
    */
}
