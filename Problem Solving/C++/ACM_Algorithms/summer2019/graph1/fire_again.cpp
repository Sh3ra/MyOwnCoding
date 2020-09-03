#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
pair<ll, ll> an;
map<pair<ll, ll>, bool> lit;
queue<pair<ll, ll>> q;
ll x[] = {0, 1, 0, -1};
ll y[] = {1, 0, -1, 0};
void bfs(pair<ll, ll> node, ll n, ll m)
{
    lit[node] = true;
    an = node;
    for (int i = 0; i < 4; i++)
    {
        pair<ll, ll> temp = node;
        temp.first += x[i];
        temp.second += y[i];
        if (temp.first > 0 && temp.first <= n && temp.second > 0 && temp.second <= m)
        {
            if (!lit[temp])
            {
                q.push(temp);
            }
        }
    }
    if (!q.empty())
    {
        pair<ll, ll> temp = q.front();
        q.pop();
        bfs(temp, n, m);
    }
}

int main(int argc, char const *argv[])
{
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;
    ll k;
    cin >> k;
    vector<pair<ll, ll>> ks;
    for (int i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        ks.push_back({x, y});
        lit[{x, y}] = true;
        if (i > 0)
        {
            q.push({x, y});
        }
    }
    bfs(ks[0], n, m);
    cout << an.first << " " << an.second;

    return 0;
}
