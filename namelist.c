#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAMELENGTH 25
typedef  char Name[NAMELENGTH];
void cleanline() 
{ for (int ch = 0; (ch != EOF) && (ch != '\n'); ch = fgetc(stdin)); }
void makenamelist(int k)
    {int n ;
    n=k;


Name* namelst = ((Name*)malloc(n * NAMELENGTH));

cleanline();
    
for (int i = 0; i < n; i++) {
    printf("Name %d : ", i);
    fgets(namelst[i], NAMELENGTH , stdin);
}

    }