#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    long long res=0;
    for (int i = 0; i < n; i++)
    {
        res=0;
        for(int j=0;j<m-1;j++)
        {
            if(i==1)
             res+=abs(j-j+1);
            else
            {            
            if(i==j)
            {
                res+=abs(1-j+1+1);
            }
            else if(j<i){
                int x;
                if(j+1<i)
                x=j+1;
                else if(j+1>i) x=j+1+1;
                else x=1;
                res+=abs(j-x);
            }
            }
        }
        cout<<res<<" ";
    }
    
    return 0;
}