#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100005
ll tree[MAX*4];
ll lazy[MAX*4];
ll A[MAX];

void build(int node,int start,int end){
    if(start==end){
        tree[node] = A[start];
        return;
    }
    int mid = (start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);
    tree[node] = tree[node*2]+tree[node*2+1];
}

void update_query(int node,int start,int end,int l,int r,int val){
    if(lazy[node]!=0){
        tree[node] -= (end-start+1)*lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[(node*2)+1] += lazy[node];
        }
        lazy[node] = 0;
        tree[node] = max(0LL,tree[node]);
    }
    if(l>end || r<start || start > end) return;
    if(start >= l && end<=r){
        tree[node] -= (end-start+1)*val;
        tree[node] = max(0LL,tree[node]);
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[(node*2)+1] += lazy[node];
        }
        return;
    }
    int mid = (start+end)/2;
    update_query(node*2,start,mid,l,r,val);
    update_query((node*2)+1,mid+1,end,l,r,val);

}

ll rangeQuery(int node,int start,int end,int l,int r){
    ll xr = tree[node];
    if(lazy[node]!=0){
        tree[node] -= (end-start+1)*lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
        tree[node] = max(0LL,tree[node]);
    }
    if(l>end || r<start) return 0;

    int mid = (start+end)/2;
    if(start >= l && end<=r){
        rangeQuery(node*2,start,mid,l,r);
        rangeQuery(node*2+1,mid+1,end,l,r);
        return tree[node]=tree[node*2]+tree[node*2+1];
    }
     mid = (start+end)/2;
    ll p1 = rangeQuery(node*2,start,mid,l,r);
    ll p2 = rangeQuery(node*2+1,mid+1,end,l,r);
    return (p1+p2);
}

int main()
{
    int n,q,x,y,v,c;
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>A[i];
    }
    build(1,1,n);
    for(int i = 0;i<q;i++){
        cin>>c>>x>>y;
        if(c==1){
            cout<<rangeQuery(1,1,n,x,y)<<endl;
        }else if (c==2){
            cin>>v;
            update_query(1,1,n,x,y,v);
        }
    }

    return 0;
}
