#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if(a==0)return b;
    return gcd(b%a,a);
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(gcd(a,b)!=1)
        cout<<"Infinite"<<endl;
        else cout<<"Finite"<<endl;
    }
    return 0;
}
