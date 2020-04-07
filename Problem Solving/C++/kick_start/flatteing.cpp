#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int dp (int arr[],int i,int diff,int k,int n)
{
    for (int j= 0; j < n; j++)
    {
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    
    if(diff<=k)
    return 0;
    if(i==n)
    return INT_MAX;
    if(arr[i]!=arr[i-1])
    {
        int a,b;
        a=dp(arr,i+1,diff,k,n);
        arr[i]=arr[i-1];
        diff--;
        if(i+1<n)
        {
            if(arr[i+1]==arr[i])
            diff--;
        }
        b=dp(arr,i+1,diff,k,n);
        if(b<a)
        return b+1;
        else return a;
    }
    return dp(arr,i+1,diff,k,n);

}

int main(int argc, char const *argv[])
{
    int t,x=1;
    cin>>t;
    while (t--)
    {
        int res=0;
        int n,k,diff=0;
        cin>>n>>k;
        int arr[n];
        cin>>arr[0];
        for(int i=1;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]!=arr[i-1])
                diff++;
        }
        if(diff>k)
        {
            res=dp(arr,1,diff,k,n);
        }

        cout<<"Case #"<<x<<": "<<res<<endl;
        x++;
    }
    
    return 0;
}

