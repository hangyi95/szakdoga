#include <stdio.h>

int main1()
{
    int m;
    printf("Kérem egy négyzet méretét: ");
    scanf("%d", &m);
    printf("\n");

    char c = 'X';
    for(int i = 1; i <= 8; i = i + 1) {
        for (int n = 1; n <= m; n = n + 1){
            for (int k = 1; k <= 8; k = k + 1){
                for(int j = 1; j <= m; j = j + 1){
                    printf("%c", c);
                }
                if(c == 'X')
                    c = '.';
                else
                    c = 'X';
            }
            printf("\n");
        }
        if(c == 'X')
            c = '.';
        else
            c = 'X';
    }

    return 0;
}
