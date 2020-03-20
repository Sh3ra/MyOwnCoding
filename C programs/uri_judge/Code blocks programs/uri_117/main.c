#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x,y;
    int X;
    x=y=0;
    while (X!=2){
    while (x==0){
        scanf("%lf",&x);
        if (x<0 || x>10){
                printf("nota invalida\n");
                x=0;
        }
    }
     while (y==0){
        scanf("%lf",&y);
        if (y<0 || y>10){
                printf("nota invalida\n");
                y=0;
        }
    }
    printf("media = %.2f\n",(x+y)/2.0);
scanf("%d",&X);
    while (X!=1 && X!=2){

            printf("novo calculo (1-sim 2-nao)\n");

 scanf("%d",&X);
    }
                printf("novo calculo (1-sim 2-nao)\n");
x=y=0;
    }
    return 0;
}
