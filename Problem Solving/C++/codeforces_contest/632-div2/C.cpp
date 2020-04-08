#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll cnt = (n*(n+1))/2;
    unordered_map<ll, vector<ll>> m;
    ll sum = 0;
    vector<pair<ll, ll>> out;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            out.push_back(make_pair(0, i));
        if (m.find(sum) != m.end())
        {
            vector<ll> vc = m[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }
        m[sum].push_back(i);
    }
    int x=0,y=0;
    for (int i = 0; i < out.size(); i++)
    {
        x=((n-1)-out[i].second)+1;
        y=out[i].first+1;
        cnt-=((x*y)+(y*x));
    }
    cout << cnt;

    return 0;
}
