//代码能力蒟蒻的我来作大死
#include<bits/stdc++.h>
#define N 100005
#define LL long long
using namespace std;
struct edge {
	int t, next, dis;
} e[N * 2];
int ecnt, head[N];
void addedge(int f, int t, int dis) {
	e[++ecnt] = (edge) {
		t, head[f], dis
	};
	head[f] = ecnt;
	e[++ecnt] = (edge) {
		f, head[t], dis
	};
	head[t] = ecnt;
}
#define iter(i,x) for(int i=head[x];i;i=e[i].next)
int wei[N], vis[N], size[N], fa[N];
//----------------LCA-------------
int dis[N], ETTx[N * 2], ETcnt, show_pos[N];
void LCA_DFS(int u, int fr, int now_dis) {
	ETTx[++ETcnt] = u;
	dis[u] = now_dis;
	show_pos[u] = ETcnt;
	size[u] = 1;
	fa[u] = fr;
	iter(i, u) {
		if(e[i].t != fr) {
			LCA_DFS(e[i].t, u, now_dis + e[i].dis);
			ETTx[++ETcnt] = u;
			size[u] += size[e[i].t];
		}
	}
}
int ST[22][N * 2], LG[N * 2];
void pre_LCA() {
	LCA_DFS(1, 0, 0);

	for(int i = 1; i <= ETcnt; i++) ST[0][i] = dis[ETTx[i]];

	for(int i = 2; i <= ETcnt; i++) LG[i] = LG[i >> 1] + 1;

	for(int i = 1; (1 << i) <= ETcnt; i++)
		for(int j = 1 << i; j <= ETcnt; j++)
			ST[i][j] = min(ST[i - 1][j], ST[i - 1][j - (1 << (i - 1))]);
}
int get_dis(int f, int t) {
	if(f == t) return 0;

	if(show_pos[f] > show_pos[t]) swap(f, t);

	int d = LG[show_pos[t] - show_pos[f] + 1];
	int mn = min(ST[d][show_pos[t]], ST[d][show_pos[f] + (1 << d) - 1]);
	return dis[f] + dis[t] - 2 * mn;
}
//-------tree conquer-------------
int dtree_fa[N];//点分树结构
vector<LL> dsubtree_wei[N];
LL dsum_wei[N];//重量和
vector<LL> dsubtree_ans[N];
LL dsum_ans[N];//答案贡献
vector<int> belong[N];//属于哪颗子树

int buf_size[N];
void mark_DFS(int u, int bel, int fr) {
	buf_size[u] = 1;
	belong[u].push_back(bel);
	iter(i, u) {
		if(e[i].t != fr && vis[e[i].t] == 0) {
			mark_DFS(e[i].t, bel, u);
			buf_size[u] += buf_size[e[i].t];
		}
	}
}
int get_center(int u, int fr, int sum_size) {
	buf_size[u] = 1;
	int mx = 0;
	iter(i, u) {
		if(e[i].t != fr && vis[e[i].t] == 0) {
			int x = get_center(e[i].t, u, sum_size);

			if(x) return x;

			mx = max(mx, buf_size[e[i].t]);
			buf_size[u] += buf_size[e[i].t];
		}
	}
	mx = max(mx, sum_size - buf_size[u]);

	if(mx <= sum_size / 2) return u;

	return 0;
}

