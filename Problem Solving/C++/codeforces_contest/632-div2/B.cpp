#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        ll a[n],b[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        bool there_pos=false,there_neg=false,fail=false;
        for (int i = 0; i < n; i++)
        {
            if(a[i]==b[i]);
            else if(b[i]>0)
            {
                if(!there_pos){
                    cout<<"NO";
                    fail=true;
                    break;
                }
            }
            else if(b[i]<0)
            {
                if(!there_neg){
                    cout<<"NO";
                    fail=true;
                    break;
                }
            }
            else if(b[i]==0)
            {
                if(a[i]>0)
                {
                    if(!there_neg){
                        cout<<"NO";
                        fail=true;
                        break;
                    }
                }
                else if(a[i]<0)
                {
                    if(!there_pos){
                        cout<<"NO";
                        fail=true;
                        break;
                    }
                }
            }
            if(there_neg&&there_pos)break;
            if(a[i]<0)there_neg=true;
            else if(a[i]>0)there_pos=true;
        }
        if(!fail)cout<<"YES";
        cout<<endl;
    }
    
    return 0;
}
