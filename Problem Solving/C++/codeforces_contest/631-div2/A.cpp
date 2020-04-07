#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll t;cin>>t;
    
    while (t--)
    {
        ll n,x;cin>>n>>x;
        map<int,int>m;
        for (int i=0;i<n;i++)
        {
            int temp;cin>>temp;
            m[temp]=1;
        }
        int index=1,ans=1;
        while (x>=0)
        {
            if(x==0)
            {
                if(m[index==1]){index++;continue;}
                else ans=index-1;
            }
            if(m[index]==1)
            {
                index++;
                continue;
            }
            else {
                x--;
            }
            index++;
        }
        cout<<ans<<endl;
        
    }
    
    
    return 0;
}
