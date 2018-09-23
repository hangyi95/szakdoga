#include<stdio.h>

int main(void){

     int i,j,n,k,f;
     double *p;
     printf("Mekkora legyen egy mezo merete? ");
     scanf("%d", &n);
     printf("\n");
     for(f=0;f<4;f+=1)
            {
          for(i=0;i<n;i+=1)
              {
		    for(j=0;j<4;j=j+1)
		    {
			for(k=0;k<n;k+=1)
			    printf("X");
			    p=malloc(1024*1024*10);
			for(k=0;k<n;k+=1)
			    printf(".");
		    }
		  printf("\n");
	           }
	for(i=0;i<n;i+=1)
         {
		for(j=0;j<4;j=j+1)
		{
			for(k=0;k<n;k+=1)
			    printf(".");
			for(k=0;k<n;k+=1)
			    printf("X");
		}
		  printf("\n");
	     }
             }
return 0;

}
