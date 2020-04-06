#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned x,a,g,d;
    a=g=d=0;
printf("MUITO OBRIGADO\n");
    do
    {
        scanf("%d",&x);

        switch(x)
        {
        case 1:
            a=a+1;
            break;
        case 2:
            g=g+1;
            break;
        case 3:
            d=d+1;
            break;
        }

    }
    while (x!=4);
        printf("Alcool: %d\n",a);
    printf("Gasolina: %d\n",g);
    printf("Diesel: %d\n",d);
    return 0;
}
