#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    scanf("%lld",&t);
    ll sub;
    ll themod = 1000000007;
    for (int i = 0; i < t;i++){
        ll n;
        scanf("%lld",&n);
        ll temp;
        scanf("%lld",&temp);
        for (int j = 0 ; j < n - 1 ; j++){
            sub = temp;
            scanf("%lld",&temp);
            temp = ((sub+1) * temp + sub) % themod;

        }
        printf("%lli\n",temp);
    }


    return 0;
}
