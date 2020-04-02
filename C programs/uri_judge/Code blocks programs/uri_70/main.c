#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    scanf("%d",&n);
    if (n%2==0){
        n=n+1;
        for (i=0;i<11;i=i+2){
            printf("%d\n",n+i);
        }
    }
    else {for (i=0;i<11;i=i+2){
            printf("%d\n",n+i);
        }
        }
    return 0;
}
