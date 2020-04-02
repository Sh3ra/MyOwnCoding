#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int q;
    cin>>q;
    while(q--)
    {
        long long res=0,n;
        cin>>n;
        for(int i=0;i<n;i++)
            {
                int x;
                cin>>x;
                res+=x;
            }
            if(res%n==0)
            res/=n;
            else
            
            { res/=n;
            res++;
    }
        cout<<res<<endl;
    }
    return 0;
}
