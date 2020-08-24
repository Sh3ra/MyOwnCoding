    #include <bits/stdc++.h>
    typedef long long ll;
     
    using namespace std;
     
    int main(int argc, char const *argv[])
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ll n, k;
        cin >> n >> k;
        ll arr[n + 1];
        arr[0] = 0;
        map<ll, ll> m;
        m[0]++;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll x = 1;
            if (k == 1)
            {
                x = 1;
                ans += m[arr[i] - x];
            }
            else if (k == -1)
            {
                x = 1;
                ans += m[arr[i] - x];
                x = -1;
                ans += m[arr[i] - x];
            }
            else
            {
                while (abs(x) < 1e15)
                {
                    if(m.find(arr[i] - x)!=m.end())
                        ans += m[arr[i] - x];
                    x *= k;
                }
            }
            m[arr[i]]++;
        }
        cout << ans;
    }