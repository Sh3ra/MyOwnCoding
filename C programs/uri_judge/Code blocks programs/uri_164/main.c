#include<stdio.h>


void main()
{
    int N,i,x=1,y=0,z=0;
    scanf("%d",&N);
    for(i=0; i<N; i++)
    {

        printf("%d ",x);
        z=x;
        x=x+y;
        y=z;


    }

    return 0;
}
