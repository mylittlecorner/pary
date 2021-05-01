#include <stdio.h>
#include "zrodlo.h"

int main()
{
    char** result=odczyt("pary.txt");
    //char** result2=liczby(result);
    char** result3=znaki(result);
        int i;
        for(i=0;i<100;i++)
        {
            printf("%s",result3[i]);
        }

    return 0;
}




