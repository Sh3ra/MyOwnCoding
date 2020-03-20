#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        int x[i];
        scanf ("%d",&x[i]);
        if (x[i]>0 && x[i]%2==0){
            printf("EVEN POSITIVE\n");
        }
        else if(x[i]>0 && x[i]%2!=0){
            printf("ODD POSITIVE\n");
        }
        else if(x[i]<0 && x[i]%2==0){
            printf("EVEN NEGATIVE\n");
        }
        else if(x[i]<0 && x[i]%2!=0){
            printf("ODD NEGATIVE\n");
        }
        else {printf("NULL\n");}
    }
    return 0;
}
