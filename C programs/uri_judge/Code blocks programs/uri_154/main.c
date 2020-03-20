#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    float s=0;
    for (i=1,j=1;i<=39;i+=2,j*=2){
        s=s+(i/(j*1.0));
    }
    printf("%.2f\n",s);
    return 0;
}
