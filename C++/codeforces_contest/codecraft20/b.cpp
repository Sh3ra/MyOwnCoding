#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false),cin.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        string s;
        cin>>n;
        cin>>s;
        vector<char>v;
        string temp1=s,temp2,temp4;
        temp2=temp1.substr(1,n) + temp1.substr(0,1);
        temp4=temp2.substr(2,n) + temp2.substr(0,2);
        temp4=reverse(temp4.begin()+4,temp4.end());
        for (int k = 1; k <= s.size();k++)
        {
            if(k==1||k==2||k==4)continue;
            if(k%2==1)
            {
                temp1 = temp1.substr(2,n) + temp1.substr(0,2);
            }
            else
            {
                temp4=temp4.substr(2,n) + temp4.substr(0,2);
            }
            
        }
        

        

        
    }
    return 0;
}