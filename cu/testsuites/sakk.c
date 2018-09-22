#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int szam,i,j,b,a;
    printf("Milyen szeles legyen?");
    scanf("%d", &szam);

    for(i = 1; i<=8; i = i +1)
    {
        for(b = 1; szam>=b; b = b+1)
        {
            for(j = 1; j<=8; j = j+1)
            {
                if((i+j)%2 == 0)
                    for(a = 1; a<=szam; a = a+1)
                        printf("X");
                else
                    for(a = 1; a<=szam; a = a+1)
                        printf(".");
            }
            printf("\n");
        }
    }

    return 0;
}
