#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,k,sum=0;
    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%d %d",&n,&k);
        int x;
        t--;
        sum=0;
        while(n!=0)
        {
            scanf("%d",&x);
            sum=sum+x/k;

            n--;
        }
        printf("%d\n",sum);
    }


    return 0;
}
