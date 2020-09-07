#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<ll>>g(55);
vector<bool>vis(55,false);
ll ans=1;
void dfs(ll node)
{
    vis[node]=true;
    for (int i = 0; i < g[node].size(); i++)
    {
        if(!vis[g[node][i]])
            {
                ans*=2;
                dfs(g[node][i]);

            }
    }
    
}

int main(int argc, char const *argv[])
{
    ll n,m;cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    cout<<ans;
    return 0;
}
