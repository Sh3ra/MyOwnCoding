#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,i,o,min;
    scanf("%d %d",&n1,&n2);
    o=0;
    if (n1<n2){
        min=n1;
      if (n1%2==0){
    for(i=n1+1;i<n2;i=i+2){
       o=o+i;
    }
    printf("%d\n",o);
    }
    else {
        for(i=n1+2;i<n2;i=i+2){
       o=o+i;
    }
    printf("%d\n",o);
    }
    }
    else{
        min=n2;
      if (n2%2==0){
    for(i=n2+1;i<n1;i=i+2){
       o=o+i;
    }
    printf("%d\n",o);
    }
    else {
        for(i=n2+2;i<n1;i=i+2){
       o=o+i;
    }
    printf("%d\n",o);
    }
    }

    return 0;
}
