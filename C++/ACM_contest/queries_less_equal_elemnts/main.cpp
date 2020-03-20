#include <iostream>
#include<bits/stdc++.h>

using namespace std;


/*int bin_search(long long int a[],int low,int high,long long int key)
{
    long long int mid=(low+high)/2;
    if(a[mid]==key||low==high)
    {
        if(a[mid+1]==key)
        {
            while(a[mid+1]==key)
                mid++;
        }

        if(a[mid]==key)return mid+1;
        else return mid;
    }
    else if(a[mid]>key)
        bin_search(a,low,mid,key);
    else
        bin_search(a,mid+1,high,key);
}*/
int bin_search(long long int a[],int low,int high,long long int key)
{
    while(low<=high)
    {
        long long int mid=(low+high)/2;
        if(a[mid]==key||low==high)
        {
            if(a[mid+1]==key)
            {
                while(a[mid+1]==key)
                    mid++;
            }

            if(a[mid]==key)
                return mid+1;
            else
                return mid;
        }
        else if(a[mid]>key)
            high=mid;
        else
            low=mid+1;
    }
}

int main()
{
    long long int n,m;
    cin>>n>>m;
    long long int a[n],b[m],temp[m];
    map<long long int,long long int>x;
    for(long long int i=0; i<n; i++)
        cin>>a[i];
    for(long long int i=0; i<m; i++){
        cin>>b[i];
        temp[i]=b[i];
        x[b[i]];
        }
    sort(a,a+n);
    sort(b,b+m);
    int ans=0;
    for(long long int j=0; j<m; j++)
    {
        ans=bin_search(a,ans,n,b[j]);
        x[b[j]]=ans;
    }
    for(long long int i=0;i<m;i++){cout<<x[temp[i]];
    if(i!=m-1)cout<<" ";
    }
    return 0;
}
