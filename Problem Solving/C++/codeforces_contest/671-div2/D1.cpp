#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll n;
    cin>>n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll ans[n];
    ll i=0,j=n-1;
    ll indx=0;
    ll cnt=0;
    while (i<j)
    {
        ans[indx++]=arr[j--];
        ans[indx++]=arr[i++];
    }
    if(i==j)
            ans[indx++]=arr[j--];

    cout<<(n/2)-!(n%2)<<endl;
    for (ll x:ans)
    {
        cout<<x<<" ";
    }
    
    return 0;
    
}