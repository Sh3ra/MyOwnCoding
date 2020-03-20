#include <iostream>

using namespace std;

void build(int tree[],int A[],int node, int start, int endd)
{
    if(start == endd)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + endd) / 2;
        // Recurse on the left child
        build(tree,A,2*node, start, mid);
        // Recurse on the right child
        build(tree,A,2*node+1, mid+1, endd);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update(int tree[],int A[],int node, int start, int endd, int idx, int val)
{
    if(start == endd)
    {
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + endd) / 2;
        if(start <= idx && idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(tree,A,2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(tree,A,2*node+1, mid+1, endd, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
int query(int tree[],int node, int start, int endd, int l, int r)
{
    if(r < start || endd < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start && endd <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + endd) / 2;
    int p1 = query(tree,2*node, start, mid, l, r);
    int p2 = query(tree,2*node+1, mid+1, endd, l, r);
    return (p1 + p2);
}

void updateRangeNotLazy(int tree[],int node, int start, int endd, int l, int r, int val)
{
    // out of range
    if (start > endd or start > r or endd < l)
        return;

    // Current node is a leaf node
    if (start == endd)
    {
        // Add the difference to current node
        tree[node] += val;
        return;
    }

    // If not a leaf node, recur for children.
    int mid = (start + endd) / 2;
    updateRangeNotLazy(tree,node*2, start, mid, l, r, val);
    updateRangeNotLazy(tree,node*2 + 1, mid + 1, endd, l, r, val);

    // Use the result of children calls to update this node
    tree[node] = tree[node*2] + tree[node*2+1];
}

//////////////////
//lazy imp
//////////////////
void updateRange(int tree[],int lazy[], int node, int start, int endd, int l, int r, int val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (endd - start + 1) * lazy[node];    // Update it
        if(start != endd)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > endd or start > r or endd < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and endd <= r)
    {
        // Segment is fully within range
        tree[node] += (endd - start + 1) * val;
        if(start != endd)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + endd) / 2;
    updateRange(tree,lazy,node*2, start, mid, l, r, val);        // Updating left child
    updateRange(tree,lazy,node*2 + 1, mid + 1, endd, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value
}

int queryRange(int tree[],int lazy[],int node, int start, int endd, int l, int r)
{
    if(start > endd || start > r || endd < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (endd - start + 1) * lazy[node];            // Update it
        if(start != endd)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and endd <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + endd) / 2;
    int p1 = queryRange(tree,lazy,node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(tree,lazy,node*2 + 1, mid + 1, endd, l, r); // Query right child
    return (p1 + p2);
}
int main()
{
    int n;
    cin>>n;
    int arr[n+1];for(int i=1;i<=n;i++)arr[i]=i;
    int tree[2*n];
    //////
    int lazy[2*n]={0};
    //////
    build(tree,arr,1,1,n);
    update( tree,arr,1, 1, n, idx to change, val to add);

    updateRangeNotLazy( tree, 1, 1, n, start range, endd range, value to add);
query(tree,1, 1, n, start range, endd range);
    //////lazy part
    updateRange(tree, lazy, 1,1,n, start range, endd range, value to add);
    queryRange( tree, lazy,1, 1, n, start range, endd range);

    ////////
    for(int i=1;i<2*n;i++){
        cout<<tree[i]<<" ";
    }
    return 0;
}
