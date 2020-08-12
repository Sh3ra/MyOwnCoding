#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll t;cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        unordered_map<ll,ll>m;
        map<pair<ll,ll>,bool>ii;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            //m[arr[i]]++;
        }
        ll ans=0;
        //ll ar[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                ll s=arr[i]+arr[j];
                if(!ii[{s,i}]&&!ii[{s,j}]){
                    m[s]++;
                    ii[{s,i}]=!ii[{s,i}];
                    ii[{s,j}]=!ii[{s,j}];
                    ans=max(ans,m[s]);
                }
            }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}