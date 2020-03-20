#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,T,PA,PB,y=0,g1,g2;
    double G1,G2;
    scanf("%d",&T);
    for(i=0; i<T; i++)
    {
        scanf("%d %d %lf %lf",&PA,&PB,&G1,&G2);
        y=0;
        while(PB>=PA)
        {
            g1=PA*(G1/100);
            g2=PB*(G2/100);
            PA=PA+g1;
            PB=PB+g2;
            y++;
        }
        if (y>100)
            printf("Mais de 1 seculo.\n");
        else printf("%d anos.\n",y);
    }

    return 0;
}
