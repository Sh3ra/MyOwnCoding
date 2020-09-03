#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        string s;
        cin>>s;
        string ans;
        ll pos=0;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(s[pos]);
            pos+=2;
        }
        
        cout<<ans<<endl;
    }
    //10101010001
    //0,2,4,6
    return 0;
}
