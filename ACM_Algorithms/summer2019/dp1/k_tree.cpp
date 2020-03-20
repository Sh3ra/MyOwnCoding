#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int k, d;
int counter = 0;
bool dp[101][101];
vector<int> data;
bool solve(int n, int w)
{
    if (n == 0)
    {
        if (count(data.begin(), data.end(), d))
        {
            counter++;
            data.pop_back();
            return true;
        }
        data.pop_back();
        return false;
    }
    if (dp[n][w])
    {
        if (count(data.begin(), data.end(), d))
        {
            counter++;
            data.pop_back();
            return true;
        }
        data.pop_back();
        return false;
    }
    for (int i = 1; i <= k; i++)
    {
        if (i <= n)
        {
            data.push_back(i);
            dp[n][i] = solve(n - i, i);
        }
    }
    return dp[n][w];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n >> k >> d;
    solve(n, 1);
    cout << counter;
    return 0;
}
