/*
ID: wangbn11
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Text here:
 * 1. list: the one cannot inter the while loop will return so take care
 * whether use the next or itself to determine
 * 2. fscanf: use > 0 instead of = 0 to see whether it read the end*/
struct map{
    char *name;
    int money;
    struct map *next;
};

struct map *head = NULL;
void mapInsert(char *name)
{
    if(head == NULL){
        head = (struct map *)malloc(sizeof(struct map));
        head->name = name;
        head->money = 0;
        head->next = NULL;
    }
    else{
        struct map *temp;
        struct map *p;
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        p = (struct map *)malloc(sizeof(struct map));
        p->name = name;
        p->money = 0;
        p->next = NULL;
        temp->next = p;
    }
}

struct map *mapSearch(char *name)
{
    struct map *temp;
    temp = head;
    while(temp != NULL){
        if(!strcmp(name, temp->name))
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void minus(struct map *cur, int num)
{
    cur->money -= num;
}

void add(struct map *cur, int num)
{
    cur->money += num;
}

int main()
{
   FILE *fin = fopen("gift1.in", "r");
   FILE *fout = fopen("gift1.out", "w");
   
   int number;
   char *name[10];
   fscanf(fin, "%d", &number);
   int i;
   for(i = 0; i<number; i++){
       name[i] = (char *)malloc(15 * sizeof(char));
       fscanf(fin, "%s", name[i]);
       mapInsert(name[i]);
   }
   
   char giverName[15];
   int j = 0;
   while(fscanf(fin, "%s", giverName) > 0){
       //printf("---%s---\n", giverName);
      //printf("Number %d round: ", ++j);
      char *receiveName[10];
      int moneyToGive;
      int person;
      fscanf(fin, "%d %d", &moneyToGive, &person);
      if(person == 0)
          continue;
      //printf("%s gives %d to %d person\n", giverName, moneyToGive, person);
      
      int i;
      for(i = 0; i < person; i++){
          receiveName[i] = (char *)malloc(14 * sizeof(char));
          fscanf(fin, "%s", receiveName[i]);
          struct map *cur;
          cur = mapSearch(receiveName[i]);
          add(cur, moneyToGive/person);
          ///printf("%s receive %d\n", receiveName[i], moneyToGive/person);
          free(receiveName[i]);
      }
      
      //printf("%s gives %d to\n", giverName, moneyToGive);
      minus(mapSearch(giverName), moneyToGive);
      moneyToGive = moneyToGive - moneyToGive / person * person;
      add(mapSearch(giverName), moneyToGive);
   }
   
   struct map *temp = head;
   
   while(temp){
       fprintf(fout, "%s %d\n", temp->name, temp->money);
       temp = temp->next;
   }
   fclose(fin);
   fclose(fout);
}
