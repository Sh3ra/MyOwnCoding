#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<ll>>color_sets;

void init(ll n,ll c)
{
    for (int i = 0; i < c; i++)
    {
        vector<ll>p;
        for (int j = 0; j < n; j++)
        {
            p.push_back(j);
        }
        color_sets.push_back(p);
    }
    
}

ll FIND(ll a,ll c)
{
    while (color_sets[c][a]!=a)
    {
        a=color_sets[c][a];
    }
    return a;
}

void UNION (ll a,ll b, ll c)
{
    color_sets[c][FIND(a,c)]=FIND(b,c);
}


int main(int argc, char const *argv[])
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,pair<ll,ll>>>edgs;
    ll maxc=0;
    for (int i = 0; i < m; i++)
    {
        ll a,b,c;cin>>a>>b>>c;
        edgs.push_back({--c,{--a,--b}});
        maxc=max(c+1,maxc);
    }
    //sort(edgs.begin(),edgs.end());
    init(n,maxc);
    for(int i=0;i<edgs.size();i++)
    {
        UNION(edgs[i].second.first,edgs[i].second.second,edgs[i].first);
    }
    ll q;cin>>q;
    while (q--)
    {
        ll a,b;cin>>a>>b;
        a--,b--;
        ll cnt=0;
        for (int i = 0; i < maxc; i++)
        {
            if(FIND(a,i)==FIND(b,i))
                cnt++;
        }
        cout<<cnt<<"\n";
    }
    
    return 0;
}
