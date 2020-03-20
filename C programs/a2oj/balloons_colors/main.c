#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(t=t; t>0; t--)
    {
        int n,x,y,z,w,check1=0,check2=0;

        scanf("%d %d %d",&n,&x,&y);
        w=n;
        check1=0;
        check2=0;
        while(n!=0)
        {

            scanf("%d",&z);
            if(n==w)
            {
                if(z==x)
                {
                    check1=1;
                }
            }
            else if(n==1)
            {
                if(z==y)
                {
                    check2=1;
                }
            }
            n--;
        }
        if(check1&&check2)
        {
            printf("BOTH\n");
        }
        else if  (check1==1)
        {
            printf("EASY\n");
        }
        else if (check2==1)
        {
            printf("HARD\n");
        }
        else
            printf("OKAY\n");

    }
    return 0;
}
