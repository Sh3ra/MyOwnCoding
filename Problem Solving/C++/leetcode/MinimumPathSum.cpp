class Solution {
    #include <bits/stdc++.h>
public:
    void solve(vector<vector<int>>grid,int x,int y,int i,int j,vector<vector<int>>&dp){
        if(i==grid.size())return ;
        if(j==grid[0].size())return ;
        dp[i][j]=min(dp[x][y]+grid[i][j],dp[i][j]);
        solve(grid,i,j,i,j+1,dp);
        solve(grid,i,j,i+1,j,dp);
    }
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0)return 0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        dp[0][0]=grid[0][0];
        //solve(grid,0,0,0,0,dp);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(i<grid.size()-1)
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]+grid[i+1][j]);
                if(j<grid[i].size()-1)
                    dp[i][j+1]=min(dp[i][j+1],dp[i][j]+grid[i][j+1]);
            }
        }
        return dp[grid.size()-1][grid[grid.size()-1].size()-1];
    }
};