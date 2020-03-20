#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,g,b;cin>>n>>g>>b;
        long long c=0,done=0;
        long long half=(n/2)+(n%2),b_c=0;
        while (done<half)
        {
            c+=g;
            done+=g;
            if(done>=half)
            break;
            b_c+=b;
            c+=b;
        }
        if(b_c<n-done){
        
            c+=n-done;
        }
        if(n%(g+b)==0||g>=n)c=n;
        cout<<max(c,n)<<endl;
    }
    return 0;
}
