#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll cnt = 0;
        ll i = 1, total = 0;
        while (true)
        {
            ll x=total+i;
            total=(total+i)+total;
            if(total>n)
            break;
            if(i==1||i==2)
                cnt++;
            else if(x%4==0)
            cnt++;
            i++;
        }
        cout << cnt << endl;
    }
}