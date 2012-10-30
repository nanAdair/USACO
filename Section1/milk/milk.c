/*
ID: wangbn
LANG: C
TASK: milk
*/
#include <stdio.h>

struct farmer {
    int price;
    int amount;
};

void insertionSort(struct farmer[], int number);

int main()
{
    FILE *fin = fopen("milk.in", "r");
    FILE *fout = fopen("milk.out", "w");
    
    int amount, number;
    fscanf(fin, "%d %d", &amount, &number);
    
    struct farmer person[5001];
    int i;
    for(i = 0; i < number; i++){
        fscanf(fin, "%d %d", &person[i].price, &person[i].amount);
    }
    
    insertionSort(person, number);
    
    int total = 0;
    int money = 0;
    i = 0;
    while(total < amount){
        total += person[i].amount;
        money += person[i].price * person[i].amount;
        i++;
    }
    
    money -= person[i - 1].price * (total - amount);
    fprintf(fout, "%d\n", money);
    
    fclose(fin);
    fclose(fout);
}

void insertionSort(struct farmer *person, int number)
{
    int i, j;
    for(i = 0; i < number; i++){
        int price, amount;
        price = person[i].price;
        amount = person[i].amount;
        for(j = i -1; j >= 0 && person[j].price > price; j--){
            person[j+1].price = person[j].price;
            person[j+1].amount = person[j].amount;
        }
        person[j+1].price = price;
        person[j+1].amount = amount;
    }
}
