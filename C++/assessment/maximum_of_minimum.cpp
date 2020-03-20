#include <iostream>
    #include <stdio.h>
    #include <vector>
    #include <limits.h>
    #include <algorithm>
    #include <stack>
    #include <queue>
    #include <map>
    #include <cstring>
    #include <math.h>
    #define ll long long
using namespace std;
int r,c;
ll arr[1000][1000];
bool visited[1000][1000];
bool isInsideGrid(int i, int j) 
{ 
    return (i >= 0 && i < r && j >= 0 && j < c); 
} 
void get_min(int& x,int& y)
{
    ll min=INT_MAX;
    int dx[] = {-1, 0, 1, 0}; 
    int dy[] = {0, 1, 0, -1}; 
    int tempX;
    int tempY;
    for(int i=0;i<4;i++)
    {
        int a=x+dx[i];
        int b=y+dy[i];
        if (!isInsideGrid(a, b)) 
                continue; 
        if(min>=arr[a][b]&&!visited[a][b])
        {
            min=arr[a][b];
            tempX=a;
            tempY=b;
        }
    }
    x=tempX;y=tempY;
}
ll solve(int i,int j)
{
    ll maxi=arr[i][j];
    int x=i,y=j;
    visited[i][j]=true;
    while (y>0)
    {
        get_min(x,y);
        if(visited[x][y])
            {return LLONG_MAX;}
        visited[x][y]=true;
        maxi=max(arr[x][y],maxi);        
    }
    
    return maxi;
}
int main(int argc, char const *argv[])
{
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }
    ll maxi=INT_MAX;
    for(int i=0;i<r;i++)
    {
        memset(visited,false,sizeof(visited));
        if(arr[i][c-1]<maxi)
        maxi=min(solve(i,c-1),maxi);
    }
    cout<<maxi;
    return 0;
}
