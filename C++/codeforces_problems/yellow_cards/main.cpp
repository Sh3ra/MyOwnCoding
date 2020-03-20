#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;
    if(a1*k1+a2*k2<=n)
    {
        cout<<a1+a2<<" ";
        cout<<a1+a2;
        return 0;
    }
    else
    {
        if(n<=a1*(k1-1)+a2*(k2-1))
        {
            cout<<0<<" ";
        }
        else
        {
            cout<<n-(a1*(k1-1)+a2*(k2-1))<<" ";
        }
        int k,a,k3,a3;
        if(k1<=k2)
        {
            a=a1;
            k=k1;
            a3=a2;
            k3=k2;
        }
        else {
            a=a2;
            k=k2;
            a3=a1;
            k3=k1;
        }
        int counter=0;
            if(a*k<=n)
            {
                counter+=a;
                n=n-a*k;
                counter+=n/k3;
            }
            else counter+=n/k;
            cout<<counter;

    }
    return 0;
}
