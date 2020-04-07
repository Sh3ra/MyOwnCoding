#include <iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k, la, ra;
    cin >> n >> k;
    map<int, int> m;
    int arr[n + 1], l = 0, r = 0, x = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (k == 1)
    {
        cout << 1 << " " << 1;
        return 0;
    }
    int counter = 0;
    while (l < n - 1)
    {
        if (arr[l] != arr[l + 1])
            break;
        l++;
    }
    if (l == n - 1)
    {
        cout << -1 << " " << -1;
        return 0;
    }
    m[arr[l]] = 1;
    r = l + 1;
    m[arr[r]] = 1;
    counter = 2;
    while (counter < k)
    {
        if (r == n - 1)
        {
            cout << -1 << " " << -1;
            return 0;
        }
        if (m[arr[r]] == 0)
        {
            m[arr[r]] = 1;
            if (arr[r] != arr[l])
                counter++;
            else
            {
                while (l < n - 1&&m[arr[l]]==1)
                {
                    if (arr[l] != arr[l + 1])
                        break;
                    l++;
                }
                if (l == n - 1)
                {
                    cout << -1 << " " << -1;
                    return 0;
                }
            }
        }
        else
            r++;
    }
    x = r - l + 1;
    la = l;
    ra = r;
    while (r < n && l != r)
    {
        if (arr[r] == arr[r + 1] || m[arr[r]] == 1)
        {
            if (arr[l] == arr[r])
            {
                while (l < n - 1&&m[arr[l]]==1)
                {
                    if (arr[l] != arr[l + 1])
                        break;
                    l++;
                }
                if (l == n - 1)
                {
                    cout << -1 << " " << -1;
                    return 0;
                }
            }
            r++;
        }
        else
        {
            m[arr[r]] = 1;
            m[arr[l]] = 0;
            l++;
            if (x > r - l + 1)
            {
                x = r - l + 1;
                la = l;
                ra = r;
            }
        }
    }
    cout << la + 1 << " " << ra + 1;

    return 0;
}
