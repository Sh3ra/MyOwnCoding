#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int n, q, cum[N][26];
char s[N + 1];

inline long long calc(int k, int ch) {
	long long res = 1LL * k / n * cum[n - 1][ch];
	if (k % n != 0)
		res += cum[k % n - 1][ch];
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%s", &n, &q, s);
		memset(cum[0], 0, sizeof cum[0]);
		++cum[0][s[0] - 'a'];
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 26; ++j)
				cum[i][j] = cum[i - 1][j];
			++cum[i][s[i] - 'a'];
		}
		int l, r;
		char c;
		while (q-- != 0) {
			scanf("%d%d %c", &l, &r, &c);
			printf("%lld\n", calc(r, c - 'a') - calc(l - 1, c - 'a'));
		}
	}
	return 0;
}
