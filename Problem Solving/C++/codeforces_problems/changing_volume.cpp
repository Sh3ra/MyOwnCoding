#include <iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, ans = 0;
        cin >> a >> b;
        long long diff = abs(a - b);
        if (diff > 0ll)
            ans += diff / 5ll;
        if (diff > 0ll&&diff/5ll!=0ll)
            diff -= (diff/5) * 5ll;
        if (diff > 0ll)
            ans += diff / 2ll;
        if (diff > 0&&diff/2ll!=0ll)

            diff -= (diff/2) * 2ll;
        if (diff > 0ll)

            ans += diff / 1ll;
        if (diff > 0&&diff/1ll!=0ll)

            diff -= (diff/1) * 1ll;

        cout << ans << endl;
    }

    return 0;
}
