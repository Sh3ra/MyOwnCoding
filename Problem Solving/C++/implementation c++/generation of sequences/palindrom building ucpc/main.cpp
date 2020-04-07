#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll fact[12];
int main()
{
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i < 12; i++){
        fact[i] = i * fact[i-1];
    }
    ll t;
    scanf("%lli",&t);
    for(int i = 0; i < t; i++){
        ll freq[26] = {0};
        ll n;
        string s;
        ll ec=0;
        ll odc = 0;
        scanf("%lli",&n);
        ll h = n;
        cin>>s;
        //cout<<s<<"\n";
        for(int j = 0; j < n; j++){
            freq[s[j] - 'a']++;
            //cout<<freq[s[j] - 'a']<<"\n";
        }
        vector<ll>v;
        for(int j=0;j<26;j++){
            if(freq[j]!=0 && freq[j]%2==0){
                ec++;
                v.push_back(freq[j]/2);
            }else if(freq[j]!=0 && freq[j]%2==1){
                odc++;
                h--;
                v.push_back((freq[j]-1)/2);
            }
        }
        if( (n%2==1 && odc==1) || (n%2 == 0 && odc==0) ){
            ll an = 1;
            ll ne = 0;
            for(int j = 0; j < v.size(); j++){
                an *= fact[v[j]];
                ne += v[j];
            }
            ll p = fact[ne];
            printf("%lld\n",p/an);
        }else{
            printf("0\n");
        }
    }

    return 0;
}
