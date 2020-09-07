#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    ll r = 0, l = s.size() , max_cnt = 0, cnt = 0, temp = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if(i==0&&s[i]=='a')
        continue;
        else if(s[i]=='a')
        {
            if(cnt>0)
            {
                break;
            }
            else continue;
        }
        else {
            s[i]--;
            cnt++;
        }
        
    }
    if(cnt==0)
    {
        s[s.size()-1]='z';
    }
    for (int i = 0; i < s.size(); i++)
    {
        cout<<s[i];

    }
    
    return 0;
}