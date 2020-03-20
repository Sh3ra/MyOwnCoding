#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n,j=0,k=0;
        scanf("%I64d",&n);
        long long counter=0;
        map<long long,long long>a;
        map<long long ,long long>b;
        long long arr[n];
        long long arr2[n];
        set<long long>se;
        vector<long long>v;
        for(int i=0;i<n*2;i++)
        {
            if(i%2==0)
            {
            scanf("%I64d",&arr[k]);
            a[arr[k]]++;
            int prev_size=se.size();
            se.insert(arr[k]);
            if(se.size()>prev_size)
                v.push_back(arr[k]);
            k++;
            }
            else
            {
                scanf("%I64d",&arr2[j]);
                b[arr2[j]]++;
                j++;

            }
        }
        for(int i=0;i<v.size();i++)
        {
            counter+=a[v[i]]*b[v[i]];
        }
        printf("%I64d\n",counter);
    }
}
