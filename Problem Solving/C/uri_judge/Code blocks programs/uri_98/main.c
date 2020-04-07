#include <stdio.h>
#include <stdlib.h>

int main()
{
    double I,J;
    I=0;
    J=1;
    int i,j,x;
    x=0; j=1;
    for(i=0;i<11;i++){
        if (x==2){
            printf("I=%d J=%d\n",x,j);
                printf("I=%d J=%d\n",x,j+1);
                printf("I=%d J=%d\n",x,j+2);
        }
        else if (x!=I && j!=J)
        {
                printf("I=%.1f J=%.1f\n",I,J);
                printf("I=%.1f J=%.1f\n",I,J+1);
                printf("I=%.1f J=%.1f\n",I,J+2);

        }
        else {
                x=I; j=J;
                printf("I=%d J=%d\n",x,j);
                printf("I=%d J=%d\n",x,j+1);
                printf("I=%d J=%d\n",x,j+2);

        }
I=I+0.2;
                J=J+0.2;
                x=I+0.2;
                j=J+0.2;
    }
    return 0;
}
