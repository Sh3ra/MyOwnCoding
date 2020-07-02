#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    ll a[n], ans[n];
    map<ll, ll> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ll ele = a[i];
        if (i == n - 1)
        {
            m[ele * -1] = i;
            ans[i] = -1;
            continue;
        }
        auto teto = m.upper_bound(ele * -1);
        if (teto != m.end())
        {
            ans[i] = (*teto).second - (i + 1);
            if (m[ele * -1] == 0)
                m[ele * -1] = (*teto).second;
        }
        else
        {
            ans[i] = -1;
            if (m[ele * -1] == 0)
                m[ele * -1] = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
