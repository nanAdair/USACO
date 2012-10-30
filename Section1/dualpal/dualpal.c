/*
ID: wangbn11
LANG: C
TASK: dualpal
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *change(int number, int base);
void tranverse(char *);
int isPal(char *);

int main()
{
    FILE *fin = fopen("dualpal.in", "r");
    FILE *fout = fopen("dualpal.out", "w");
    int number, s;
    fscanf(fin, "%d %d", &number, &s);
    
    int base, count;
    count = 0;
    while(count < number){
        s++;
        int countPal = 0;
        for(base = 2; base <= 10; base++){
            char *form;
            form = change(s, base);
            if(isPal(form))
                countPal++;
        }
        if(countPal >= 2){
            fprintf(fout, "%d\n", s);
            count++;
        }
    }
    
    fclose(fin);
    fclose(fout);
}

char *change(int number, int base)
{
    char *form;
    form = (char *)malloc(20 * sizeof(char));
    
    int i = 0;
    do{
        int c;
        if(number % base < 10)
            form[i++] = number % base + '0';
        else
            form[i++] = number % base - 10 + 'A';
    }while(number /= base);
    
    form[i] = '\0';
    tranverse(form);
    return form;
}

void tranverse(char *form)
{
    char temp[20];
    int i, len;
    len = strlen(form);
    
    for(i = 0; i < len; i++)
        temp[i] = form[i];
    for(i = 0; i < len; i++)
        form[i] = temp[len - 1 - i];
}

int isPal(char *form)
{
    int i, j;
    i = 0;
    j = strlen(form) - 1;
    while(i < j){
        if(form[i] != form[j])
            break;
        i++;
        j--;
    }
    if(i < j)
        return 0;
    else
        return 1;
}
