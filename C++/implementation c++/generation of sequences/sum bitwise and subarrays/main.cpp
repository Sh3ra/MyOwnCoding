#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 100000 + 10;
int t, n, a[N];
ll ans;
int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		for (int k = 0; k <= 20; ++k) {
			int cnt = 0;
			for (int i = 0, v; i < n; ++i) {
				v = (a[i] >> k) & 1;
				if (v) {
					++cnt;
				}
				else {
					ans += (ll)cnt * (cnt + 1) / 2 * (1 << k);
					cnt = 0;
				}
			}
			ans += (ll)cnt * (cnt + 1) / 2 * (1 << k);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
