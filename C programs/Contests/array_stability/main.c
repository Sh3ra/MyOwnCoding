#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int minStab,i=0;
    int max,max2,min;
    for(i=0; i<n; i++)
    {
        if(i==0)
        {
            max=a[i];
            max2=a[i];
            min=a[i];
        }
        if(a[i]>max)
        {
            max2=max;
            max=a[i];
        }
        if(a[i]<min)
            min=a[i];
    }
    minStab=max2-min;
    printf("%d",minStab);


    return 0;
}
