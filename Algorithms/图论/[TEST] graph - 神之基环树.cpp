// by kririae
// 代码实现难度 inf
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
struct Edge {
 int x, fa;
 Edge(int _t, int _f) : x(_t), fa(_f) {}
};
int n, m, a[N], tot, head[N], 
ver[N << 1], nxt[N << 1], from[N << 1],
on[N], out[N], in[N], 
vis[N << 1], tmp[N]; ll all, s1[N], s2[N], val[N];
queue<Edge> q, qw;
inline void addedge(int u, int v) {
	ver[tot] = v;
	nxt[tot] = head[u];
	from[tot] = u;
	head[u] = tot++;
	out[u]++;
}
int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	for (int i = 1, u, v; i <= m; ++i)
		scanf("%d%d", &u, &v), 
		addedge(u, v), addedge(v, u);
	if(m > n || m < n - 1) return puts("0"), 0;
	for (int i = 1; i <= n; ++i) 
		if(out[i] == 1) q.push(Edge(i, 0));
	while(!q.empty()) {
		Edge c = q.front(); q.pop();
		for (int i = head[c.x], to; ~i; i = nxt[i]) {
			if((to = ver[i]) == c.fa) continue;
			--out[to];
			if(!val[(i >> 1) + 1]) {
				val[(i >> 1) + 1] = (a[c.x] << 1) - in[c.x];
				in[to] += val[(i >> 1) + 1];
				if(out[to] == 1) q.push(Edge(to, c.x));
			}
		}
	} // 处理出环外的每一条边边权。处理结束后，out[i] > 1的就是环上的点。
	if(m == n - 1) {
		for (int i = 1; i <= m; ++i) printf("%lld\n", val[i]);
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if(out[i] > 1) {
			a[i] = (a[i] - in[i]) << 1;
			tmp[++cnt] = i, all += a[i];
		}
	if(cnt % 2 == 0) return puts("0"), 0;
	all >>= 1; s1[1] = a[1];
	for (int i = 3; i <= cnt; i += 2) 
		s1[i] = s1[i - 2] + a[i];
	for (int i = 2; i <= cnt; i += 2) 
		s2[i] = s2[i - 2] + a[i]; 
	// 奇数点和偶数点的和。
	for (int i = 0; i < tot; i += 2)
		if(from[i] == tmp[1] && ver[i] == tmp[cnt])
			val[(i >> 1) + 1] = all - s2[cnt - 1], 
			qw.push(Edge(from[i], i)), qw.push(Edge(ver[i], i));
	// 求出一个了，之后的慢慢求吧。。。
	while(!qw.empty()) {
		Edge c = qw.front();
		qw.pop();
		for (int i = head[c.x], to; ~i; i = nxt[i]) {
			if(out[to = ver[i]] <= 1) continue; // 筛选出在边上的点。
			if(val[(i >> 1) + 1]) continue;
			val[(i >> 1) + 1] = a[c.x] - val[c.fa];
			q.push(Edge(to, i));
		}
	}
	for (int i = 1; i <= m; ++i) printf("%lld\n", val[i]);
}