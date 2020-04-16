#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll t;cin>>t;
    while (t--)
    {
        ll a,b,c,d;cin>>a>>b>>c>>d;
        ll x,y,z;
        z=c;
        x=a;
        y=c-a+1>b?c-a+1:b;
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
    return 0;
}
