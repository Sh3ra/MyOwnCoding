#include <stdio.h>
#include <stdlib.h>

 int main()
{
   int N[1000],t,i=0,j;
   scanf("%d",&t);
   while (i<1000){
    for (j=0;j<=t-1;j++){
        N[i]=j;
        i++;
    }
    j=0;
   }
   for(i=0;i<1000;i++){
    printf("N[%d] = %d\n",i,N[i]);
   }
    return 0;
}

