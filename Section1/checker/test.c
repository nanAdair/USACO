#include <stdio.h>

int order(unsigned long);
void test(unsigned long, unsigned long, unsigned long, int);

int mark[14];
unsigned long upper;
int number;
int count = 0;
FILE *fin, *fout;

int main()
{
    fin = fopen("checker.in", "r");
    fout = fopen("checker.out", "w");
    fscanf(fin, "%d", &number);
    upper = (1 << number) - 1;
    
    test(0, 0, 0, 1);
    
    fprintf(fout, "%d\n", count);
    
    fclose(fin);
    fclose(fout);
}

void test(unsigned long row, unsigned long rp, unsigned long lp, int depth)
{
    if(row != upper){
        unsigned long pos, p;
        pos = upper & ~(row | rp | lp);
        while(pos != 0){
            p = pos & -pos;
            pos = pos - p;
            test(row+p, (rp+p) >> 1, (lp+p) << 1, depth+1);
        }
    }
    else{
        count++;
    }
}
