#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool ans=true;

vector<ll>parent;

void init(ll n)
{
    for (int i = 0; i < n; i++)
    {
        parent.push_back(i);
    }
}

ll FIND(ll a)
{
    while (parent[a]!=a)
    {
        a=parent[a];
    }
    return a;
}

void UNION(ll a,ll b)
{
    parent[FIND(a)]=FIND(b);
}

int main(int argc, char const *argv[])
{
    ll n,m;cin>>n>>m;
    vector<pair<ll,ll>>edg;
    init(n);
    for (int i = 0; i < m; i++)
    {
        ll x,y;cin>>x>>y;
        x--,y--;
        edg.push_back({x,y});
    }
    ll cnt=0;
    for (int i = 0; i <m; i++)
    {
        ll x=edg[i].first;
        ll y=edg[i].second;
        if(FIND(x)!=FIND(y))
        {
            UNION(x,y);
        }
        else cnt++;
    }
    ll x=0;
    for (int i = 0; i < n; i++)
    {
        if(parent[i]==i)
            x++;
    }
    
    
    if(cnt==1&&x==1)
    {
        cout<<"FHTAGN!";
    }
    else cout<<"NO";
    
    return 0;
}
