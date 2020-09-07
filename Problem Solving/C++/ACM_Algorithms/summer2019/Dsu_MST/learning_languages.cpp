#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll>papa;
void init(ll n)
{
    for (int i = 0; i < n; i++)
    {
        papa.push_back(i);
    }
}
ll Find(ll j)
{
    while (papa[j]!=j)
    {
        j=papa[j];
    }
    return j;
}

void Union(ll b,ll a)
{
    papa[Find(a)]=Find(b);
}

int main(int argc, char const *argv[])
{
    ll n,m;cin>>n>>m;
    init(n);
    vector<ll>first_spoken(m,-1);
    for (int i = 0; i < n; i++)
    {
        ll k;cin>>k;
        while (k--)
        {
            ll l;cin>>l;
            l--;
            if(first_spoken[l]==-1)
            {
                first_spoken[l]=i;
            }
            else
            {
                Union(i,first_spoken[l]);
            }
        }
    }
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        if(papa[i]==i)
        ans++;
    }
    bool found=false;
    for (int i = 0; i < m; i++)
    {
        if(first_spoken[i]!=-1)
            found=true;
    }
    
    cout<<(found?ans-1:ans);
    
    return 0;
}