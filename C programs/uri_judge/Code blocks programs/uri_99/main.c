#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,j,sum=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
    int x[i][2];
    scanf("%d %d",&x[i][0],&x[i][1]);
    if (x[i][0]<x[i][1] && x[i][0]%2==0){
        sum=0;
        for (j=x[i][0]+1;j<x[i][1];j=j+2){

            sum=sum +j;
        }
        printf("%d\n",sum);
    }
    else if (x[i][0]<x[i][1] && x[i][0]%2!=0){
        sum=0;
        for (j=x[i][0]+2;j<x[i][1];j=j+2){

            sum=sum +j;
        }
        printf("%d\n",sum);
    }
    else if (x[i][0]>x[i][1] && x[i][1]%2==0){
        sum=0;
        for (j=x[i][1]+1;j<x[i][0];j=j+2){

            sum=sum +j;
        }
        printf("%d\n",sum);
    }
    else if (x[i][0]>x[i][1] && x[i][1]%2!=0){
        sum=0;
        for (j=x[i][1]+2;j<x[i][0];j=j+2){

            sum=sum +j;
        }
        printf("%d\n",sum);
    }
    else {printf("0\n");}
    }
    return 0;
}
