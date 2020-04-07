#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false),cin.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        ll arr[n],av,sum=0;
        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
            av+=arr[i];   
            if(i>0)
                sum+=arr[i]; 
        }
        cout<<min(sum+arr[0],m);
        cout<<endl;
        

        
    }
    
    return 0;
}
