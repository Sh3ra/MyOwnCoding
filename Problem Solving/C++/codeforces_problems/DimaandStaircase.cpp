#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
ll n;
vector<ll> arr;
vector<ll> tree;
vector<ll>lazy;

void build(ll node,ll start,ll end)
{
    if(start==end)
    {
        tree[node]=arr[start];
        return;
    }
    ll mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

void update_lazy(ll node,ll start,ll end,ll l,ll r,ll val)
{
    if(lazy[node]!=0)
    {
        tree[node]=max(lazy[node],tree[node]);
        if(start<end)
        {
            lazy[node*2]=max(lazy[node*2],lazy[node]);
            lazy[node*2+1]=max(lazy[node*2+1],lazy[node]);
        }
        lazy[node]=0;
    }
    if(start>end||start>r||l>end)return;
    if(start>=l&&r>=end)
    {
        tree[node]=max(tree[node],val);
        if(start<end)
        {
            lazy[node*2]=max(lazy[node*2],val);
            lazy[node*2+1]=max(lazy[node*2+1],val);
        }
        return;
    }
    ll mid=(start+end)/2;
    update_lazy(node*2,start,mid,l,r,val);
    update_lazy(node*2+1,mid+1,end,l,r,val);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

ll range_lazy(ll node,ll start,ll end,ll l,ll r)
{
    if(start>end||l>end||r<start)return 0;
    if(lazy[node]!=0)
    {
        tree[node]=max(tree[node],lazy[node]);
        if(start<end)
        {
            lazy[node*2]=max(lazy[node*2],lazy[node]);
            lazy[node*2+1]=max(lazy[node*2+1],lazy[node]);
        }
    }
    if(start>=l&&end<=r)
    {
        return tree[node];
    }
    ll mid=(start+end)/2;
    ll m1=range_lazy(node*2,start,mid,l,r);
    ll m2=range_lazy(node*2+1,mid+1,end,l,r);
    return max(m1,m2);
}

int main(int argc, char const *argv[])
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        ll x;cin>>x;
        arr.push_back(x);
    }
    tree.resize(arr.size()*4);
    lazy.resize(arr.size()*4);
    build(1,0,arr.size()-1);
    ll m;cin>>m;
    for (int i = 0; i < m; i++)
    {
        ll w,h;cin>>w>>h;
        ll val=range_lazy(1,0,arr.size()-1,0,w-1);
        cout<<val<<"\n";
        val+=h;
        //for(int x:tree)cout<<x<<" ";
        //cout<<"\n";
        update_lazy(1,0,arr.size()-1,0,w,val);
        //for(int x:tree)cout<<x<<" ";
        //cout<<"\n";
    }
    
    return 0;
}