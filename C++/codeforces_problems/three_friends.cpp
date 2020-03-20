#include<iostream>
#include<bits\stdc++.h>
# define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
    ll t;cin>>t;
    while(t--)
    {
        ll a[3];
        cin>>a[0]>>a[1]>>a[2];
        ll sum =abs(a[0]-a[1])+abs(a[0]-a[2])+abs(a[1]-a[2]);
        if(sum<=4)cout<<0<<endl;
        else cout<<sum-4<<endl;
    }
    return 0;
}
