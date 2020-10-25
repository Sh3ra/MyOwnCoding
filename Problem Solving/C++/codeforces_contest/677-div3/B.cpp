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
        ll arr[n];
        ll cnt = 0;
        ll l = 0, r = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1 && cnt == 0)
                l = i, r = i;
            if (arr[i] == 1)
                cnt++;
        }
        while (r < n)
        {
            while (r < n && arr[r] == 1)
            {
                r++;
            }
            ll t=0;
            while (r < n && arr[r] == 0)
            {
                r++;
                t++;
            }
            if(r<n&&arr[r]==1)
                ans+=t;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
