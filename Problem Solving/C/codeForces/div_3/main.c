#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,k,a,b,p=0;
    scanf("%d",&t);
    for(int j=0;j<t;j++){
        scanf("%d %d %d",&a,&b,&k);
        p=0;
        if(k%2==0){
            p=(a-b)*k;
        }
        else p=(a-b)*k+a;
        printf("%d\n",p);
    }
    return 0;
}
