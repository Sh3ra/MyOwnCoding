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
        vector<pair<ll,ll>>vp;
        vector<pair<ll,ll>>vp1;
        for(int i=0;i<n;i++)
        {
            ll x,y;
            cin>>x>>y;
            vp1.push_back(make_pair(x,y));
        }
        if(n==1){cout<<0<<endl;continue;}
        sort(vp1.begin(),vp1.end());
        for(int i=0;i<n;i++)
        {
            bool done=false;
            ll x,y;x=vp1[i].first;y=vp1[i].second;
            if(i==0){vp.push_back(make_pair(x,y));continue;}
            for(int j=0;j<vp.size();j++)
            {
                if (x>=vp[j].first&&y<=vp[j].second)
                {
                    vp[j].first=x;
                    vp[j].second=y;
                    done=true;
                    break;
                }
            }
            if(!done)vp.push_back(make_pair(x,y));
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
