#include <stdio.h>
#include <stdlib.h>

int main()
{
    char O[2];
    double sum=0.0,M[12][12];
    int i,j,x=11;
    scanf("%s",&O);
    for(i=0;i<=11;i++){
        for(j=0;j<=11;j++){
            scanf("%lf",&M[i][j]);
        }
    }
    for(i=0;i<=11;i++){
        for(j=x+1;j<=11;j++){
            sum=sum+M[i][j];
        }
        x=x-1;
    }
    if(O[0]=='S')
        printf("%.1lf\n",sum);
    else if (O[0]=='M')
        printf("%.1lf\n",sum/66.0);

    return 0;
}
