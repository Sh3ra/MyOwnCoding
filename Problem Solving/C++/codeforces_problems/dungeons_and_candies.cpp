#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<ll>> sons;
vector<ll> parent;

void init(ll k)
{
    k++;
    for (int i = 0; i <= k; i++)
    {
        vector<ll> temp;
        sons.push_back(temp);
        parent.push_back(i);
    }
}
ll FIND(ll a)
{
    while (parent[a] != a)
    {
        a = parent[a];
    }
    return a;
}

void UNION(ll a, ll b)
{
    parent[FIND(a)] = FIND(b);
}

vector<vector<string>> levels;

ll dif(ll a, ll b)
{
    ll cnt = 0;
    for (int i = 0; i < levels[a].size(); i++)
    {
        for (int j = 0; j < levels[a][i].size(); j++)
        {
            if (levels[a][i][j] != levels[b][i][j])
                cnt++;
        }
    }
    return cnt;
}
vector<string> ans;
ll total_cost = 0, n, m = 0, w;
void dfs(vector<bool> &vis, ll i, ll p)
{
    vis[i] = true;
    if (p == i)
    {
        string s;
        int x = i + 1;
        s += to_string(x);
        s += " ";
        s += to_string(0);
        //cout<<i+1<<" "<<0;
        ans.push_back(s);
        //total_cost+=(n*m);
    }
    else
    {
        string s;
        s += to_string(i + 1);
        s += " ";
        s += to_string(p + 1);
        //cout<<i+1<<" "<<p+1;
        ans.push_back(s);
        //total_cost+=(dif(i,p)*w);
    }
    //cout<<"\n";

    for (int j = 0; j < sons[i].size(); j++)
    {
        if (!vis[sons[i][j]])
        {
            dfs(vis, sons[i][j], i);
        }
    }
}

int main(int argc, char const *argv[])
{
    ll k;
    cin >> n >> m >> k >> w;
    init(k);
    for (int i = 0; i < k; i++)
    {
        vector<string> temp;
        for (int j = 0; j < n; j++)
        {
            string s;
            cin >> s;
            temp.push_back(s);
        }
        levels.push_back(temp);
    }
    vector<pair<ll, pair<ll, ll>>> edges;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i != j)
            {
                ll d = dif(i, j);
                edges.push_back({d * w, {i, j}});
            }
        }
        edges.push_back({n * m, {i, k}});
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++)
    {
        if (FIND(edges[i].second.first) != FIND(edges[i].second.second))
        {
            if (edges[i].second.second != k)
            {
                sons[edges[i].second.first].push_back(edges[i].second.second);
                sons[edges[i].second.second].push_back(edges[i].second.first);
            }
            UNION(edges[i].second.first, edges[i].second.second);
            total_cost += edges[i].first;
        }
    }
    vector<bool> vis(k, false);
    for (int i = 0; i < k; i++)
    {
        if (!vis[i])
            dfs(vis, i, i);
    }
    cout << total_cost << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
