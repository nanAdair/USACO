/*
ID: wangbn11
LANG: C
TASK: preface
*/
#include <stdio.h>
#include <string.h>

char *sign[4][10] = {
    "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
    "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
    "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
    "", "M", "MM", "MMM", "  ", " ", "  ", "   ", "    ", "  "
};

struct comp {
    char c;
    int count;
};

struct comp output[7] = {
    'I', 0,
    'V', 0,
    'X', 0,
    'L', 0,
    'C', 0,
    'D', 0,
    'M', 0
};

void manage(int);
void add(int, int);

int main()
{
    FILE *fin = fopen("preface.in", "r");
    FILE *fout = fopen("preface.out", "w");
    int number, i;
    fscanf(fin, "%d", &number);
    
    for (i = 1; i <= number; i++)
        manage(i);
    
    for (i = 0; i < 7; i++) {
        if (output[i].count != 0)
            fprintf(fout, "%c %d\n", output[i].c, output[i].count);
    }
    
    fclose(fin);
    fclose(fout);
}

void manage(int num)
{
    int depth, digit;
    depth = 0;
    
    while (num) {
        digit = num % 10;
        add(digit, depth);
        depth += 1;
        num /= 10;
    }
}

void add(int digit, int depth)
{
    char *temp;
    temp = sign[depth][digit];
    int i, j;
    
    for (i = 0; i < strlen(temp); i++) {
        for (j = 0; j < 7; j++) {
            if (output[j].c == temp[i]) {
                output[j].count++;
                break;
            }
        }
    }
}
