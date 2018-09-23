#include <stdio.h>

void kirajzsakk(int sor, int oszlop, int mezo){
    int i=1;

    while(i<=sor){
        for(int l=0; l<mezo; l++){
            int j=1;
            while(j<=oszlop){
                for(int k=0; k<mezo; k++){
                    if(i%2==1){
                        if(j%2==1){
                            printf("X");
                        }else{
                            printf(".");
                        }
                    }else{
                        if(j%2==1){
                            printf(".");
                        }else{
                            printf("X");
                        }
                    }
                }
                j+=mezo;
            }
            printf("\n");
        }
        i+=mezo;
    }
}

int main()
{
    printf("Sakktabla program!\n");
    printf("Elso feladat (ismetles kikuszoboles)\n");
    kirajzsakk(16,16,1);
    printf("Masodik feladat (sajat meret)\n");
    printf("Add meg a tabla meretet: (pl.: 16) ");
    int meret;
    scanf("%d", &meret);
    printf("Add meg a mezok meretet: (pl.: 3)");
    int mezo;
    scanf("%d", &mezo);
    kirajzsakk(meret, meret, mezo);
    return 0;
}
