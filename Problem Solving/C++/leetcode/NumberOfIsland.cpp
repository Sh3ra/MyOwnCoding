class Solution {
    #include <bits/stdc++.h>
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        if(grid.size()==0)return 0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        stack<pair<int,int>>s;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1'&&!visited[i][j])
                {
                    ans++;
                    s.push({i,j});
                    visited[i][j]=true;
                    while(!s.empty())
                    {
                        int x=s.top().first,y=s.top().second;
                        //cout<<x<<" "<<y<<endl;
                        visited[x][y]=true;
                        s.pop();

                        if(x>0&&grid[x-1][y]=='1'&&!visited[x-1][y])
                        {
                            s.push({x-1,y});
                        }
                        if(y>0&&grid[x][y-1]=='1'&&!visited[x][y-1])
                        {
                            s.push({x,y-1});
                        }
                        if(x<grid.size()-1&&grid[x+1][y]=='1'&&!visited[x+1][y])
                        {
                            s.push({x+1,y});
                        }
                        if(y<grid[x].size()-1&&grid[x][y+1]=='1'&&!visited[x][y+1])
                        {
                            s.push({x,y+1});
                        }
                    }
                }
            }
        }
        return ans;
    }
};