#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I,i;
   I=1;
    for (i=60;i>=0;i=i-5){
        printf("I=%d J=%d\n",I,i);
        I=I+3;
    }

    return 0;
}
