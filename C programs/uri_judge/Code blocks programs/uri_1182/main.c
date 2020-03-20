#include <stdio.h>
#include <stdlib.h>

int main()
{
    int C,i,j;
    char a[2];
    double M[12][12],sum=0.0;
    scanf("%d",&C);
    scanf("%s",&a);
    for(i=0; i<=11; i++)
    {
        for(j=0; j<=11; j++)
        {
            scanf("%lf",&M[i][j]);
            if (j==C)
                sum=sum+M[i][j];
        }
    }
    if(a[0]=='S')
    {

        printf("\n%.1lf\n",sum);
    }
        else if(a[0]=='M') {

        printf("%.1lf\n",sum/12.0);

    }

    return 0;
}
