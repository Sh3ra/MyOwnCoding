#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{

	ll t;
	scanf("%lld",&t);
	for(int i = 0; i < t; i++){
        ll n,m;
        scanf("%lli",&n);
        scanf("%lli",&m);
        ll arr[n];
        ll counter = 0;
        ll num = -1;
        for (ll j = 0; j< n ; j++){
            ll a;
            scanf("%lli",&a);
            arr[j] = a;
            if (a != -1 && num == -1){
                num = a;
                counter = j;
            }
        }
        for(ll j = counter + 1; j < n; j++){
            arr[j] = (arr[j-1] + 1) % m;
        }
        for(ll j = counter - 1; j >= 0; j--){
            if(arr[j + 1] == 0){
                arr[j] = m - 1;
            }else{
                arr[j] = arr[j+1] - 1;
            }
        }
        for(ll j = 0; j < n; j++){
            cout<<arr[j]<<" ";
        }
        printf("\n");
	}




    return 0;
}
