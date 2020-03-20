#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,n,x[5];
   n=0;
   scanf("%d %d %d %d %d",&x[0],&x[1],&x[2],&x[3],&x[4]);
   for(i=0;i<5;i++){
    if (x[i]%2==0){
        n++;
    }
   }
   printf("%d valores pares\n",n);
    return 0;
}
