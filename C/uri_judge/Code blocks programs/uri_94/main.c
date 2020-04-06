#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,t,f,r,rat;
    scanf("%d",&N);
    t=f=r=rat=0;
    for (i=0;i<N;i++){
        int x[i];
        char c;
        scanf("%d %c",&x[i],&c);
        t=t+x[i];
        switch (c){
        case 'C':r=r+x[i];
        break;
        case 'R':rat=rat+x[i];
        break;
        case 'S':f=f+x[i];
        break;
               }
    }
    float R,F,T,RAT;
    R=r;
    T=t;
    F=f;
    RAT=rat;

    printf("Total: %d cobaias\n",t);
    printf("Total de coelhos: %d\n",r);
    printf("Total de ratos: %d\n",rat);
    printf("Total de sapos: %d\n",f);
    printf("Percentual de coelhos: %.2f %%\n",(R/T)*100);
   printf("Percentual de ratos: %.2f %%\n",(RAT/T)*100);
     printf("Percentual de sapos: %.2f %%\n",(F/T)*100);
    return 0;
}
