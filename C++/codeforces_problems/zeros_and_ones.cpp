#include<iostream>
#include <bits\stdc++.h>
#define ll long long
using namespace std;

ll solve(ll x,ll y,ll m,ll k,ll num,ll i,ll bits){
    if(x==1){
        num=num|1LL<<bits;
        if(num%m>=k)
            return 1;
        else return 0;
    }
    else if(y==0){
        while (x--)
        {
            num|=1LL<<i;
            i++;
        }
         if(num%m>=k)
            return 1;
        else return 0;
    }
    else{
        return solve(x-1,y,m,k,num|1LL<<i,i+1,bits)+solve(x,y-1,m,k,num,i+1,bits);
    }
}

int main(int argc, char const *argv[])
{
 //  freopen("zeros.in","r",stdin);
    long long t;
    cin>>t;
    while (t--)
    {   
        long long x,y,m,k,d=0,temp=0,counter=0;
        cin>>x>>y>>m>>k;
       // long long max_d=((long long)pow(2,x)-1)<<y;
       // temp=(d-k)/m;
        //d=(1<<y+x-1)+pow(2,x-1)-1;
        cout<<solve(x,y,m,k,0,0,x+y)<<endl;        
    }
    return 0;
}
