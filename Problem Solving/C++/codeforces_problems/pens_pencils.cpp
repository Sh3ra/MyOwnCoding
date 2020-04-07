#include<iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    int y=ceil((float)a/c);
    int x=ceil((float)b/d);
    if(x+y<=k)
    {
        cout<<y<<" "<<x;
    }
    else cout<<-1;
    cout<<endl;}
    return 0;
}
memset(visited,false,sizeof(visited));
                maxo=0;
                dfs(adj,0,1);
                if(maxo>counter)
                counter=maxo;
                maxo=0;
                dfs(adj,n-1,1);
                if(maxo>counter)
                counter=maxo;
                maxo=0;
                dfs(adj,n,1);
                if(maxo>counter)
                counter=maxo;
                maxo=0;
                dfs(adj,(2*n)-1,1);
                if(maxo>counter)
                counter=maxo;