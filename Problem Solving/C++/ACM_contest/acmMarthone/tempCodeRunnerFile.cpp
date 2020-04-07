#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    long long maxN=0,temp=1;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
        temp++;
        else
        {
            if(temp>maxN)
            maxN=temp;
            temp=1;
        }        
    }
    if(maxN==1)
    cout<<2;
    else cout<<maxN;
    
    return 0;
}
