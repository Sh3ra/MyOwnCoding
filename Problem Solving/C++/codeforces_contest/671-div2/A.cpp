#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll turns=n-1;
        ll ev_odd=0,odd_ev=0,ev_ev=0,od_od=0;
        for (int i = 0; i < n; i++)
        {
            if((i+1)%2)
            {
                if((s[i]-'0')%2)
                    od_od++;
                else ev_odd++;
            }
            else
            {
                if((s[i]-'0')%2)
                    odd_ev++;
                else ev_ev++;
            }
        }
        for (int i = 0; i < n-1; i++)
        {
            if(i%2==0)
            {

                if(ev_odd>0)
                    ev_odd--;
                else
                {
                    od_od--;
                }
            } 
            else
            {
                if(odd_ev>0)
                    odd_ev--;
                else
                {
                    ev_ev--;
                }
            }   
        }
        if(ev_ev||ev_odd)
            cout<<"2";
        else
        {
            cout<<"1";
        }
        cout<<endl;

    }
    
    return 0;
}
