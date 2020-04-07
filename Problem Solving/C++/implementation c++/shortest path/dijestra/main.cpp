#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

int main()
{
    long long n,m;
    scanf("%I64d %I64d",&n,&m);
    int parent[n+1];
    vector<pair<long long, long long> > graph[n+1];
    for (long long i = 0; i < m; i++){
        long long from, to, weight;
        scanf("%I64d %I64d %I64d",&from,&to,&weight);
        graph[from].push_back(make_pair(to,weight));
        graph[to].push_back(make_pair(from,weight));
    }

    long long dist[n+1];
    bool vis[n+1];
    for (long long i = 1; i < n+1; i++){
        dist[i] = 1e18;
        vis[i] = false;
    }
    dist[1] = 0;
    set<pair<long long, long long> > S;
    S.insert(make_pair(dist[1],1));
    while (!S.empty()){

        long long node = S.begin()->second;
        long long timeTaken = S.begin()->first;
        S.erase(S.begin());


        if (node == n)
            break;

        if (vis[node])
            continue;
        vis[node] = true;

        for (long long i = 0; i < graph[node].size(); i++){
            long long to = graph[node][i].first;

            long long weight = graph[node][i].second;
            long long newTime = weight + dist[node];
            if (newTime < dist[to]){
                dist[to] = newTime;
                parent[to] = node;
                S.insert(make_pair(dist[to], to));
            }
        }
    }
    long long j=n , i=0;
    vector<int> t;
    if (dist[n] == 1e18){
        cout << "-1";
    }
    else{
    while (parent[j] != 1){
            t.push_back(parent[j]);
            j = parent[j];
            i++;

    }
    int arr[t.size()];
    std::copy(t.begin(), t.end(), arr);
     cout << "1 ";
    for ( int i =t.size() - 1; i >= 0; i--){
     cout << arr[i] << " ";
    }
    cout << n;
    }
