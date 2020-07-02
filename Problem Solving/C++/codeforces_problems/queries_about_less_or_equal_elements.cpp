#include<iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int bs(ll arr[],ll b,ll siz)
{
    int ans=siz;
    int l=0,r=siz-1;
    while (l<=r)
    {
        int mid=l+((r-l)/2);
        if(arr[mid]>b)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ll n,m;
    cin>>n>>m;
    ll a[n],b[m];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    for (int i = 0; i < m; i++)
    {
        cout<<bs(a,b[i],n)<<" ";
    }
    
    return 0;
}