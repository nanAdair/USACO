/*
ID: wangbn11
LANG: C
TASK: contact
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct mark {
    int length;
    int value;
    int count;
};

int formNumber(int *record, int length);
void sortInsertion(struct mark *contact, int count);
void formString(int length, int value, char *output);

int main()
{
    FILE *fin = fopen("contact.in", "r");
    FILE *fout = fopen("contact.out", "w");
    int i, j, begin, end, top, record[200001], count, res[13][4096];
    fscanf(fin, "%d %d %d", &begin, &end, &top);
    
    char buffer[1024];
    count = 0;
    while (fscanf(fin, "%s", buffer) > 0) {
        for (i = 0; i < strlen(buffer); i++)
            record[count++] = buffer[i] - '0';
    }
    
    for (i = 0; i < count; i++) {
        for (j = begin; j <= end; j++) {
            if (i + j > count)
                break;
            int temp = formNumber(record+i, j);
            res[j][temp]++;
        }
    }
    
    struct mark contact[5000];
    count = 0;
    for (i = begin; i <= end; i++) {
        for (j = 0; j < 4096; j++) {
            if (res[i][j] != 0) {
                contact[count].length = i;
                contact[count].value = j;
                contact[count++].count = res[i][j];
            }
        }
    }
    
    sortInsertion(contact, count);
    
    int next, num;
    i = j = 0;
    next = 1;
    while (i < top && j < count) {
        if (next) {
            fprintf(fout, "%d\n", contact[j].count);
            next = 0;
            num = 0;
        }
        char output[13];
        formString(contact[j].length, contact[j].value, output);
        fprintf(fout, "%s", output);
        num++;
        if (contact[j+1].count != contact[j].count) {
            i++;
            next = 1;
            fprintf(fout, "\n");
        }else {
            if (num == 6) {
                fprintf(fout, "\n");
                num = 0;
            }else 
                fprintf(fout, " ");
        }
        j++;
    }
    
    fclose(fin);
    fclose(fout);
}

void sortInsertion(struct mark *contact, int limit)
{
    int i, j;
    for (i = 0; i < limit; i++) {
        int length, value, count;
        length = contact[i].length;
        value = contact[i].value;
        count = contact[i].count;
        for (j = i-1; j >= 0 && contact[j].count < count; j--) {
            contact[j+1].length = contact[j].length;
            contact[j+1].value = contact[j].value;
            contact[j+1].count = contact[j].count;
        }
        contact[j+1].length = length;
        contact[j+1].value = value;
        contact[j+1].count = count;
    }
}

void formString(int length, int value, char *output)
{
    int i, j, count;
    char temp[13];
    i = j = 0;
    while (value != 0) {
        temp[i++] = value % 2 + '0';
        value /= 2;
    }
    for (; i < length; i++)
        temp[i] = '0';
    output[length] = '\0';
    for (j = 0; j < length; j++)
        output[j] = temp[length-j-1];
}

int formNumber(int *record, int length)
{
    int i, sum;
    sum = 0;
    for (i = 0; i < length; i++) {
        sum += record[i] * pow(2, length-i-1);
    }
    return sum;
}
