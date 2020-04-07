#include<iostream>
#include <bits\stdc++.h>

using namespace std;

long long gcd(long long a,long long b)
{
    if(a==0)return b;
    return gcd(b%a,a); 
}

int main(int argc, char const *argv[])
{
    long long n,q,k=25,MaxN=100005;
    cin>>n;
    long long st[MaxN][k+1];
    map<long long,long long>m;
    for(int i=0;i<n;i++)
        cin>>st[i][0];
    for(int j=1;j<=k;j++)
    {
        for(int i=0;i+(1<<j)<=n;i++)
        {
            st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            m[st[i][j]]++;
        }
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int t;
        cin>>t;
        cout<<m[t]<<endl;

    }
    return 0;
}
