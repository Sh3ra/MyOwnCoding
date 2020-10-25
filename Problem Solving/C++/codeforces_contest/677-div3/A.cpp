#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        ll ans=0;
        ans+=(10*(x%10-1));
        ll cnt=0;
        while (x>0)
        {
            x/=10;
            cnt++;
            
        }
        int i=1;
        while (cnt>0)
        {
            ans+=(cnt);
            cnt--;
        }
        
        
        cout<<ans<<"\n";
        
    }
    return 0;
}

