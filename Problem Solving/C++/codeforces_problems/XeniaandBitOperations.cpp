#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
ll n;
vector<ll>arr;
vector<ll>tree;
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
    if(n%2==((int)log2(node)+1)%2)
    {
        tree[node]=tree[node*2]|tree[node*2+1];
    }
    else
    {
        tree[node]=tree[node*2]^tree[node*2+1];
    }
}

void update(ll node,ll start, ll end, ll indx, ll val)
{
    if(start==end)
    {
        tree[node]=val;
        arr[start]=val;
        return;
    }
    ll mid=(start+end)/2;
    if(start<=indx&&mid>=indx)
    {
        update(node*2,start,mid,indx,val);
    }
    else
    {
        update(node*2+1,mid+1,end,indx,val);
    }
    if(n%2==((int)log2(node)+1)%2)
    {
        tree[node]=tree[node*2]|tree[node*2+1];
    }
    else
    {
        tree[node]=tree[node*2]^tree[node*2+1];
    }
}

int main(int argc, char const *argv[])
{
    ll m;
    cin>>n>>m;
    for (int i = 0; i < (ll)pow(2,n); i++)
    {
        ll x;cin>>x;
        arr.push_back(x);
    }
    tree.resize(arr.size()*4);
    build(1,0,arr.size()-1);
    //for(ll x:tree)cout<<x<<" ";
    //cout<<endl;
    for (int i = 0; i < m; i++)
    {
        ll p,q;cin>>p>>q;
        p--;
        update(1,0,arr.size()-1,p,q);
        cout<<tree[1]<<"\n";
    }    
}