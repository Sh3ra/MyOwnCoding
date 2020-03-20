#include <stdio.h>
#include <stdlib.h>

int main()
{
   int N,i;
   scanf("%d",&N);
   if (N%2==0){
   for(i=2;i<=N;i=i+2){
    printf("%d^2 = %d\n",i,i*i);
   }

   }
   else {
    for(i=2;i<N;i=i+2){
    printf("%d^2 = %d\n",i,i*i);
   }
   }
    return 0;
}
