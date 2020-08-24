#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll n,t;
    cin>>n>>t;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    ll l=0,r=0,total=0,ans=0;
    while (r<n)
    {
        total+=arr[r];
        while(total>t)
        {
            total-=arr[l];
            l++;            
        }
        ans=max(ans,r-l+1);
        r++;
    }
    cout<<ans;    
    return 0;
}
