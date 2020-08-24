#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
vector<ll>temp_v;
void search(vector<ll>v,ll sum,ll index)
{
    if(index==v.size())
        {temp_v.push_back(sum);return;}
    search(v,sum,index+1);
    sum+=v[index];
    search(v,sum,index+1);
}

int main(int argc, char const *argv[])
{
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll>v1,v2;
    for (int i = 0; i < n; i++)
    {
        ll t;cin>>t;
        i<n/2?v1.push_back(t):v2.push_back(t);
    }
    vector<ll>sub1,sub2;
    temp_v.clear();
    search(v1,0,0);
    sub1=temp_v;
    temp_v.clear();
    search(v2,0,0);
    sub2=temp_v;
    ll ans=0;
    sort(sub2.begin(),sub2.end());
    for (int i = 0; i < sub1.size(); i++)
    {
        ans+=(upper_bound(sub2.begin(),sub2.end(),b-sub1[i])-lower_bound(sub2.begin(),sub2.end(),a-sub1[i]));
    }
    cout<<ans;
    return 0;
}