#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        float x[i][2];
        scanf("%f %f %f",&x[i][0],&x[i][1],&x[i][2]);
        printf("%.1f\n",((x[i][0]*2)+(x[i][1]*3)+(x[i][2]*5))/10);
    }

    return 0;
}
