#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i;
    N=100000000000;
    for(i=0;i<N;i++){
        int x[i][2];
        scanf("%d %d",&x[i][0],&x[i][1]);
        if (x[i][0]>0 && x[i][1]>0 &&x[i][0]<x[i][1]){
            int j,sum;
            sum=0;
            for (j=x[i][0];j<=x[i][1];j++){
                sum=sum+j;
                printf("%d ",j);
            }
            printf("Sum=%d\n",sum);
        }
        else if (x[i][0]>0 && x[i][1]>0 &&x[i][0]>x[i][1]){
            int j,sum;
            sum=0;
            for (j=x[i][1];j<=x[i][0];j++){
                sum=sum+j;
                printf("%d ",j);
            }
            printf("Sum=%d\n",sum);
        }
        else {
            i=N;
        }
    }
    return 0;
}
