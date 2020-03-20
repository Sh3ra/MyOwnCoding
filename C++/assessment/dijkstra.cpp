#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <math.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll r, c;
    ll mm = INT_MAX;
map<ll, pair<ll, ll>> indexes;
vector<ll> dist;
vector<ll> used;
ll myMin;
void dijkstra(vector<vector<pair<ll, ll>>> &graph, ll src, ll n)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> minQueue;
    ll distance, current;
    for (ll i = 0; i < n; i++)
        dist.push_back(INT_MAX);
    dist[src] = 0;
    minQueue.push(make_pair(0, src));
    pair<ll, ll> temp;
    while (minQueue.size())
    {
        temp = minQueue.top();
        minQueue.pop();
        current = temp.second;
        distance = temp.first;
        if ((current >= (c - 1) && (current + 1) % c == 0)||dist[current]>mm)
        {
            myMin = dist[current];
            return;
        }
        if (used[current])
            continue;
        used[current] = 1;
        for (ll v = 0; v < graph[current].size(); v++)
        {
            if (dist[graph[current][v].second] > max(dist[current], graph[current][v].first))
                dist[graph[current][v].second] = max(dist[current], graph[current][v].first);
            minQueue.push(make_pair(graph[current][v].first, graph[current][v].second));
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> r >> c;
    ll arr[r][c];
    ll index = 0;
    ll n = r * c;
    vector<vector<pair<ll, ll>>> graph;
    graph.resize(n);
    used.resize(n);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            indexes[index] = make_pair(i, j);
            if (j > 0)
            {
                graph[index].push_back(make_pair(max(arr[indexes[index - 1].first][indexes[index - 1].second], arr[indexes[index].first][indexes[index].second]), index - 1));
                graph[index - 1].push_back(make_pair(max(arr[indexes[index - 1].first][indexes[index - 1].second], arr[indexes[index].first][indexes[index].second]), index));
            }
            if (i > 0)
            {
                graph[index].push_back(make_pair(max(arr[indexes[index - c].first][indexes[index - c].second], arr[indexes[index].first][indexes[index].second]), index - c));
                graph[index - c].push_back(make_pair(max(arr[indexes[index - c].first][indexes[index - c].second], arr[indexes[index].first][indexes[index].second]), index));
            }
            index++;
        }
    }
    for (int i = 0; i < n; i += c)
    {
        if (arr[indexes[i].first][indexes[i].second] > mm)
            continue;
        used.clear();
        used.resize(n);
        dijkstra(graph, i, n);
        mm = min(mm, myMin); 
    }
    cout << mm;
    return 0;
}
