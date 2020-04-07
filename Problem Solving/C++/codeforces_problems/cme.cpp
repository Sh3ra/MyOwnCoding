#include<iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    long long q,n,x=1,y=1,res=0;
    cin>>q;
    while (q--)
    {
    cin>>n;
        res=0;   
    if(n==2)res=2;
    else res=n%2;
    cout <<res<<endl;}
    return 0;
}
