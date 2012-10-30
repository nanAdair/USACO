#include <stdio.h>

int main()
{
    int a = 11;
    printf("%d\n", a & 0x1);
    printf("%d\n", a & 0x2);
    printf("%d\n", a & 0x4);
    printf("%d\n", a & 0x8);
    printf("%d\n", (a & 0x4) == 0);
}
