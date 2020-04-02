#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string s,res;
    cin>>s;
    res.push_back(toupper(s[0]));
    for(int i=1;i<s.length();i++)
    {
        res.push_back(s[i]);    
    }
    cout<<res;
    return 0;
}
