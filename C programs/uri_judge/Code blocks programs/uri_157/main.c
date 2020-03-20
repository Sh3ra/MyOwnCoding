#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,x,y,j,sum=0,z;
    scanf("%d",&N);
    for(i=0; i<N; i++)
    {
        scanf("%d %d",&x,&y);
        if (x%2==0)
        {
            z=x+1;
        }

        else
        {
            z=x;
        }
        for (j=0; j<y; j++)
        {
            sum=sum+z;
            z=z+2;
        }
        printf("%d\n",sum);
        sum =0;

    }

    return 0;
}
