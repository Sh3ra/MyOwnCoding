#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    long long ans = 1;
    cin >> s;
    long long dp[s.size()+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            cout<<0;
            return 0;
        }
    }
    for(int i=2;i<=s.size();i++)
    {
        if(i!=1&&((s[i-2]=='u'&&s[i-1]=='u')||(s[i-1]=='n'&&s[i-2]=='n')))
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
        else dp[i]=dp[i-1];
    }
    cout<<dp[s.size()];
    return 0;
}
