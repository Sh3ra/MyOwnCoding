#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;cin>>t;
    map<int,int>m;
    vector<set<char>>vs;
    vector<vector<char>>vv;
    while(t--)
    {
        bool imp=false;
        bool taken[26];
        memset(taken, false, sizeof(taken));
        vs.resize(26);
        vv.resize(26);
        string s,outP;cin>>s;
        for(int i=0;i<s.size()-1;i++)
        {
            char c=s[i];
            char n_c=s[i+1];
            int index=(int)(c-'a');
            int siz=v[index].size();
            vs[index].insert(c);
            if(vs[index].size()>siz)
            {
                m[index]++;
                vv[index].push_back(c);
            }
        }
        for(int i=0;i<26;i++)
        {
            if(m[i]>2)
            {
                imp=true;
                break;
            }
        }
        if(imp)cout<<"No"<<endl;
        else
        {
            for(int i=0;i<vv.size();i++)
            {
                
                for(int j=0;j<vv[i].size();j++)
                {

                }
            }
        }
        
    }
    return 0;
}
