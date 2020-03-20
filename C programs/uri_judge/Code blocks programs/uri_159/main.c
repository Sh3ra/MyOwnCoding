#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X,i,sum=0,z;
    scanf("%d",&X);
    while(X!=0)
    {
        if(X%2==0)
        {
            z=X;
        }
        else
            z=X+1;
        for (i=0; i<5; i++)
        {
            sum =sum + z;
            z=z+2;
        }
        printf("%d\n",sum);
        scanf("%d",&X);
        sum =0;

    }
    return 0;
}
