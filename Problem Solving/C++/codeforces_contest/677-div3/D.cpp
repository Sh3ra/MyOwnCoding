#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll arr[n];
        bool no=true;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            if(i>0)
            {
                if(arr[i]!=arr[i-1])
                no=false;
            }
        }
       
        if(no)
        {
            cout<<"NO"<<"\n";
        }
        else
        {
            cout<<"YES"<<"\n";
            ll indx=0;
            ll s=n;
            n--;
            map<ll,bool>m;
            m[0]=true;
            while (n>0)
            {
                for (int i = 0; i < s; i++)
                {
                    if(i!=indx&&arr[i]!=arr[indx]&&m[i]==false)
                    {
                        cout<<indx+1<<" "<<i+1<<"\n";
                        n--;
                        m[i]=true;
                    }
                }
                indx++;
            } 
        }
        
        
    }
    return 0;
}

