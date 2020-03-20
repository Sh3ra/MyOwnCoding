#include<iostream>
#include <bits\stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
    int t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll counter=1;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]<=counter)
            {
                if(arr[i]<counter)counter--;
                break;
            }
           if(i>0) counter++;
        }
        cout<<counter<<endl;
    }
    
    return 0;
}
