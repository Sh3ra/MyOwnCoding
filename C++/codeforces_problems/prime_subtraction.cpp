#include<iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        long long x,y;
        cin>>x>>y;
        if(x-y>1)
        cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}