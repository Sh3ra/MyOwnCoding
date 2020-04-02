#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,M,K,L,x=1;
    scanf("%d %d %d %d",&N,&M,&K,&L);
    if(K<1 || M<1 || N<1 || N>1000000000000000000 || L>1000000000000000000 || K>N || M>N || (L+K)>N)
    {
        printf("-1");
        return 0;
    }

    while(((x*M)-K)<L){

        x++;
    }


        printf("%d",x);


    return 0;
}
