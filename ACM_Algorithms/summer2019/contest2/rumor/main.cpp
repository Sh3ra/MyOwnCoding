#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void dfs(vector<vector<long long> >&adj,long long s,vector<bool>&visited)
{
    visited[s]=true;
    for (long long u : adj[s])
    {
        if(!visited[u])
            dfs(adj,u,visited);
    }
    return;
}

int main()
{
    long long result=0;
    long long n,m;
    cin >>n>>m;
    vector<vector<long long>>adj;
    vector<bool>visited;
    vector<long long>c;
    for(long long i=0; i<n; i++)
    {
        long long temp;
        cin>>temp;
        c.push_back(temp);
        visited.push_back(false);
        vector<long long >a;
        adj.push_back(a);
    }
    long long minC=INT_MAX,index;
    for(long long i=0; i<m; i++)
    {
        long long x1,x2;
        cin >>x1>>x2;
        x1--;
        x2--;
        adj[x1].push_back(x2);
        adj[x2].push_back(x1);
        if(c[x1]<minC)
        {
            index=x1;
            minC=c[x1];
        }
        if(c[x2]<minC)
        {
            index=x2;
            minC=c[x2];
        }
    }
    //NOTES IN NOTAAAAAAAAA
    if(m)
    {
        result+=c[index];
        dfs(adj,index,visited);
    }
    for(long long i=0; i<adj.size(); i++)
    {
        if(!visited[i])
        {
            result+=c[i];
            dfs(adj,i,visited);
        }
    }
    cout<<result;
    return 0;
}
