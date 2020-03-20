#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>a;
    for(int i=0;i<4;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    if(a[3]==a[2]+a[1]+a[0])
       {
        cout<<"YES";
        return 0;
        }
    else if(a[3]+a[0]==a[2]+a[1])
        {
        cout<<"YES";
        return 0;
        }
    cout<<"NO";

    return 0;
}
