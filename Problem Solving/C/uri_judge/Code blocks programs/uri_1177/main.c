#include <stdio.h>
#include <stdlib.h>

 int main()
{
   int i;
   double N[100],x;
   scanf("%lf",&x);
   N[0]=x;
   for (i=1;i<100;i++){
    x=x/2;
    N[i]=x;
   }
   for(i=0;i<100;i++){
    printf("N[%d] = %.4lf\n",i,N[i]);
   }
    return 0;
}

