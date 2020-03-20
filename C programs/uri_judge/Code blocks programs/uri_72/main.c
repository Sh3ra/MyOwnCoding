#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,in,out;
    in=out=0;
    scanf("%d",&N);

    for (i=0;i<N;i++){
    int x[i];
    scanf("%d",&x[i]);
   if (x[i]>=10 && x[i]<=20){
    in++;
   }
   else {
    out++;
   }
    }
    printf("%d in\n",in);
    printf("%d out\n",out);

    return 0;
}
