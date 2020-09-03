#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

map<pair<ll, ll>, bool> m;
bool ans = false;
ll x[] = {0, 0, 1, -1, 1, -1, 1, -1, 0};
ll y[] = {1, -1, 0, 0, 1, -1, -1, 1, 0};
void dfs(ll i, ll j, ll cnt)
{
    if (m.find({i - cnt, j}) != m.end())
    {
        return;
    }
    if ((i == 0 && j == 7) || cnt > 7)
    {
        ans = true;
        return;
    }
    for (int k = 0; k < 9; k++)
    {
        ll nx = i + x[k], ny = j + y[k];
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
        {
            if (!(m.find({nx - cnt, ny}) != m.end()))
            {
                dfs(nx, ny, cnt + 1);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++)
        {
            if (s[j] == 'S')
                m[{i, j}] = true;
        }
    }
    dfs(7, 0, 0);
    cout << (ans ? "WIN" : "LOSE");
    return 0;
}
