/*
ID: wangbn11
LANG: C
TASK: shopping
*/
/* 
 * dfs最多过9个点
 * */
#include <stdio.h>

struct special {
    int code[5];
    int count[5];
    int price;
    int number;
};
int numberOfSpecial;      //优惠种类的个数
int product[1000];        //记录商品号下商品需要的数量
int code[5];             //5种内需要的商品号
int price[1000];          //每种商品号的商品的单价
int countNow[1000];       //记录当前商品的数量
int priceNow;           //记录当前的价钱
int res;                //最后结果
int purchase;            //要购买的商品种类数

int main()
{
    FILE *fin = fopen("shopping.in", "r");
    FILE *fout = fopen("shopping.out", "w");
    struct special offers[100];
    int i, j, k, m, n;
    fscanf(fin, "%d", &numberOfSpecial);
    for (i = 0; i < numberOfSpecial; i++) {
        fscanf(fin, "%d", &offers[i].number);
        for (j = 0; j < offers[i].number; j++) {
            fscanf(fin, "%d %d", &offers[i].code[j], &offers[i].count[j]);
        }
        fscanf(fin, "%d", &offers[i].price);
    }
    
    int limit;
    limit = 0;
    fscanf(fin, "%d", &purchase);
    for (i = 0; i < purchase; i++) {
        int a, b, c;
        fscanf(fin, "%d %d %d", &a, &b, &c);
        code[i] = a;
        product[a] = b;
        price[a] = c;
        limit += b * c;
    }
    for (i = purchase; i < 6; i++)
        code[i] = 0;
    res = limit;
    
    int f[6][6][6][6][6];
    f[0][0][0][0][0] = 0;
    
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            for (k = 0; k < 6; k++) {
                for (m = 0; m < 6; m++) {
                    for (n = 0; n < 6; n++) {
                        
                    }
                }
            }
        }
    }
    
    fprintf(fout, "%d\n", res);
    
    fclose(fin);
    fclose(fout);
}
