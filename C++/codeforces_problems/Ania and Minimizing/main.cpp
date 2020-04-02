#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string res;
    bool checker=false;
    int index;
    if(n==1&&k>0)res.push_back('0');
    else{

    for(int i=0;i<s.size();i++)
    {
        if(k==0)
        {
            checker=true;
            index=i;
            break;
        }
        if(i!=0)
        {
        if(s[i]!='0')
        {
            res.push_back('0');
            k--;
        }
        else res.push_back(s[i]);
        }
        else if(s[i]!='1')
        {
            res.push_back('1');
            k--;
        }
        else res.push_back(s[i]);
    }
    }
    if(checker)
    {
        for(int i=index;i<s.size();i++)
        {
            res.push_back(s[i]);
        }
    }
    cout<<res;
    return 0;
}
