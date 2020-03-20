#include <iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    vector<pair<long long, long long>> v;
    vector<pair<long long, long long>> out;
    while (t--)
    {
        v.clear();
        out.clear();
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            v.push_back(make_pair(temp, i));
        }
        sort(v.begin(), v.end());
        if (m<n||n == 2)
        {
            cout << -1 << endl;
            continue;
        }
        long long cost = 0, counter = 0;
        for (int i = 0; i < n-1; i++)
        {
            cost += (v[i].first + v[i+1].first);
            out.push_back(make_pair(v[i].second + 1, v[i+1].second + 1));
            counter++;
        }
            cost += (v[0].first + v[n-1].first);
            out.push_back(make_pair(v[0].second + 1, v[n-1].second + 1));

        cout << cost << endl;
        for (int i = 0; i < m; i++)
            cout << out[i].first << " " << out[i].second << endl;
    }

    return 0;
}
