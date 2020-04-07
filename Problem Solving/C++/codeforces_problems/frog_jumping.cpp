#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while (t--)
    {
        long long a,b,k;
        cin>>a>>b>>k;
        long long x,y;
        if(k%2==0)
        {
            x=a*(k/2);
            y=b*(k/2);
        }
        else {
            x=a*((k/2)+1);
            y=b*(k/2);
        }
        cout<<x-y<<endl;
    }
}
    
