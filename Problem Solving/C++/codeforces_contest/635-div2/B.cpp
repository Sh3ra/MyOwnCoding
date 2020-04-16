#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll t;cin>>t;
    while (t--)
    {
        ll x,n,m,temp;
        cin>>x>>n>>m;
        temp=x;
        for (int i = 0; i < n; i++)
        {
            x/=2;
            x+=10;
        }
        if(x<=0){
            cout<<"YES"<<endl;
            continue;
        }
        x=temp;
        //cout<<x<<endl;
        x-=m*10;
        if(x<=0){
            cout<<"YES"<<endl;
            continue;
        }
        x=temp;
        for (int i = 0; i < n; i++)
        {
            x/=2;
            x+=10;
        }
        //cout<<x<<endl;
        x-=m*10;
        if(x<=0){
            cout<<"YES"<<endl;
            continue;
        }
        x=temp;
        x-m*10;
        for (int i = 0; i < n; i++)
        {
            x/=2;
            x+=10;
        }
        if(x>0)cout<<"NO";
        else cout<<"YES";
        cout<<"\n";
    }
    return 0;
}
