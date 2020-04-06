#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,x;
    scanf("%d",&t);
    for(t=t; t>0; t--)
    {
        scanf("%d",&x);
        int n=(x*10)+1;
        char a[n];
        scanf(" %[^\t\n]s",&a);
        int i=0,checka=0,checke=0,begin=-1,end=0;
        while(a[i]!='\0')
        {
            if(a[i]=='#')
                checka=1;
            if(a[i]>=97 && a[i]<=122)
            {
                if (begin==-1)
                    begin=i;
                else
                    end =i;
                checke=1;
            }
            if(end==0)
                end =begin;
            i++;
        }
        if(checka==1 && checke==1)
        {
            int j;
            for(j=(end+1); j<i; j++)
            {
                if(j==(end+1)&& a[j]==' ')
                    j=j;
                else
                    printf("%c",a[j]);
                if(j==i-1)
                    printf(" ");
            }
            if(begin==0)
            {
                for(j=begin; j<=end; j++)
                {
                    printf("%c",a[j]);
                }
            }
            else
            {
                for(j=begin; j<=end; j++)
                {
                    printf("%c",a[j]);
                }

                for(j=0; j<=(begin-2); j++)
                {
                    if (j==0)
                        printf(" ");
                    printf("%c",a[j]);
                }
            }
            printf("\n");

        }
        else
        {
            printf("%s\n",a);
        }
    }
    return 0;
}
