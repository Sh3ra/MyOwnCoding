#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool bfs(string mat[],int m, int n,vector<pair<int,int>>opennings)
{
    pair<int,int>s=opennings[0];
    queue<pair<int,int>> q;
    bool used[m][n];
    std::fill( &used[0][0], &used[0][0] + sizeof(used), false );
    q.push(s);
    used[s.first][s.second] = true;
    while (!q.empty())
    {
        pair<int,int> v = q.front();
        if(v==opennings[1])
            return true;
        q.pop();
        if(v.first+1<m)
        {
            if (!used[v.first+1][v.second]&&mat[v.first+1][v.second]=='.')
            {
                used[v.first+1][v.second] = true;
                q.push(make_pair(v.first+1,v.second));
            }
        }
        if(v.first-1>-1)
        {
            if (!used[v.first-1][v.second]&&mat[v.first-1][v.second]=='.')
            {
                used[v.first-1][v.second] = true;
                q.push(make_pair(v.first-1,v.second));
            }

        }
        if(v.second-1>-1)
        {
            if (!used[v.first][v.second-1]&&mat[v.first][v.second-1]=='.')
            {
                used[v.first][v.second-1] = true;
                q.push(make_pair(v.first,v.second-1));
            }
        }
        if(v.second+1<n)
        {

            if (!used[v.first][v.second+1]&&mat[v.first][v.second+1]=='.')
            {
                used[v.first][v.second+1] = true;
                q.push(make_pair(v.first,v.second+1));
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >>t;
    while(t>0)
    {
        t--;
        int n,m;
        cin>>m>>n;
        string mat[m];
        vector<pair<int,int>>opennings;
        for(int i=0; i<m; i++)
        {
            cin>>mat[i];
            if(i==0||i==m-1)
            {
                for(int j=0; j<n; j++)
                {
                    if(mat[i][j]=='.')
                        opennings.push_back(make_pair(i,j));
                }
            }
            else
            {
                if(mat[i][0]=='.')
                    opennings.push_back(make_pair(i,0));
                if(mat[i][n-1]=='.'&&n-1!=0)
                    opennings.push_back(make_pair(i,n-1));
            }
        }
        if(opennings.size()!=2)
        {
            cout<<"invalid"<<endl;
            continue;
        }
        if(bfs(mat,m,n,opennings))
            cout<<"valid"<<endl;
        else
            cout<<"invalid"<<endl;
    }
    return 0;
}
