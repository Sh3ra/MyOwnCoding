#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2,res;
    cin>>s1>>s2;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]=='1'&&s2[i]=='0')
        {
            res.push_back('1');
        }else if(s2[i]=='1'&&s1[i]=='0')
        {
            res.push_back('1');
        }
        else res.push_back('0');
    }
    cout<<res;
    return 0;
}
