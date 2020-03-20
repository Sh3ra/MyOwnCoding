    #include <iostream>
    #include <bits/stdc++.h>
    typedef long long ll;
    using namespace std;
     
    #define MOD 998244353
    #define MAX 1000006
    ll mulmod(ll a,ll b){return ((a%MOD)*(b%MOD))%MOD;}
    ll minusmod(ll a,ll b){return ((((a%MOD)-(b%MOD))%MOD)+MOD)%MOD;}
    ll plusmod(ll a,ll b){return ((a%MOD)+(b%MOD))%MOD;}
    ll n;
     
    int main()
    {
        ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
        cin>>n;
        vector <ll> factorial(MAX);
        vector <ll> dp(MAX);
        factorial[1] = factorial[0] = 1;
        for(ll i = 2;i<MAX;i++){
            factorial[i] = mulmod(factorial[i-1],i);
        }
        dp[1] = 1;
        for(ll i = 2;i<MAX;i++){
            dp[i] = mulmod(minusmod(plusmod(dp[i-1],factorial[i-1]),1),i);
        }
        cout<<dp[n];
        return 0;
    }