#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,w;
    scanf("%d",&t);
    for(w=0; w<t; w++)
    {
        char a[1010],l=123;
        int max=1;
        scanf(" %[^\t\n]s",&a);
        int i=0,count2=0;
        max=0;
        while(a[i]!='\0')
        {

            int j=0,count=0;

            while(a[j]!='\0')
            {
                if(a[i]==a[j])
                {
                    count++;
                }
                j++;
            }
            if(max==count && l!=a[i])
            {
                j=0;
                while(a[j]!='\0')
                {
                    int x=0;
                    count2=0;
                    while(a[x]!='\0')
                    {
                        if(a[j]==a[x])
                        {
                            count2++;
                        }
                        x++;
                        if(l>=a[j] && count2==max)
                        {
                            l=a[j];
                        }}
                        j++;
                    }

            }
            else if(max<count)
            {
                max=count;
                l=a[i];
            }

            i++;
        }
        printf("%d %c\n",max,l);
    }

    return 0;
}
