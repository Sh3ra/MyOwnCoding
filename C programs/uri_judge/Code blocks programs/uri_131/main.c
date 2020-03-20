#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I,G,x=1,wI=0,wG=0,D=0,i=0;
 do {
    scanf("%d %d",&I,&G);
   if (I>G){
    wI++;
   }
   else if (G>I)wG++;
   else {D++;}
    printf("Novo grenal (1-sim 2-nao)\n");
    scanf("%d",&x);


       i++;
    } while (x==1);
   printf("%d grenais\n",i);
   printf("Inter:%d\n",wI);
       printf("Gremio:%d\n",wG);
       printf("Empates:%d\n",D);
       if (wI>wG)
        printf("Inter venceu mais\n");
       else if (wG>wI)
        printf("Gremio venceu mais\n");
       else
        printf("Não houve vencedor\n");


    return 0;
}
