#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,x,j;
    scanf("%d %d",&x,&N);
    for(i=1;i<=N;){
        for (j=1;j<=x;j++){
            if (j==x)
                printf("%d",i);
            else
            printf("%d ",i);
            i++;
        }
        printf("\n");
        j=1;
    }
    return 0;
}
