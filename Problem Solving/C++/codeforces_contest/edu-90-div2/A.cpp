#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll calc(ll m,ll b,ll c)
{
    ll te=m/b;
    if(b*te!=m)te++;
    return c*te;
}

int main(int argc, char const *argv[])
{
    ll t;cin>>t;
    while (t--)
    {
        ll a,b,c;cin>>a>>b>>c;
        ll ans1=-1,ans2=-1;
        ll lef=1,rig=1000000000;
        while (lef<=rig)
        {
            ll mid=lef+(rig-lef)/2;
            if(mid*a<calc(mid,b,c))
            {
                ans1=mid;
                lef=mid+1;
            }
            else rig=mid-1;
        }
        lef=1,rig=1000000000;
        while (lef<=rig)
        {
            ll mid=lef+(rig-lef)/2;
            if(mid*a>calc(mid,b,c))
            {
                ans2=mid;
                rig=mid-1;
            }
            else lef=mid+1;
        }
        if(ans2!=-1)
        {
            ll te=ans2/b;
            if(b*te!=ans2)te++;
            ans2=te*b;
        }
        if(ans1*a==(ans2/b)*c)
            ans1=-1,ans2=-1;   
        cout<<ans1<<" "<<ans2<<endl;
    }
    
    return 0;
}