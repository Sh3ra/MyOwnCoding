#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll min_cost;
ll cost[100007];
vector<vector<ll>>graph(100007);
bool visited[100007];
void dfs(ll i,ll n)
{
    if (i >= n)
        return;
    visited[i] = true;
    min_cost=min(min_cost,cost[i]);
    for (int j = 0; j < graph[i].size(); j++)
    {
        if(!visited[graph[i][j]])
            dfs(graph[i][j],n);
    }
}

int main(int argc, char const *argv[])
{
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        min_cost = INT_MAX;
        if(!visited[i])
            {dfs(i,n);
        ans += min_cost;}
    }
    cout << ans;

    return 0;
}
