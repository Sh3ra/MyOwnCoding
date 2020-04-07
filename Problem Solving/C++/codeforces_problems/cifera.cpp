#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power & 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power >>= 1; // Can also use power >>= 1; to make code even faster
    }
    return result;
}
int main(int argc, char const *argv[])
{
    long long k,l;cin>>k>>l;
    long long i=0;
    /*if(l%k!=0){
        cout<<"NO";
        return 0;
        }

    while (fast_power(k,i)<l)
    {
        i++;
    }
    if(fast_power(k,i)==l)
    {
        cout<<"YES"<<endl<<i-1;
    }
    else cout<<"NO";*/
    long long temp=1;
    while(temp<l)
    {
        temp*=k;
        i++;
    }
        if(temp==l)
    {
        cout<<"YES"<<endl<<i-1;
    }
    else cout<<"NO";

    return 0;
}
