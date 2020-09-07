#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll n,m,k;
    cin>>n>>m>>k;
    char real[n][m];
    ll row[n][m],ans=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>real[i][j];
            if(j>0)
            row[i][j]=row[i][j-1]+1;
            else if (real[i][j]=='.')
            {
                row[i][j]=1;
            }
            if(real[i][j]=='*')
                row[i][j]=0;
            if(row[i][j]>=k)
                ans++;
        }
        
    }
    if(k!=1)
    {

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(j>0)
            row[j][i]=row[j-1][i]+1;
            else if (real[j][i]=='.')
            {
                row[j][i]=1;
            }
            if(real[j][i]=='*')
                row[j][i]=0;
            if(row[j][i]>=k)
                ans++;
        }
        
    }
    }
    cout<<ans;
}