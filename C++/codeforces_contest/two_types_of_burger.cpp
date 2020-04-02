#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >>t;
    long long b,p,f,h,c;
    long long profit;
    long long maxm,minm,y,z;
    while(t--)
    {
        profit=0;
        cin >>b>>p>>f>>h>>c;
        b=b/2;
        if(b==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(h>=c)
        {
            maxm=h;
            minm=c;
            y=p;
            z=f;
        }
        else {
            maxm=c;
            minm=h;
            y=f;
            z=p;
        }
        if(b>=y)
        {
            b=b-y;
            profit=profit+maxm*y;
            if(b<=z)
            profit=profit+minm*b;
            else profit=profit+minm*z;
        }
        else if(b<y)
        {
            profit=profit+maxm*b;
        }
        cout<<profit<<endl;        
    }
    return 0;
}
