/*
ID: wangbn11
LANG: C
TASK: calfflac
*/
#include <stdio.h>
#include <string.h>
/* 从一个中心点开始向外增长，.bk中的方法，复杂度是20000*2000*2000，超时 */
int ispal(char *, int);

int main()
{
    FILE *fin = fopen("calfflac.in", "r");
    FILE *fout = fopen("calfflac.out", "w");
    char str[20001];
    char back[20001];
    int index[20001];
    int  i, j, k, smallindex, largeindex;
    i = j = k = 0;
    
    while(fscanf(fin, "%c", &back[j++]) > 0){
        if(back[j - 1] >= 'A' && back[j - 1] <= 'Z'){
            index[i] = j -1;
            str[i] = back[j - 1] - 'A' + 'a';
            i++;
        }
        else if(back[j - 1] >= 'a' && back[j - 1] <= 'z'){
            index[i] = j - 1;
            str[i] = back[j - 1];
            i++;
        }
    }
    str[i] = '\0';
    
    int max = 0;
    for(i = 0; i < j; i++){
        int temp;
        temp = ispal(str, i);
        if(temp > max){
            max = temp;
            if(max % 2 == 1){
                smallindex = i - max/2;
                largeindex = i + max/2;
            }
            else {
                smallindex = i - max/2 + 1;
                largeindex = i + max/2;
            }
        }
    }
    
    char re[2001];
    for(i = index[smallindex]; i <= index[largeindex]; i++)
        re[i-index[smallindex]] = back[i];
    re[i-index[smallindex]] = '\0';
    fprintf(fout, "%d\n%s\n", max, re);
    
    fclose(fin);
    fclose(fout);
}

int ispal(char *str, int mid)
{
    int oddsum, evensum, i, j;
    evensum = 0;
    oddsum = i = j = 1;
    
    while(str[mid - i] == str[mid + i] && mid - i >= 0 && i < 1000 && mid + i < strlen(str)){
        oddsum += 2;
        i++;
    }
    
    while(str[mid -j +1] == str[mid + j] && mid - j + 1 >= 0 && j <= 1000 && mid + j < strlen(str)){
        evensum += 2;
        j++;
    }
    
    return oddsum > evensum ? oddsum : evensum;
}
