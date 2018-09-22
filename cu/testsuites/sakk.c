#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Adjon meg egy szelesseget: ");
    int width,i,j,k,l;
    scanf("%d", &width);
    bool black = true;
    for(i=0;i<8;i++){
        for(j=0;j<width;j++){
            for( k=0;k<8;k++){
                for( l=0;l<width;l++){
                    if(black)
                        printf("X");
                    else
                        printf(".");
                }
                black = !black;
            }
            printf("\n");
        }
        black = !black;
    }
    return 0;
}
