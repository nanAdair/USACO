/*
ID: wangbn11
LANG: C
TASK: crypt1
*/
#include <stdio.h>

int lessT(int *, int);
int lessW(int *, int);

int main()
{
    FILE *fin = fopen("crypt1.in", "r");
    FILE *fout = fopen("crypt1.out", "w");
    int number[10] = {0};
    int count, i;
    fscanf(fin, "%d", &count);
    int digit[10];
    for(i = 0; i < count; i++){
        fscanf(fin, "%d", &digit[i]);
        number[digit[i]] = 1;
    }
    
    //for(i = 0; i < 10; i++)
     //   printf("%d is: %d\n", i, number[i]);
    
    int mulTop, mulDown, sol;
    int j, k, p, q;
    sol = 0;
    for(i = 0; i < count; i++){
        for(j = 0; j < count; j++){
            for(k = 0; k < count; k++){
                mulTop = digit[i]*100 + digit[j]*10 + digit[k];
                for(p = 0; p < count; p++){
                    for(q = 0; q < count; q++){
                        mulDown = digit[p]*10 + digit[q];
                        int pro1, pro2, re;
                        pro1 = mulTop * digit[q];
                        pro2 = mulTop * digit[p];
                        re = pro2 * 10 + pro1;
                        if(lessT(number, pro1) && lessT(number, pro2) && lessW(number, re)){
      //                      printf("%d %d\n", mulTop, mulDown);
                            sol++;
                        }
                    }
                }
            }
        }
    }
    
    fprintf(fout, "%d\n", sol);
    fclose(fin);
    fclose(fout);
}

int lessT(int *number, int pro)
{
    if(pro >= 1000)
        return 0;
    while(pro){
        if(number[pro % 10] == 0)
            return 0;
        pro /= 10;
    }
    return 1;
}

int lessW(int *number, int pro)
{
    if(pro >= 10000)
        return 0;
    while(pro){
        if(number[pro % 10] == 0)
            return 0;
        pro /= 10;
    }
    return 1;
}


