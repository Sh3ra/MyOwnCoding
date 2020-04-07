#include <iostream>
#include <bits\stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    long long n,m;
    cin>>n>>m;
    long long arr[n];
    long long prefix[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for (int i = 0; i < n; i++)
    {
        if(i>=m)
           prefix[i]=prefix[i-m]+arr[i];
        else prefix[i]=arr[i];
    }
    long long prev=0;
    for(int i=1;i<=n;i++)
    {
        int q=i;
        i--;
        if(i<m)
        {
            cout<<prefix[i]+prev<<" ";
            prev+=prefix[i];
            i=q;
            continue;
        } 
              long long sum=0;
            sum=prev+prefix[i];
            prev=sum;
        cout<<sum<<" ";
        i=q;
    }
    return 0;
}
