#include<cstdio>
#include<iostream>
#include<vector>
#define N 300005
using namespace std;
int n, m;
//树
vector<int> node[N];
int color[N], father[N], lca[N][18], deep[N], sons[N];
inline void addedge(int f, int t)
{
	node[f].push_back(t);
	node[t].push_back(f);
}
int getlca(int u, int v) //du>dv
{
	if(deep[u] < deep[v]) swap(u, v);
	int p = deep[u] - deep[v];
	int t = 0;
	while(p != 0) {
		if(p & 1)  u = lca[u][t];
		p >>= 1;
		t++;
	}
	if(u == v) return u;
	for(int i = 17; i >= 0; i--) {
		if(lca[u][i] != lca[v][i]) u = lca[u][i], v = lca[v][i];
	}
	return lca[u][0];
}
//链剖
int newname[N], xds[N], anc[N]; //anc-oldname
int DFS1(int u, int from, int deeps)
{
	father[u] = from;
	lca[u][0] = father[u];
	deep[u] = deeps;
	for(int i = 1; (1 << i) <= deeps; i++) lca[u][i] = lca[lca[u][i - 1]][i - 1];
	int hson = 0, hsize = 0;
	for(int i = 0, len = node[u].size(), t; i < len; i++) {
		if(node[u][i] == from) continue;
		t = DFS1(node[u][i], u, deeps + 1);
		if(t > hsize) hsize = t, hson = i;
		sons[u] += t;
	}
	swap(node[u][0], node[u][hson]);
	return ++sons[u];
}
int lpcnt;
void DFS2(int u, int ancestor)
{
	newname[u] = lpcnt++;
	xds[lpcnt - 1] = color[u];
	anc[u] = ancestor;
	for(int i = 0, len = node[u].size(), t; i < len; i++) {
		if(node[u][i] == father[u]) continue;
		if(i == 0) DFS2(node[u][i], ancestor);
		else DFS2(node[u][i], node[u][i]);
	}
}
//-----------苦逼的分割线------xds----------
int son[N << 1][2], start[N << 1], end[N << 1], side[N << 1][2], count[N << 1], dye[N << 1]; //side--两侧的颜色dye-lazy
int xdscnt, root;
const int L = 0, R = 1;
inline void update(const int &k)
{
	side[k][L] = side[son[k][L]][L];
	side[k][R] = side[son[k][R]][R];
	count[k] = count[son[k][L]] + count[son[k][R]];
	if(side[son[k][L]][R] == side[son[k][R]][L]) count[k]--;
}
void build(int &k, int st, int en)
{
	k = ++xdscnt;
	start[k] = st;
	end[k] = en;
	son[k][L] = son[k][R] = 0;
	dye[k] = -1;
	if(st == en) side[k][L] = side[k][R] = xds[st], count[k] = 1;
	else {
		int mid = (st + en) >> 1;
		build(son[k][L], st, mid);
		build(son[k][R], mid + 1, en);
		update(k);
	}
}
void xds_dye(int k, int fr, int to, int &c)
{
	if(fr == start[k] && to == end[k]) {
		dye[k] = c;
		count[k] = 1;
		side[k][L] = side[k][R] = c;
		if(fr == to) dye[k] = -1;
	} else {
		int mid = (start[k] + end[k]) >> 1; //push_down
		if(dye[k] != -1) xds_dye(son[k][L], start[k], mid, dye[k]), xds_dye(son[k][R], mid + 1, end[k], dye[k]), dye[k] = -1;
		if(fr <= mid) xds_dye(son[k][L], fr, min(mid, to), c);
		if(to > mid) xds_dye(son[k][R], max(mid + 1, fr), to, c);
		update(k);
	}
}
int xds_query(int k, int fr, int to)
{
	if(fr == start[k] && to == end[k]) {
		return count[k];
	} else {
		int mid = (start[k] + end[k]) >> 1; //push_down
		/*pushdown(k);*/
		if(dye[k] != -1) return 1;
		if(fr > mid) return xds_query(son[k][R], fr, to);
		else if(to <= mid) return xds_query(son[k][L], fr, to);
		else return xds_query(son[k][L], fr, mid) + xds_query(son[k][R], mid + 1, to) - (side[son[k][L]][R] == side[son[k][R]][L] ? 1 : 0);
	}
}
int xds_pquery(int k, int x) //单点查询
{
	if(start[k] == end[k]) {
		return side[k][L];
	} else {
		if(dye[k] != -1) return dye[k];
		int mid = (start[k] + end[k]) >> 1;
		if(x > mid) return xds_pquery(son[k][R], x);
		else if(x <= mid) return xds_pquery(son[k][L], x);
	}
}
//==========加强的rg的分割线=======下面是链剖的操作==========
void tree_dye(int a, int b, int c)
{
	int u = getlca(a, b);
	while(anc[a] != anc[u]) {
		xds_dye(root, newname[anc[a]], newname[a], c);
		a = anc[a];
		a = father[a];
	}
	xds_dye(root, newname[u], newname[a], c);
	while(anc[b] != anc[u]) {
		xds_dye(root, newname[anc[b]], newname[b], c);
		b = anc[b];
		b = father[b];
	}
	xds_dye(root, newname[u], newname[b], c);
}
int tree_query(int a, int b)
{
	int u = getlca(a, b);
	int ret = 0;
	while(anc[a] != anc[u]) {
		ret += xds_query(root, newname[anc[a]], newname[a]);
		a = anc[a];
		if(xds_pquery(root, newname[a]) == xds_pquery(root, newname[father[a]])) ret--;
		a = father[a];
	}
	while(anc[b] != anc[u]) {
		ret += xds_query(root, newname[anc[b]], newname[b]);
		b = anc[b];
		if(xds_pquery(root, newname[b]) == xds_pquery(root, newname[father[b]])) ret--;
		b = father[b];
	}
	if(a == u) ret += xds_query(root, newname[u], newname[b]);
	else ret += xds_query(root, newname[u], newname[a]);
	return ret;
}
//~~~~~~~~~~~~~~~~~~~~凌乱的分割线~~~~~~~~~~~~~~~~~~~~~
void init()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &color[i]);
	}
	for(int i = 1, f, t; i < n; i++) {
		scanf("%d%d", &f, &t);
		addedge(f, t);
	}
	lpcnt = 1;
	DFS1(1, 0, 0);
	DFS2(1, 1);
	build(root, 1, n);
}
int main()
{
	init();
	for(int i = 1; i <= m; i++) {
		char c = getchar();
		while(c != 'Q' && c != 'C') c = getchar();
		if(c == 'C') {
			int a, b, c2;
			scanf("%d%d%d", &a, &b, &c2);
			tree_dye(a, b, c2);
		} else {
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%d\n", tree_query(a, b));
		}
	}
	return 0;
}
