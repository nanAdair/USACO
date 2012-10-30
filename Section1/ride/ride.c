/*
 ID: wangbn11
 LANG: C
 TASK: ride
 */

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");
    
    char comet[7];
    char group[7];
    
    fscanf(fin, "%s", comet);
    fscanf(fin, "%s", group);
    int mask;
    long com, grp;
    com = grp = 1;
    int i;
    for(i = 0; i<strlen(comet); i++)
        com *= comet[i] - 'A' + 1;
    for(i = 0; i<strlen(group); i++)
        grp *= group[i] - 'A' + 1;
    if(com % 47 == grp % 47)
        mask = 1;
    else 
        mask = 0;
    if(mask)
        fprintf(fout, "GO\n");
    else
        fprintf(fout, "STAY\n");
    
    fclose(fin);
    fclose(fout);
}
