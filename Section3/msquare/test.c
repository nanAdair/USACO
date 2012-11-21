#include <stdio.h>

int encode(int x, int y);
int main()
{
    int res;
    res = encode(1234, 5687);
    printf("%d\n", res);
}
int encode(int x, int y)
{
    int mul[7] = {5040, 720, 120, 24, 6, 2, 1};
    int number[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int digit[8], i;
    i = 0;
    while (y) {
        digit[i++] = y % 10;
        y /= 10;
    }
    while (x) {
        digit[i++] = x % 10;
        x /= 10;
    }
    
    int res = 0;
    for (i = 7; i > 0; i--) {
        int small, j;
        small = 0;
        for (j = 1; j < digit[i]; j++) {
            if (number[j] == 0)
                small++;
        }
        res += small * mul[7 - i];
        number[digit[i]] = 1;
    }
    return res;
}
