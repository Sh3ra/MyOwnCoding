#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[3];
int dp[4001];

int solve(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n - 1] != -1)
        return dp[n - 1];
    int res = INT_MIN;
    if (n >= a[0])
        res = max(res, solve(n - a[0]) + 1);
    if (n >= a[1])
        res = max(res, solve(n - a[1]) + 1);
    if (n >= a[2])
        res = max(res, solve(n - a[2]) + 1);
    return dp[n - 1] = res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n >> a[0] >> a[1] >> a[2];
    std::fill_n(dp, n, -1);
    cout << solve(n);
    return 0;
}
