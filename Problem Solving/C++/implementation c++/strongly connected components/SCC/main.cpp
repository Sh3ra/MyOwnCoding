#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int DfsNum[100005];
int LowLink[100005];
vector<int> adjList[100005];
int tim = 1;
stack<int> Stk;
vector<vector<int> > SCCs;
bool inStack[100005];
void DFS(int node)
{
    Stk.push(node);
    inStack[node] = true;
    DfsNum[node] = LowLink[node] = tim++;
    for(int i = 0;i < adjList[node].size();i++)
    {
        if(DfsNum[adjList[node][i]] == 0)
        {
            DFS(adjList[node][i]);
            LowLink[node] = min(LowLink[node],LowLink[adjList[node][i]]);
        } else if(inStack[adjList[node][i]])
            LowLink[node] = min(LowLink[node],DfsNum[adjList[node][i]]);
    }
    if(LowLink[node] == DfsNum[node])
    {
        vector<int> currentComponent;
        while(Stk.top() != node)
        {
            int topNode = Stk.top();
            Stk.pop();
            currentComponent.push_back(topNode);
            inStack[topNode] = false;
        }
        currentComponent.push_back(node);
        Stk.pop();
        SCCs.push_back(currentComponent);
         inStack[node] = false;
    }
}
int main()
{
    for(int i=0;i<7;i++){
        DfsNum[i]=0;
        LowLink[i]=0;
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int from ,to;
        cin>>from>>to;
        adjList[from].push_back(to);
         //adjList[to].push_back(from);
    }
    DFS(1);
    for(int i=0;i<SCCs.size();i++){
        for(int j=0;j<SCCs[i].size();j++){
            cout<<SCCs[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
