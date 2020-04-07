#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[5],i,e,o,p,g;
    e=o=p=g=0;
    scanf("%d %d %d %d %d",&n[0],&n[1],&n[2],&n[3],&n[4]);
    for(i=0;i<5;i++){
        if(n[i]%2==0){
      e++;
        }
        else {
      o++;
        }
    }
    printf("%d valor(es) par(es)\n",e);
    printf("%d valor(es) impar(es)\n",o);

    for(i=0;i<5;i++){
        if(n[i]>0){
            p++;
        }
        else if (n[i]<0){
            g++;
        }
    }
    printf("%d valor(es) positivo(s)\n",p);
    printf("%d valor(es) negativo(s)\n",g);
    return 0;
}
