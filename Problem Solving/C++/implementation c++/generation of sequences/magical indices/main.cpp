#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t,n;
    scanf("%lld",&t);
    for(int i = 0 ; i < t; i++){
        scanf("%lld",&n);
        ll A[n] = {0}, B[n] = {0}, C[n] = {0};
        for(ll j = 0; j < n; j++){
            scanf("%lld",&A[j]);
        }
        ll maxe = A[0];
        for(ll j = 1; j < n-1; j++){
            //cout<<A[j] <<" " << maxe<<"\n";
            if(A[j] >= maxe){
                B[j] = 1;
                maxe = A[j];
            }
        }
        ll mine = A[n-1];
        for(ll j = n-2; j > 0; j--){
            if(A[j] <= mine){
                C[j] = 1;
                mine = A[j];
            }
        }
        ll ans = 0;
        for(ll j = 1; j < n-1; j++){
            ans += (B[j] & C[j]);

        }
        printf("%lld\n",ans);
    }
    return 0;
}
