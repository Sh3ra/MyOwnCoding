#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m,now,prev,counter=0;
    cin>>n>>m;
    cin>>now;
    prev=1;
    counter+=(now-prev);
    prev=now;
    for(int i=1;i<m;i++)
    {
        cin>>now;
        if(now>prev)
        {
            counter+=(now-prev);
        }
        else if(prev>now)
        {
            counter+=(n-prev)+1;
            prev=1;
            counter+=(now-prev);
        }
        prev=now;
    }
    cout<<counter;
    return 0;
}
