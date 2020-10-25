#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vector<string>vs;
        vector<pair<ll,ll>>ans;
        while (n--)
        {
            string s;cin>>s;
            vs.push_back(s);
        }
        if(vs.size()>=3&&vs[0].size()>=2)
        {
            ll a,b,c,d;
            a=vs[0][1]-'0';
            b=vs[1][0]-'0';
            c=vs[vs.size()-1][vs[0].size()-1-1]-'0';
            d=vs[vs.size()-1-1][vs[0].size()-1]-'0';
            if(a==0&&b==0)
            {
                if(c!=1)
                {
                    ans.push_back({vs.size(),vs[0].size()-1});
                }
                if(d!=1)
                {
                    ans.push_back({vs.size()-1,vs[0].size()});
                }
            }
            else if(a==1&&b==1)
            {
                if(c!=0)
                {
                    ans.push_back({vs.size(),vs[0].size()-1});
                }
                if(d!=0)
                {
                    ans.push_back({vs.size()-1,vs[0].size()});
                }
            }
            else if(c==0&&d==0)
            {
                if(a==0)
                {
                    ans.push_back({1,2});
                }
                if(b==0)
                {
                    ans.push_back({2,1});
                }
                
            }
            else if(c==1&&d==1)
            {
                if(a==1)
                {
                    ans.push_back({1,2});
                }
                if(b==1)
                {
                    ans.push_back({2,1});
                }
                
            }
            else
            {
                if(a==1)
                {
                    ans.push_back({1,2});
                }
                else
                {
                    ans.push_back({2,1});
                }
                if(c==0)
                {
                    ans.push_back({vs.size(),vs[0].size()-1});
                }
                if(d==0)
                {
                    ans.push_back({vs.size()-1,vs[0].size()});
                }
            }
            
        }
       
        
        cout<<ans.size()<<"\n";
        for (pair<ll,ll>i:ans)
        {
            cout<<i.first<<" "<<i.second<<"\n";
        }
    }
}