#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    int t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vector<pair<ll,ll>> vp;
        bool good=true;
        for (int i = 0; i < n; i++)
        {
            ll x,y;cin>>x>>y;
            vp.push_back({x,y});
            if(vp[i].first<vp[i].second)good=false;
            if(i>0)
            {
                if(vp[i].first<vp[i-1].first)good=false;
                if(vp[i].second<vp[i-1].second)good=false;
                if(vp[i].second-vp[i-1].second>vp[i].first-vp[i-1].first)good=false;
            }
        }
        good?cout<<"Yes":cout<<"No";
        cout<<endl;
    }
    
}
