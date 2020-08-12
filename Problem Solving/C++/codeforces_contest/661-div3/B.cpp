#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll t;cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll a[n],b[n];
        ll minA=INT_MAX,minB=INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            minA=min(minA,a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            cin>>b[i];
            minB=min(minB,b[i]);
        }
        ll ans=0;
        for (int i = 0; i < n; i++)
        {
            ll diffA=a[i]-minA;
            ll diffB=b[i]-minB;
            ans+=min(diffA,diffB);
            ans+=abs(diffA-diffB);
        }
        cout<<ans<<endl;
    }
    return 0;
}