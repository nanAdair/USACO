#include <stdio.h>

struct test {
    int a;
    int b;
};

int main()
{
    struct test aa[44];
    int i, number;
    i = 0;
    number = 30;
    for(i = 0; i < number; i++){
        aa[i].a = 1;
        aa[i].b = 2;
    }
    struct test *c;
    c = aa;
    
    printf("%d %d %d\n", sizeof(c), sizeof(struct test), sizeof(aa) / sizeof(struct test));
}
