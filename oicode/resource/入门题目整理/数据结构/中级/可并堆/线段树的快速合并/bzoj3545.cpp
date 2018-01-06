//我完全不知道我wa哪了
//快调疯了
#include<cstdio>
#include<algorithm>
#define X 5000005
#define N 100005
using namespace std;
const int INF = 1000000005;
int n, m, q, root[N], cnt;
//-----------------
int bcj[N];
int ff(int x) {
	return bcj[x] == x ? x : bcj[x] = ff(bcj[x]);
}
inline void connect(int f, int t) {
	bcj[ff(f)] = ff(t);
}
//---------xds----------
const int L = 0, R = 1;
struct node {
	int size, son[2];
} xds[X];
void build(int &k, int fr, int to, int x) {
	k = ++cnt;
	xds[k].size = 1;

	if(fr == to) return;

	int mid = (fr + to) / 2;

	if(mid < x) build(xds[k].son[R], mid + 1, to, x);
	else build(xds[k].son[L], fr, mid, x);
}
int kth(int k, int fr, int to, int x) {
	if(fr == to) return fr;

	int mid = (fr + to) / 2;
	int t = xds[xds[k].son[R]].size;

	if(x <= t) return kth(xds[k].son[R], mid + 1, to, x);
	else return kth(xds[k].son[L], fr, mid, x - t);
}
int merge(int x, int y) {
	if(x == 0) return y;

	if(y == 0) return x;

	xds[x].size += xds[y].size;
	xds[x].son[L] = merge(xds[x].son[L], xds[y].son[L]);
	xds[x].son[R] = merge(xds[x].son[R], xds[y].son[R]);
	return x;
}
//-------------------
struct edge {
	int f, t, dis;
	bool operator<(const edge & ed)const {
		return dis < ed.dis;
	}
} e[N * 5];
struct query {
	int v, x, k, ans;
} qu[N * 5];
//----------------------------
inline int ask(int x) {
	int t = ff(qu[x].v);
	int t2 = qu[x].k;

	if(xds[root[t]].size < t2) {
		return -1;
	} else {
		return kth(root[t], -INF, INF, t2);
	}
}
inline void addedge(int k) {
	int f = ff(e[k].f), t = ff(e[k].t);

	if(f == t) return;

	connect(f, t);
	root[t] = merge(root[t], root[f]);
}
//--------------------------
int sor[N * 5];
bool cmp1(const int &a1, const int &a2) {
	return qu[a1].x < qu[a2].x;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);

	for(int i = 1; i <= n; i++) bcj[i] = i;

	for(int i = 1, t; i <= n; i++) { //可以离散化优化 空间
		scanf("%d", &t);
		build(root[i], -INF, INF, t);
	}

	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].f, &e[i].t, &e[i].dis);
	}

	for(int i = 1; i <= q; i++) {
		scanf("%d%d%d", &qu[i].v, &qu[i].x, &qu[i].k);
		sor[i] = i;
	}

	sort(e + 1, e + m + 1);
	sort(sor + 1, sor + q + 1);
	int l = 1, r = 1;

	while(r <= q) {
		if(e[l].dis <= qu[sor[r]].x && l <= m) {
			addedge(l);
			l++;
		} else {
			qu[sor[r]].ans = ask(sor[r]);
			r++;
		}
	}

	for(int i = 1; i <= q; i++) {
		printf("%d\n", qu[i].ans);
	}

	return 0;
}
