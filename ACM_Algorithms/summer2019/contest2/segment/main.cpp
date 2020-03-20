#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int ar[100005];
    int val = 2;
    ar[1] = 0,ar[2] = 0;
    for(int i = 3;i<100005;i++){
        if(i == 100005) break;
        ar[i] = val;
        i++;
        if(i == 100005) break;
        val++;
        ar[i] = val;
        i++;
        if(i == 100005) break;
        ar[i] = val;
        val++;
    }
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<ar[n]<<endl;
    }
}
