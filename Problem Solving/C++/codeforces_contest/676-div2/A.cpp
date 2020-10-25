#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll get2(ll a)
{
    ll ans=0,temp,cnt=0;
    while (a>0)
    {
        ll bit=!(a%2);
        a/=2;
        temp=ans;
        ans=bit;
        ans<<=cnt;
        ans|=temp;
        cnt++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while (t--)
    {
       ll a,b,x;
       cin>>a>>b;
       
       ll ta=get2(a);
       ll tb=get2(b);
        tb+=ta;
        cout<<min({(a^tb)+(b^tb),(a^a)+(b^a),(a^b)+(b^b)});
        cout<<"\n";

    }
    
    return 0;
}
