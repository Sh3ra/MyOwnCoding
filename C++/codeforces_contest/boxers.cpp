#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long maxN=-1,n;
set<long long >y;

void solve(long long i,vector<long long > arr)
{
    if(i==n) return ;
    for(int j=0;j<n;j++)
    {
        y.insert(arr[j]);
    }
    if(maxN<y.size())
    maxN=y.size();
    y.clear();
    solve(i+1,arr);
    arr[i]++;
    for(int j=0;j<n;j++)
    {
        y.insert(arr[j]);
    }
    if(maxN<y.size())
    maxN=y.size();
    y.clear();
    solve(i+1,arr);
    arr[i]--;
    if(arr[i]!=1)
    {
    arr[i]--;
    for(int j=0;j<n;j++)
    {
        y.insert(arr[j]);
    }
    if(maxN<y.size())
    maxN=y.size();
    y.clear();
    solve(i+1,arr);
    }
}

int main(int argc, char const *argv[])
{
    cin>>n;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    solve(0,arr);
    cout<<maxN;
    return 0;
}
