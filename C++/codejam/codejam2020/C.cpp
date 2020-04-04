#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t,T=1;
    cin>>t;
    while(T<=t)
    {
        string res;
        int n;cin>>n;
        int J_end=-1,C_end=-1;
        vector<pair<pair<int,int>,int>>vp;
        unordered_map<int,char>m;
        for(int i=0;i<n;i++)
        {
            int x,y;cin>>x>>y;
            vp.push_back(make_pair(make_pair(x,y),i));
        }
        sort(vp.begin(),vp.end());
        for (int i = 0; i < n; i++)
        {
            if(J_end<=vp[i].first.first)
            {
                J_end=vp[i].first.second;
                m[vp[i].second]='J';
            }
            else if(C_end<=vp[i].first.first)
            {
                C_end=vp[i].first.second;
                m[vp[i].second]='C';
            }
            else
            {
                res="IMPOSSIBLE";
                break;
            }
        }
        if(res!="IMPOSSIBLE")
        {
            for (int i = 0; i < n; i++)
            {
                res.push_back(m[i]);
            }
        }
        cout<<"Case #"<<T<<": "<<res<<endl;
        T++;
    }
    return 0;
}
