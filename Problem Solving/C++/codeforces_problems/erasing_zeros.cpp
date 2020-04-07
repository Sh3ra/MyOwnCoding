#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        long long c=0,fake_c=0;
        bool start=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1'&&start==false)start=true;
            if(s[i]=='0'&&start)
            {
                fake_c++;
            }
             if(s[i]=='1'&&start)
             {
                 c=c+fake_c;
                 fake_c=0;
             }
        }
        cout<<c<<endl;

    }
    return 0;
}
