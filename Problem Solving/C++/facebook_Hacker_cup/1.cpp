#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    ll cnt = 1;
    while (t--)
    {
        ll n;
        cin >> n;
        unordered_map<ll, bool> I;
        unordered_map<ll, bool> O;
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            if (c == 'Y')
                I[i] = true;
            else
                I[i] = false;
        }
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            if (c == 'Y')
                O[i] = true;
            else
                O[i] = false;
        }
        char ans[n][n];
        cout << "Case #" << cnt++ << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            ans[i][i] = 'Y';
            if (!O[i])
            {
                for (int j = 0; j < n; j++)
                {
                    ans[i][j] = 'N';
                    if (i == j)
                        ans[i][j] = 'Y';
                }
            }
            else
            {

                ll r = i + 1, l = i - 1;
                while (r < n || l > -1)
                {
                    if (r < n)
                    {
                        ans[i][r] = 'N';
                        if (I[r] && (ans[i][r - 1] == 'Y' && O[r - 1]))
                            ans[i][r] = 'Y';
                        r++;
                    }
                    if (l > -1)
                    {
                        ans[i][l] = 'N';
                        if (I[l] && (ans[i][l + 1] == 'Y' && O[l + 1]))
                            ans[i][l] = 'Y';
                        l--;
                    }
                }
            }
            for (int w = 0; w < n; w++)
            {
                cout << ans[i][w];
            }
            if (!(i + 1 == n && t == 0))
                cout << endl;
        }
    }

    return 0;
}