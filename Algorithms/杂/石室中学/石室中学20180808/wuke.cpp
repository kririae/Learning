// by kririae
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 1e5 + 5;
int n, q, siz, head[N], ver[N << 1], nxt[N << 1], tot;
int l = 1, r = 0, cnt = 0, ans[N];
struct req {
	int l, r, pos, id;
	bool operator < (const req &a) const {
		if(pos == a.pos) {
			if(pos & 1) return r < a.r;
			else return r > a.r;
		} else return pos < a.pos;
	}
} a[N];
inline void addedge(int u, int v) {
	ver[tot] = v;
	nxt[tot] = head[u];
	head[u] = tot++;
} // 探讨联通块的性质，以此入手。
inline void add(int x) {
	for (int i = head[x]; ~i; i = nxt[i])
		if(ver[i] >= l && ver[i] <= r) ++cnt;
}
inline void del(int x) {
	for (int i = head[x]; ~i; i = nxt[i])
		if(ver[i] >= l && ver[i] <= r) --cnt;
}
int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &q);
	siz = sqrt(n) + 1;
	for (int i = 1, a, b; i < n; ++i) {
		scanf("%d%d", &a, &b);
		addedge(a, b);
		addedge(b, a);
	} 
	for (int i = 1, l, r; i <= q; ++i) {
		scanf("%d%d", &l, &r);
		a[i].l = l, a[i].r = r;
		a[i].pos = (l / siz) + 1, a[i].id = i;
	}
	sort(a + 1, a + 1 + q);
	for (int i = 1; i <= q; ++i) {
		req &c = a[i];
		while(r > c.r) del(r), --r;
		while(r < c.r) ++r, add(r);
		while(l < c.l) del(l), ++l;
		while(l > c.l) --l, add(l);
		ans[c.id] = (r - l + 1) - cnt;
	}
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
}