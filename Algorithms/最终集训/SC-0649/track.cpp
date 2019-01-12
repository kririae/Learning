#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 50005;
int n, m;
int head[N], ver[N << 1], nxt[N << 1], edge[N << 1], tot;
int U[N], V[N], W[N];
inline void addedge(int u, int v, int w) {
	ver[tot] = v;
	edge[tot] = w;
	nxt[tot] = head[u];
	head[u] = tot++;
}
inline bool judge(ll x) {
;	
}
namespace Work20 {
int a[N];
inline int judge(ll mid) {
	ll sum = 0, ans = 0;
	for (int i = 1; i < n; ++i) {
		if (sum + a[i] >= mid)
			sum = 0, ++ans;
		else sum += a[i];
	}
	if (sum == 0)
		return ans >= m;
	if (sum < mid)
		if (ans >= m) return true;
		else return false;
}
inline void solve() {
	for (int i = 1; i < n; ++i)
		a[U[i]] = W[i];
	ll l = 0, r = 1ll * n * 10000, ans = -1;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (judge(mid))
			ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
}
}
namespace Work20_2 {
int vis[N]; ll dis[N];
inline void dfs(int x) {
	vis[x] = 1;
	for (int i = head[x], to; ~i; i = nxt[i]) {
		if (vis[to = ver[i]]) continue;
		dis[to] = dis[x] + edge[i];
		dfs(to);
	}
}
inline void solve() {
	memset(vis, 0, sizeof vis);
	dfs(1);
	ll mv = 0, p = 0;
	for (int i = 1; i <= n; ++i)
		if (dis[i] > mv) mv = dis[i], p = i;
	memset(vis, 0, sizeof vis);
	memset(dis, 0, sizeof dis);
	dfs(p);
	mv = 0;
	for (int i = 1; i <= n; ++i)
		mv = max(mv, dis[i]);
	cout << mv << endl;
}
}
namespace Work20_3 {
multiset<ll> st;
inline bool judge(ll mid) {
	st.clear();
	for (int i = 1; i < n; ++i)
		st.insert(W[i]);
	int ans = 0;
	while (!st.empty()) {
		ll x = *st.begin();
		st.erase(st.begin());
		if (st.empty()) break;
		multiset<ll>::iterator y = st.lower_bound(mid - x);
		if (y == st.end()) continue;
		if (x + *y >= mid) {
			++ans;
			st.erase(st.lower_bound(mid - x));
		}
		if (ans == m) return true;
	}
	return false;
}
inline void solve() {
	ll l = 0, r = 1ll * n * 10000, ans = -1;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (judge(mid))
			ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
}
}
int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	memset(head, -1, sizeof head);
	scanf("%d%d", &n, &m);
	int fg = 1, fg2 = 1;
	for (int i = 1, u, v, w; i < n; ++i) {
		scanf("%d%d%d", &U[i], &V[i], &W[i]);
		addedge(U[i], V[i], W[i]);
		addedge(V[i], U[i], W[i]);
		if (V[i] != U[i] + 1)
			fg = 0;
		if (U[i] != 1)
			fg2 = 0;
	}
	if (fg) {
		Work20::solve();
		return 0;
	}
	if (m == 1) {
		Work20_2::solve();
		return 0;
	}
	if (fg2) {
		Work20_3::solve();
		return 0;
	}
//	ll l = 0, r = 1ll * n * 10000;
//	while (l <= r) {
//		ll mid = (l + r) >> 1;
//		if (judge(mid)) {
//			;
//		}
//	}
  cout << 0 << endl;
}
/*
6 3
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
 */
 
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
 */