void divide(int start, int dfa, int size_now) {
	int center = get_center(start, 0, size_now), bcnt = 0;
	dsum_ans[center] = dsum_wei[center] = 0;
	dtree_fa[center] = dfa;
	vis[center] = 1;
	iter(i, center) {
		if(vis[e[i].t] == 0) {
			mark_DFS(e[i].t, dsubtree_ans[center].size(), center);
			dsubtree_ans[center].push_back(0);
			dsubtree_wei[center].push_back(buf_size[e[i].t]);
		}
	}
	iter(i, center) {
		if(vis[e[i].t] == 0) {
			divide(e[i].t, center, dsubtree_wei[center][bcnt]);
			dsubtree_wei[center][bcnt++] = 0;
		}
	}
}
void modify1(int u, int dwei) {
	dsum_wei[u] += dwei;

	for(int x = dtree_fa[u], p = belong[u].size() - 1; x != 0; x = dtree_fa[x], p--) {
		LL delta = dwei * 1LL * get_dis(u, x);
		dsum_wei[x] += dwei;
		dsum_ans[x] += delta;
		dsubtree_wei[x][belong[u][p]] += dwei;
		dsubtree_ans[x][belong[u][p]] += delta;
	}
}
LL query_cost(int u) {
	LL ret = dsum_ans[u];

	for(int x = dtree_fa[u], p = belong[u].size() - 1; x != 0; x = dtree_fa[x], p--)
		ret += (dsum_ans[x] - dsubtree_ans[x][belong[u][p]]) + (dsum_wei[x] - dsubtree_wei[x][belong[u][p]]) * get_dis(u, x);

	return ret;
}
//-------------tree chain---------
int DFSx[N], dcnt, ch_pos[N];
int top[N];
void DFS2(int u, int fr, int tp) {
	top[u] = tp;
	DFSx[++dcnt] = u;
	ch_pos[u] = dcnt;

	if(size[u] == 1) return;

	int mx_size = 0, mx_son = 0;
	iter(i, u)

	if(e[i].t != fr && mx_size < size[e[i].t]) mx_size = size[e[i].t], mx_son = e[i].t;

	DFS2(mx_son, u, tp);
	iter(i, u)

	if(e[i].t != fr && e[i].t != mx_son) {
		DFS2(e[i].t, u, e[i].t);
	}
}

struct xds {
	int l, r, son[2];
	int mx, add_tag, id;
} a[N * 2];
int acnt;
const int L = 0, R = 1;
void pushdown(int k) {
	if(a[k].son[L] != 0 && a[k].add_tag != 0) {
		xds &l = a[a[k].son[L]], &r = a[a[k].son[R]];
		int &t = a[k].add_tag;
		l.mx += t, r.mx += t, l.add_tag += t, r.add_tag += t;
		t = 0;
	}
}
void update(int k) {
	a[k].mx = max(a[a[k].son[L]].mx, a[a[k].son[R]].mx);
}
void add(int k, int l, int r, int val) {
	pushdown(k);

	if(a[k].l == l && a[k].r == r) {
		a[k].mx += val;
		a[k].add_tag += val;
		return;
	}

	int mid = (a[k].l + a[k].r) >> 1;

	if(l > mid) add(a[k].son[R], l, r, val);
	else if(r <= mid) add(a[k].son[L], l, r, val);
	else add(a[k].son[L], l, mid, val), add(a[k].son[R], mid + 1, r, val);

	update(k);
}
int query_pos(int k, int key) {
	if(a[k].l == a[k].r) return a[k].id;

	pushdown(k);

	if(2 * a[a[k].son[R]].mx >= key) return query_pos(a[k].son[R], key);
	else return query_pos(a[k].son[L], key);
}

void build(int &k, int l, int r) {
	k = ++acnt;
	a[k].l = l;
	a[k].r = r;

	if(l != r) {
		int mid = (l + r) >> 1;
		build(a[k].son[L], l, mid), build(a[k].son[R], mid + 1, r);
	} else a[k].id = DFSx[l];
}

int root;
void chain_pre() {
	DFS2(1, 0, 1);
	build(root, 1, dcnt);
}
void modify2(int u, int dwei) {
	while(u != 0) {
		add(root, ch_pos[top[u]], ch_pos[u], dwei);
		u = fa[top[u]];
	}

	wei[u] += dwei;
}
//--------------------------------
int n, m;
void read_in() {
	scanf("%d%d", &n, &m);

	for(int i = 2, f, t, d; i <= n; i++) scanf("%d%d%d", &f, &t, &d), addedge(f, t, d);
}
int main() {
	read_in();
	divide(1, 0, n);
	pre_LCA();
	chain_pre();

	for(int i = 1, sum = 0; i <= m; i++) {
		int x, v;
		scanf("%d%d", &x, &v);
		sum += v;
		modify1(x, v);
		modify2(x, v);
		printf("%lld\n", query_cost(query_pos(root, sum)));
	}

	return 0;
}
