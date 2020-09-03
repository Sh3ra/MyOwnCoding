#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<ll>>graph(100007);
bool visited[100007];
bool color[100007];
ll red=0,black=0;

void dfs(ll i,bool parent)
{
    color[i]=!parent;
    visited[i]=true;
    if(parent)red++;
    else black++;
    for (int j = 0; j < graph[i].size(); j++)
    {
        if(!visited[graph[i][j]])
            dfs(graph[i][j],!parent);
    }
}

int main(int argc, char const *argv[])
{
    ll n;
    cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        ll x,y;
        cin>>x>>y;
        x--;y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(color, false, sizeof(color));
    dfs(0,false);
    cout<<red*black-(n-1);
    return 0;
}
