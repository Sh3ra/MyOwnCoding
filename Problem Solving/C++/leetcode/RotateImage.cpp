class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                int t=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][n-i-1];
                matrix[n-j-1][n-i-1]=t;
            }
        }
        int a=0,b=n-1;
        while(a<b)
        {
            for(int i=0;i<n;i++)
            {
                int t=matrix[a][i];
                matrix[a][i]=matrix[b][i];
                matrix[b][i]=t;
            }
            a++,b--;
        }
            
    }
};