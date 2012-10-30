#include <stdio.h>
#include <string.h>

int isPal(char *form);
int main()
{
    char *form = "1";
    printf("%d\n", isPal(form));
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
