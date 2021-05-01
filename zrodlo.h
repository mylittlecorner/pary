#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char* string;

char** odczyt(string nazwa)
{
    char** zawartosc=malloc(100*sizeof(char*));
    char buffer[50];
    int i=0;
    FILE *fp;
    fp=fopen(nazwa,"r");
    while(fgets(buffer,50,fp) != NULL )
    {
			zawartosc[i]=malloc(strlen(buffer)*sizeof(char));
			strcpy(zawartosc[i],buffer);
			memset(buffer, 0, 50);
    	i++;
    }
    fclose(fp);
  return zawartosc;
}

char** liczby(char** zawartosc)
{
    int i;
    int j=0;
    char** cyfry=malloc(100*sizeof(char*));
    char buff[50];
    for(i=0;i<100;i++)
    {
        while(zawartosc[i][j]!=' ')
        {
            buff[j]=zawartosc[i][j];
            j++;

        }
    cyfry[i]=malloc((strlen(buff)+1)*sizeof(char));
    strcpy(cyfry[i],buff);
    memset(buff, 0, 50);
    j=0;
    }

    return cyfry;
}

char** znaki(char** zawartosc)
{
    int i;
    bool trigger=false;
    int j=0;
    int k=0;
    char** tablicaznakow=malloc(100*sizeof(char*));
    char buffer[50];

    for(i=0;i<100;i++)
    {
        do
        {
            if(trigger)
            {
                buffer[k++]=zawartosc[i][j];
            }
	     if(zawartosc[i][j]==' ')
            {
                trigger=true;
            }
          j++;
        }while(zawartosc[i][j] != '\0');
    tablicaznakow[i]=malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(tablicaznakow[i],buffer);
    memset(buffer, 0, 50);
    j=0;
    k=0;
    trigger=false;
    }

    return tablicaznakow;
}
