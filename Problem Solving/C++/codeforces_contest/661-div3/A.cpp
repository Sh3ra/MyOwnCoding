#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll t;cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        bool f=true;
        ll c=0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i+1]-arr[i]>1)
            {
                c++;
                if(c>1){
                f=false;
                break;
                }
            }
        }
        if(f)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    

}