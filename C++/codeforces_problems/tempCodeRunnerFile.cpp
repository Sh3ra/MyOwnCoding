#include <iostream>
#include <bits\stdc++.h>
typedef long long ll;
using namespace std;
int main(int argc, char const *argv[])
{
    int t;cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll>>vp1;
        set<pair<ll,ll>>se;
        vector<pair<ll,ll>>vp;
        for(int i=0;i<n;i++)
        {
            ll x,y;cin>>x>>y;
            vp1.push_back(make_pair(x,y));
        }
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        sort(vp1.begin(),vp1.end());

        for(int i=1;i<n;i++)
        {
            if(vp1[i-1].second>=vp1[i].second)
            {
                int siz=se.size();
                se.insert(vp1[i]);
                if(se.size()>siz)
                {
                    vp.push_back(vp1[i]);
                }
            }
            else {
                int siz=se.size();
                se.insert(vp1[i-1]);
                if(se.size()>siz)
                {
                    vp.push_back(vp1[i-1]);
                }

            }
        }
      ll l,r;
      l=vp[0].second;
      r=vp[0].second;
      for(int i=1;i<vp.size();i++)
      {
          if(!((l>=vp[i].first&&l<=vp[i].second)||(r>=vp[i].first&&r<=vp[i].second)))
          {
              r=vp[i].first;
              if(l>r)
              {
                  ll temp=l;
                    l=r;
                    r=temp;
              }
          }
      }
      cout<<r-l<<endl;
    }
    return 0;
}
