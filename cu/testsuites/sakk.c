#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, k, l , f, z, h;
    int n;
    printf("Meret: ");
    scanf("%d", &n);

    if(n%2 != 0)
    {
        for( l=0; l<2; l= l+1)
        {
           for( f = 0; f<n; f=f+1)
           {
            printf("xx");
            printf("..");
           }
           printf("\n");
        }
    }

    for( i=0; i<(n/2); i=i+1)
    {
       int seged = 0;

        if(seged != 2)
        {


        for( j=0; j<2; j=j+1)
        {
           if(seged != 2)

              for( z=0; z<n; z=z+1)
              {
                  printf("..");
                  printf("xx");
              }
              seged = seged+1;
              printf("\n");

        }


        }
           if(seged == 2)
           {
              seged = 0;
                for( k=0; k<2; k=k+1)
                {
                    if(seged != 2)
                    {
                        for( h=0; h<n; h=h+1)
                        {
                            printf("xx");
                            printf("..");
                        }
                        seged = seged+1;
                        printf("\n");
                    }
                }

           }


    }


    return 0;
}