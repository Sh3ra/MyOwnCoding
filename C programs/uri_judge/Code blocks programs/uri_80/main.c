#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[100],p,m,i,j;
   p=m=0;
    for (i=0;i<100;i++){
        scanf("%d",&x[i]);
    }
    for (i=0;i<100;i++){
        for (j=0;j<100;j++){
            if (x[i]>x[j] && x[i]>m){
                m=x[i];
                p=i+1;
            }
        }
    }
    printf("%d\n%d\n",m,p);
    return 0;
}
