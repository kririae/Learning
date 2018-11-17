#include <bits/stdc++.h>
#define ll long long
#define inf (1ll << 60)
using namespace std;

const int N = 100005;
int n, m, A, X, B, Y, flag = 0, p[N], head[N], ver[N << 1], nxt[N << 1], tot;
ll f[N][2];
char s[5];
inline void addedge(int u, int v) {
	ver[tot] = v;
	nxt[tot] = head[u];
	head[u] = tot++;
}
inline void dfs(int x, int fa) {
	f[x][0] = 0;
	f[x][1] = p[x];
	for (int i = head[x], to; ~i; i = nxt[i]) {
		if ((to = ver[i]) == fa) continue;
		dfs(to, x);
		if ((x == A && to == B) || (to == A && x == B))
			if ((X || Y) == 0) return (void) (flag = 1);
		if (to == A) {
			if (X == 0) {
				if (f[to][X] == inf) return (void) (flag = 1);
				f[x][1] += f[to][X],
				f[x][0] = inf;
			} else 
				f[x][1] += f[to][X],
				f[x][0] += f[to][X];
		} else if (to == B) {
			if (Y == 0) {
				if (f[to][Y] == inf) return (void) (flag = 1);
				f[x][1] += f[to][Y],
				f[x][0] = inf;
			} else 
				f[x][1] += f[to][Y],
				f[x][0] += f[to][Y];
		} else {
			f[x][1] += min(f[to][0], f[to][1]);
			f[x][0] += f[to][1];
		}
	}
}
int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	memset(head, -1, sizeof head);
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	if (s[2] == '1') {
		dfs(1, 0);
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d%d%d", &A, &X, &B, &Y);
			cout << f[1][1] << endl;
		}
		return 0;
  }
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d%d", &A, &X, &B, &Y);
		flag = 0;
		memset(f, 0, sizeof f);
		dfs(1, 0);
		if (flag == 1)
	 		cout << -1 << endl;
		else {
			if (A == 1)
				cout << f[1][X] << endl;
			else if (B == 1)
				cout << f[1][Y] << endl;
			else cout << min(f[1][0], f[1][1]) << endl;
		}
	}
}
