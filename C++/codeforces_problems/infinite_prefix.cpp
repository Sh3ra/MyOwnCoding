#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        long long x;cin>>x;
        string s;cin>>s;
        long long cntZ=0,cntO=0;
        for(char c:s)
        {
            if(c=='0')cntZ++;
            else if(c=='1')cntO++;
        }
        if(cntZ-cntO==0){
            cout<<-1;
            cout<<endl;
            continue;
        }
        double review=(x*1.0)/(cntZ-cntO);
        if(review<0)
        {
            cout<<0;
        }
        else if (review==0)cout<<1;
        else
        {
            long long ans=0;
            ans++;
            cntO=0;cntZ=0;
            for(char c:s)
            {
                if(c=='0')cntZ++;
                else if(c=='1')cntO++;
                if(cntZ==cntO)ans++;
            }
            cntO=0;cntZ=0;
            for(int i=s.size()-1;i>=0;i--)
            {
                char c=s[i];
                if(c=='0')cntZ++;
                else if(c=='1')cntO++;
                if(cntZ==cntO)ans++;
            }
            cout<<ans;
        }
        cout<<endl;
    }
    return 0;
}