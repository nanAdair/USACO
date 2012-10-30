/*
ID: wangbn11
LANG: C
TASK: friday
*/
#include <stdio.h>
#include <stdlib.h>

int day[][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int dayOfYear[400] = {0};

int leapYear(int year);
int caculate(int year, int month);

int main()
{
    FILE *fin = fopen("friday.in", "r");
    FILE *fout = fopen("friday.out", "w");
    
    int i, number, j;
    int week[8] = {0};
    fscanf(fin, "%d", &number);
    for(i = 1900; i < 1900 + number; i++){
        for(j = 1; j < 13; j++){
            int c;
            c = caculate(i, j);
            week[c]++;
        }
    }
    for(i = 0; i < 7; i++){
        fprintf(fout, "%d", week[(i+6) % 7]);
        if( i != 6)
            fprintf(fout, " ");
    }
    fprintf(fout, "\n");
    fclose(fin);
    fclose(fout);
}

int leapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int caculate(int year, int month)
{
    int numberOfDay = 0;
    int leap;
    leap = leapYear(year);
    dayOfYear[year - 1900] = leap ? 366 : 365;
    
    int i;
    for(i = 0; i < year - 1900; i++)
        numberOfDay += dayOfYear[i];
    for(i = 1; i < month; i++)
        numberOfDay += day[leap][i];
    return (numberOfDay + 13) % 7;
}
