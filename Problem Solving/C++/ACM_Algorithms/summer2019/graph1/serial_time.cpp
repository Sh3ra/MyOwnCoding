#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

queue<pair<ll, pair<ll, ll>>> q;
char gr[12][12][12];
bool vis[12][12][12];
ll cnt = 0;
ll k, n, m;

ll arrx[] = {1, -1, 0, 0, 0, 0};
ll arry[] = {0, 0, 1, -1, 0, 0};
ll arri[] = {0, 0, 0, 0, -1, 1};

void bfs(ll i, ll x, ll y)
{
    if (!vis[i][x][y])
    {

        vis[i][x][y] = true;
        cnt++;
        for (int w = 0; w < 6; w++)
        {
            ll nx = i + arrx[w], ny = x + arry[w], nz = y + arri[w];
            if (nx >= 0 && nx < k && ny >= 0 && ny < n && nz >= 0 && nz < m)
            {
                if (gr[nx][ny][nz] == '.' && !vis[nx][ny][nz])
                    q.push({nx, {ny, nz}});
            }
        }
    }
    if (!q.empty())
    {
        pair<ll, pair<ll, ll>> t = q.front();
        q.pop();
        bfs(t.first, t.second.first, t.second.second);
    }
}

int main(int argc, char const *argv[])
{
    cin >> k >> n >> m;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int w = 0; w < m; w++)
            {
                cin >> gr[i][j][w];
                vis[i][j][w] = false;
            }
        }
    }
    ll x, y;
    cin >> x >> y;
    x--, y--;
    bfs(0, x, y);
    cout << cnt;
    return 0;
}
