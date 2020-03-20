#include <stdio.h>
#include <stdlib.h>

int main()
{
    int L,i,j;
    double m[12][12],sum=0,avg=0;
    char T;
    scanf("%d",&L);
    scanf("%s",&T);
    for(i=0; i<12; i++)
    {
        for(j=0; j<12; j++)
        {
            scanf("%lf",&m[i][j]);
        }

    }
    i=0;
    switch(T)
    {
    case'S':
        for (i=0; i<12; i++)
        {
            sum=sum+m[L][i];
        }
        printf("%.1f\n",sum);
        break;
    case'M':
        for (i=0; i<12; i++)
        {
            sum=sum+m[L][i];
        }
        avg=sum/12;

        printf("%.1f\n",avg);
        break;
    }
    return 0;
}
