#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int bfs(int m, int n,vector<pair<int,int>>opennings,int x[],int y[])
{
    pair<int,int>s=opennings[0];
    queue<pair<int,int>> q;
    bool used[m][n];
    int length[m][n];
    std::fill( &used[0][0], &used[0][0] + sizeof(used), false );
   // std::fill( &length[0][0], &length[0][0] + sizeof(length), 0 );
   for(int i=0;i<8;i++)
   {
        std::fill_n(length[i], 8, 0);
   }
    q.push(s);
    used[s.first][s.second] = true;
    while (!q.empty())
    {
        pair<int,int> v = q.front();
        if(v==opennings[1])
            return length[v.first][v.second];
        q.pop();
        for(int i=0; i<8; i++)
        {
            if(v.first+x[i]<8&&v.first+x[i]>-1&&v.second+y[i]<8&&v.second+y[i]>-1){

            if(!used[v.first+x[i]][v.second+y[i]])
            {
                used[v.first+x[i]][v.second+y[i]]=true;
                pair<int,int>u;
                u.first=v.first+x[i];
                u.second=v.second+y[i];
                length[u.first][u.second]=length[v.first][v.second]+1;
                q.push(u);
            }
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    cin>>t;
    int x[]= {1,1,2,2,-1,-1,-2,-2};
    int y[]= {2,-2,1,-1,2,-2,1,-1};
    while(t>0)
    {
        t--;
        string loc[2];
        cin>>loc[0];
        cin>>loc[1];
        vector<pair<int,int>>opennings;
        int x1=(loc[0][0]-'a');
        int y1=(loc[0][1]-'0'-1);
        int x2=(loc[1][0]-'a');
        int y2=(loc[1][1]-'0'-1);
        opennings.push_back(make_pair(x1,y1));
        opennings.push_back(make_pair(x2,y2));
       cout<< bfs(8,8,opennings,x,y)<<endl;
    }
    return 0;
}
