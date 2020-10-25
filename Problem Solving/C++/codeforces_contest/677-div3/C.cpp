#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        ll ans = 0, indx, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (ans != 0 && arr[indx + 1] == arr[indx])
            {
                if (indx > 0)
                {
                    if (arr[indx - 1] == arr[indx])
                        ans = 0;
                }
                else
                    ans = 0;
            }
            if (arr[i] > ans)
            {
                ans = arr[i];
                indx = i;
                cnt = 0;
            }
            else if (ans == arr[i])
            {
                cnt++;
            }
        }
        ll te=arr[0];
        cnt=0;
        for (int i = 1; i < n; i++)
        {
            if(arr[i]==te)
            {
                cnt++;
            }
        }
        
        if (cnt != n - 1)
            cout << indx + 1 << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}
