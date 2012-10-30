#include <stdio.h>

void rotate90(char s[][10])
{
    char temp[10][10];
    int i, j;
    int number = 3;
    for(i = 0; i < number; i++){
        printf("---\n");
        for(j = 0; j < number; j++){
            printf("%c ", s[i][j]);
            temp[i][j] = s[i][j];
        }
        printf("\n");
    }
    
    for(i = 0; i < number; i++){
        for(j = 0; j < number; j++){
            s[i][j] = temp[number - j - 1][i];
        }
    }
}

int main()
{
    char test[][10] = {
        "123",
        "456",
        "789"
    };
    
    rotate90(test);
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%c ", test[i][j]);
        }
        printf("\n");
    }
}
