#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100005;
int n, m, K, p;
namespace SP {
int head[N], ver[N << 1], nxt[N << 1], 
edge[N << 1], dis[N], in[N], tot;
inline void init() {
	tot = 0;
	memset(head, -1, sizeof head);
	memset(ver, 0, sizeof ver);
	memset(nxt, 0, sizeof nxt);
	memset(edge, 0, sizeof edge);	
}
inline void addedge(int u, int v, int w) {
	ver[tot] = v;
	edge[tot] = w;
	++in[v];
	nxt[tot] = head[u];
	head[u] = tot++;
}
inline void SPFA(int s, int t) {
	static queue<int> q;
	static int vis[N];
	while (!q.empty()) q.pop();
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; ~i; i = nxt[i]) {
			int to = ver[i], v = edge[i];
			if (dis[u] + v < dis[to]) {
				dis[to] = dis[u] + v;
				if (!vis[to])
					vis[to] = 1,
					q.push(to);
			}
		}
	}
}
}
namespace DP {
int head[N], ver[N << 1], nxt[N << 1], flag, 
edge[N << 1], tot, f[N][55], vis[N][55];
inline void init() {
	tot = flag = 0;
	memset(head, -1, sizeof head);
	memset(ver, 0, sizeof ver);
	memset(nxt, 0, sizeof nxt);
	memset(edge, 0, sizeof edge);
	memset(f, 0, sizeof f);
}
inline void addedge(int u, int v, int w) {
	ver[tot] = v;
	edge[tot] = w;
	nxt[tot] = head[u];
	head[u] = tot++;
}
inline ll dfs(int x, int k) {
	if (vis[x][k]) 
		return flag = 1, -1;
	if (f[x][k])
		return f[x][k];
	f[x][k] = 0;
	vis[x][k] = 1;
	for (int i = head[x]; ~i; i = nxt[i]) {
		int to = ver[i];
		int dt = SP::dis[x] - SP::dis[to] + k - edge[i];
		if (dt < 0 || dt > K)
			continue;
		f[x][k] = (1ll * f[x][k] + dfs(to, dt)) % p;
	}
	vis[x][k] = 0;
	return f[x][k];
}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SP::init();
		DP::init();
		scanf("%d%d%d%d", &n, &m, &K, &p);
		for (int i = 1, ai, bi, ci; i <= m; ++i) {
			scanf("%d%d%d", &ai, &bi, &ci);
			SP::addedge(ai, bi, ci);
			DP::addedge(bi, ai, ci);
		}
		SP::SPFA(1, n);
		ll ans = 0;
		DP::f[1][0] = 1;
		for (int i = 0; i <= K; ++i)
			(ans += DP::dfs(n, i)) %= p;
		if (DP::flag == 0)
			printf("%lld\n", ans);
		else
			puts("-1");
	}
}