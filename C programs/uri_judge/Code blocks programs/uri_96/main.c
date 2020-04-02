#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n;
   n=7;
    for (i=1;i<=9;i=i+2){
        for (j=n;j>n-3;j--){
            printf("I=%d J=%d\n",i,j);
        }
        n=n+2;
    }
    return 0;
}
