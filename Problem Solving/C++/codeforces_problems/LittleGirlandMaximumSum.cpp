#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
ll n;
vector<ll> arr;
vector<ll> tree;

void build(ll node,ll start,ll end)
{
    if(start==end){
        tree[node]=arr[start];
        return;
    }
    ll mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(ll node,ll start,ll end,ll l,ll r)
{
    if(r<start||l>end||start>end)return 0;
    if(l<=start&&r>=end)return tree[node];
    ll mid=(start+end)/2;
    ll p1=query(node*2,start,mid,l,r);
    ll p2=query(node*2+1,mid+1,end,l,r);
    return p1+p2;
}

int main(int argc, char const *argv[])
{
    ll q;
    cin >> n >> q;
    priority_queue<ll> pq;
    vector<pair<ll,ll>> prefix;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        pq.push(x);
        prefix.push_back({0, i});
    }
    vector<pair<ll,ll>>queries;
    for (int i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        prefix[l].first++;
        if (r < n)
            prefix[r].first--;
        r--;
        queries.push_back({l,r});
    }
    for (int i = 1; i < n; i++)
    {
        prefix[i].first+=prefix[i-1].first;
    }
    
    sort(prefix.begin(),prefix.end());
    arr.resize(n);
    for (int i = n-1; i >=0; i--)
    {
        arr[prefix[i].second]=pq.top();
        pq.pop();
    }
    tree.resize(arr.size()*4);
    build(1,0,arr.size()-1);
    ll ans=0;
    for (int i = 0; i < q; i++)
    {
        ans+=query(1,0,arr.size()-1,queries[i].first,queries[i].second);
    }
    cout<<ans;
    return 0;
}
