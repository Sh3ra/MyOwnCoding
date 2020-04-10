#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll t;cin>>t;
    while (t--)
    {
        ll n,x;
        cin>>n>>x;
        ll arr[n];
        for (int i = 0; i < n; i++)
            cin>>arr[i];
        sort(arr,arr+n);
        ll ans=0,sum=0,c=0;
        for (int i = n-1; i >-1; i--)
        {
            sum+=arr[i];
            c++;
            if(sum/c<x)break;
            ans++;
        }
        cout<<ans<<endl;
        
    }
    
}
