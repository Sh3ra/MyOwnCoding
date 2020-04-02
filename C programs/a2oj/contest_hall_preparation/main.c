#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(t=t; t>0; t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int a[n][m];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int x[1000]= {0},w=0,count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(j+1!=m&& a[i][j]!=-1)
                {
                    int check=0;
                    for(int y=0; y<w; y++)
                    {
                        if(a[i][j]==x[y])
                            check=1;
                    }
                    if(a[i][j]==a[i][j+1]&&!check)
                    {
                        count++;
                        x[w]=a[i][j];
                        w++;
                    }

                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j+1!=n&& a[j][i]!=-1)
                {
                    int check=0;
                    for(int y=0; y<w; y++)
                    {
                        if(a[j][i]==x[y])
                            check=1;
                    }
                    if(a[j][i]==a[j+1][i]&&!check)
                    {
                        count++;
                        x[w]=a[j][i];
                        w++;
                    }

                }
            }
        }
        if(n>=2&&m>=2)
        {
            for(int i=0; i<n-1; i++)
            {
                for(int j=0; j<m-1; j++)
                {
                   if(a[i][j]!=-1){
                    int check=0;
                    for(int y=0; y<w; y++)
                    {
                        if(a[i][j]==x[y])
                            check=1;
                    }
                    if(a[i][j]==a[i+1][j+1]&&!check)
                    {
                        count++;
                        x[w]=a[i][j];
                        w++;
                    }
                   }
                }
            }
            for(int i=n-1; i>0; i--)
            {
                for(int j=m-1; j>0; j--)
                {
                    if(a[i][j]!=-1){
                    int check=0;
                    for(int y=0; y<w; y++)
                    {
                        if(a[i][j]==x[y])
                            check=1;
                    }
                    if(a[i][j]==a[i-1][j-1]&&!check)
                    {
                        count++;
                        x[w]=a[i][j];
                        w++;
                    }
                }}
            }
            printf("%d\n",count);
        }
    }
    return 0;
}
