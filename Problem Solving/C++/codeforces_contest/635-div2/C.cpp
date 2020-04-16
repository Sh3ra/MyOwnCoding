#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool visited [500007];
map<int,vector<int>>m;

void dfs(int s,vector<vector<int>>graph) 
{ 
    stack<int> stack; 
  
    stack.push(s); 
    int d=0;
    while (!stack.empty()) 
    { 
        s = stack.top(); 
        stack.pop(); 
        d++;
        if (!visited[s]) 
        { 
            visited[s] = true; 
        } 
        for (int i = 0; i <graph[s].size(); ++i) 
        {
                if (!visited[graph[s][i]]) {
                    stack.push(graph[s][i]);
                    cout<<graph[s][i]<<" "<<d<<endl; 
                    m[d].push_back(s);
                }
        }    
} 
} 
int main(int argc, char const *argv[])
{
    ll n,k;cin>>n>>k;
    vector<vector<int>>graph(n+1);
    for (int i = 0; i < n-1; i++)
    {
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,graph);
    cout<<"h";
    
    return 0;
}
