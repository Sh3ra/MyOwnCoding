#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll k;
    cin >> k;
    string s;
    cin >> s;
    ll l = 0, r = 0, calc = 0, ans = 0,zcnt=0;
    deque<ll> ones;
    while (r < s.size())
    {
        if (s[r] == '1')
        {
            ones.push_front(r);
            if(k==0)
            {
                calc=((zcnt*(zcnt+1))/2);
                ans += calc;

            }
            zcnt=0;
            calc=0;
        }
        else zcnt++;
        if (ones.size() < k)
        {
            calc = calc;
        }
        else if (ones.size() == k)
        {
            if (s[r] == '1')
            {
                calc = ones.back() - l + 1;
            }
            ans += calc;
        }
        else
        {
            l = ones.back() + 1;
            ones.pop_back();
            if (!ones.empty())
            {
                calc = ones.back() - l + 1;
                ans += calc;
            }
            zcnt=0;
        }
        r++;
    }
    if(k==0&&zcnt!=0)
        ans+=((zcnt*(zcnt+1))/2);

    cout << ans;
    return 0;
}