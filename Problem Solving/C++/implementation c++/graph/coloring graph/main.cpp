#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
int n, m;
const int N = 1e5 + 10;
int a[N], b[N]; char c[N];

int f[N], r[N];
inline int find(int x) {
	if (f[x] != x) {
		find(f[x]), r[x] ^= r[f[x]], f[x] = f[f[x]];
	}
	return f[x];
}

vector<int> nd[N][2], ans[2];

bool work(char C, int F) {
	rep(i,1,n) f[i] = i, r[i] = 0, ans[F].pb(i); ans[F].pb(233);
	rep(i,1,m) {
		int w = (c[i] == C);
		find(a[i]), find(b[i]);
		if (f[a[i]] == f[b[i]]) {
			if (r[a[i]] ^ r[b[i]] ^ w) return false;
		} else {
			r[f[a[i]]] ^= r[a[i]] ^ w ^ r[b[i]];
			f[f[a[i]]] = f[b[i]];
		}
	}
	rep(i,1,n) nd[i][0].clear(), nd[i][1].clear();
	rep(i,1,n) {
		find(i);
		nd[f[i]][r[i]].pb(i);
	}
	ans[F].clear();
	rep(i,1,n) if (f[i] == i) {
		if (nd[i][0].size() < nd[i][1].size()) {
			int l = nd[i][0].size();
			Rep(j,l) ans[F].pb(nd[i][0][j]);
		} else {
			int l = nd[i][1].size();
			Rep(j,l) ans[F].pb(nd[i][1][j]);
		}
	}
	return true;
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,m) {
		scanf("%d%d",&a[i],&b[i]); c[i] = getchar();
		while (c[i] != 'B' && c[i] != 'R') c[i] = getchar();
	}

	bool f1 = work('B',0), f2 = work('R', 1);
	if (!f1 && !f2) printf("-1\n"); else {
		if (ans[0].size() < ans[1].size()) {
			cout <<ans[0].size()<<endl; int l = ans[0].size();
			Rep(i,l) printf("%d ",ans[0][i]);
		} else {
			cout <<ans[1].size()<<endl; int l = ans[1].size();
			Rep(i,l) printf("%d ",ans[1][i]);
		}
	}
	return 0;
}
