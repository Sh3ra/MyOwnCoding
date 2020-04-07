#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long n;
    cin>>n;
    unsigned long long arr[n];
    unsigned long long sorted_arr[n];
    unsigned long long sum_sorted_arr[n];
    unsigned long long sum_arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sorted_arr[i]=arr[i];
    }
    sort(sorted_arr,sorted_arr+n);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            sum_arr[i]=arr[i];
            sum_sorted_arr[i]=sorted_arr[i];
        }
        else{
            sum_arr[i]=sum_arr[i-1]+arr[i];
            sum_sorted_arr[i]=sum_sorted_arr[i-1]+sorted_arr[i];
        }
    }
    unsigned long long m;
    cin >>m;
    for(int i=0;i<m;i++)
    {
        unsigned long long x,l,r;
        cin>>x;
        switch(x)
        {
            case 1:{
                cin>>l>>r;
                l--;r--;
                unsigned long long temp=0;
                temp=sum_arr[r]-sum_arr[l]+arr[l];
                cout<<temp<<endl;
            }break;
            case 2:{
                cin>>l>>r;
                l--;r--;
                unsigned long long  temp=0;
                temp=sum_sorted_arr[r]-sum_sorted_arr[l]+sorted_arr[l];
                cout<<temp<<endl;
            }break;
        }
    }

    return 0;
}
