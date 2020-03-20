#include <iostream>
#include <bits\stdc++.h>

using namespace std;
int maxo = 0;
bool visited[2000];
void dfs(vector<vector<int>> adj, int i, int num)
{
    num++;
    visited[i] = true;
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (!visited[adj[i][j]])
        {
            dfs(adj, adj[i][j], num);
            if (maxo < num)
                maxo = num;
        }
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n * 2);
        string a;
        cin >> a;
        int first_index=-1;
        int last_index=-1;
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1)
            {
                adj[i].push_back(i + 1);
                adj[i + n].push_back(i + 1 + n);
                adj[i + 1].push_back(i);
                adj[i + n + 1].push_back(i + n);
            }
            if (a[i] == '1')
            {
                if(first_index==-1)first_index=i;
                last_index=i;
                adj[i].push_back(n + i);
                adj[n + i].push_back(i);
            }
        }
        int counter = 0;
        if(last_index!=-1)
        counter=last_index+1+max(n-last_index,last_index+1);
        else {
            cout<<n<<endl;
            continue;
        }
        counter=max(counter,n-first_index+max(first_index+1,n-first_index));
        /*memset(visited, false, sizeof(visited));
        maxo = 0;
        dfs(adj, 0, 1);
        if (maxo > counter)
            counter = maxo;
        memset(visited, false, sizeof(visited));
        maxo = 0;
        dfs(adj, n - 1, 1);
        if (maxo > counter)
            counter = maxo;*/
        cout << max(counter, n) << endl;
    }
    return 0;
}