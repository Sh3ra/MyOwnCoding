#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll>papa;
vector<ll>cost;
void init(ll n)
{
    for (int i = 0; i < n; i++)
    {
        papa.push_back(i);
        cost.push_back(INT_MAX);
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

void Union(ll b,ll a,ll c)
{
    papa[a]=Find(b);
    cost[a]=min(c,cost[a]);
}
int main(int argc, char const *argv[])
{
    ll n;cin>>n;
    init(n);
    vector<ll>q(n);
    for (int i = 0; i < n; i++)
    {
        cin>>q[i];        
    }
    ll m;
    cin>>m;
    ll x,y,c;
    while (m--)
    {
        cin>>x>>y>>c;
        x--,y--;
        Union(x,y,c);
    }
    ll cnt=0;
    for (int i = 0; i < n; i++)
    {
        if(papa[i]==i)
            cnt++;
    }
    if(cnt!=1)
    {
        cout<<-1;
    }
    else
    {
        ll co=INT_MAX*-1;
        for (int i = 0; i < n; i++)
        {
            co+=cost[i];
        }
        cout<<co;        
    }
    
    return 0;
}
