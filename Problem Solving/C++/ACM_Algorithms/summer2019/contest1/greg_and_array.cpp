#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll n,m,k;cin>>n>>m>>k;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<vector<ll>>op(m);
    for (int i = 0; i < m; i++)
    {
        ll r,l,d;
        cin>>r>>l>>d;
        r--;l--;
        op[i].push_back(r);
        op[i].push_back(l);
        op[i].push_back(d);
    }
    ll temparr[m];
    memset(temparr,0,sizeof(temparr));
    ll arr2[n];
    memset(arr2,0,sizeof(arr2));
    for (int i = 0; i < k; i++)
    {
        ll x,y;cin>>x>>y;
        x--,y--;
        temparr[x]++;
        if(y+1<m)
            temparr[y+1]--;
    }
    for (int i = 0; i < m;i++)
    {
        if(i>0)
            temparr[i]+=temparr[i-1];
        op[i][2]*=temparr[i];
        arr2[op[i][0]]+=op[i][2];
        if(op[i][1]+1<n)
        arr2[op[i][1]+1]-=op[i][2];
    }
    for (int i = 0; i < n; i++)
    {
        if(i>0)arr2[i]+=arr2[i-1];
        cout<<arr[i]+arr2[i]<<" ";
    }
    

    
    return 0;
}