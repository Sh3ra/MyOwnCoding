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
        vector<pair<pair<ll,pair<ll,ll>>,ll>>vpp;
        for (int i = 0; i < n; i++)
        {
            ll x,y;cin>>x>>y;
            ll z=x;
            if(i==n-1)
                vpp.push_back({{z,{x,y}},0});
            else vpp.push_back({{z,{x,y}},i+1});
                
        }
        vector<pair<pair<ll,pair<ll,ll>>,ll>>vpp1=vpp;
        sort(vpp.begin(),vpp.end());
        ll b=0;
        for(int i=0;i<n;i++)
        {
            ll index=vpp[i].second;
            ll myIndex;
            if(index==0)myIndex=n-1;
            else myIndex=index-1;
            if(vpp1[myIndex].first.second.first<1)continue;
            b+=vpp1[myIndex].first.second.first;
            if(vpp1[index].first.second.first<1)continue;
            vpp1[index].first.second.first-=vpp1[myIndex].first.second.second;
            vpp1[myIndex].first.second.first=0;
            while (vpp1[index].first.second.first<1)
            {
                 myIndex=index;
                 index =vpp1[myIndex].second;
                 if(vpp1[index].first.second.first<1)break;    
                 vpp1[index].first.second.first-=vpp1[myIndex].first.second.second;  
            }            
        }           
        cout<<b<<endl;
    }
    
    return 0;
}
