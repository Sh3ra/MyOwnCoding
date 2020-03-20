#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X,Y;
    int N,i;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d %d",&X,&Y);
        if (Y==0)
            printf("divisao impossivel\n");

        else{
            printf("%.1f\n",X/(Y*1.0));
        }
    }
    return 0;
}
