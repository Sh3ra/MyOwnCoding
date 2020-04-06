#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(t=t;t>0;t--){
       int min,x,min2=1001,a[10];
       for(int i=0;i<10;i++){
            scanf("%d",&a[i]);
            if(i==0)min=a[i];
       if(min>=a[i]){
        min=a[i];
        x=i;
       }
       }
        for(int i=0;i<10;i++){
        if(i!=x)
         {if(i==0)min2=a[i];
       if(min2>=a[i]){
        min2=a[i];

       }}


        }
       printf("%d\n",min2);
           }
    return 0;
}
