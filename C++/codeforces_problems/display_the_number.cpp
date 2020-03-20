#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long ones=0;
        if(n%2==0)
        {
            ones=n/2;
            while (ones--)
            {
                cout<<1;
            }
        }
        else {
            ones=(n-3)/2;
            
            cout<<7;
            while (ones--)
            {
                cout<<1;
            }
        }
        cout<<endl;
    }
    return 0;
}
