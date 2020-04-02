#include<iostream>
#include <bits\stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
    int t;cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        bool check=true;
        char x='0',y='0';
        int counter=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=t[i])
            {
                if(x!='0')
                {
                    if(x!=s[i]||y!=t[i])
                    {
                        check=false;
                    }
                    else {
                        if(counter==2)
                        check=false;
                        else counter++;
                    }
                }else {
                    x=s[i];
                    y=t[i];
                    counter++;
                }
            }
        }
        if(check&&counter==2)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    
    return 0;
}
