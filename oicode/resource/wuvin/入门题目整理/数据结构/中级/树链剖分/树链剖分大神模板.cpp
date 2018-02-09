#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 0x7fffffff
#define N 30005
#define M 60005
using namespace std;
int n, q, cnt, sz;
int fa[N][15], v[N], deep[N], size[N], head[N];
int pos[N], belong[N];
bool vis[N];
struct data {
	int to, next;
} e[M];
struct seg {
	int l, r, mx, sum;
} t[100005];
void insert(int u, int v)
{
	e[++cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
	e[++cnt].to = u;
	e[cnt].next = head[v];
	head[v] = cnt;
}
void ini()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		insert(x, y);
	}
	for(int i = 1; i <= n; i++)scanf("%d", &v[i]);
}
void dfs1(int x)
{
	size[x] = 1;
	vis[x] = 1;
	for(int i = 1; i <= 14; i++) {
		if(deep[x] < (1 << i))break;
		fa[x][i] = fa[fa[x][i - 1]][i - 1]; //倍增处理祖先信息
	}
	for(int i = head[x]; i; i = e[i].next) {
		if(vis[e[i].to])continue;
		deep[e[i].to] = deep[x] + 1;
		fa[e[i].to][0] = x;
		dfs1(e[i].to);
		size[x] += size[e[i].to];
	}
}
void dfs2(int x, int chain)
{
	int k = 0;
	sz++;
	pos[x] = sz; //分配x结点在线段树中的编号
	belong[x] = chain;
	for(int i = head[x]; i; i = e[i].next)
		if(deep[e[i].to] > deep[x] && size[e[i].to] > size[k])
			k = e[i].to; //选择子树最大的儿子继承重链
	if(k == 0)return;
	dfs2(k, chain);
	for(int i = head[x]; i; i = e[i].next)
		if(deep[e[i].to] > deep[x] && k != e[i].to)
			dfs2(e[i].to, e[i].to); //其余儿子新开重链
}
int lca(int x, int y) //求lca
{
	if(deep[x] < deep[y])swap(x, y);
	int t = deep[x] - deep[y];
	for(int i = 0; i <= 14; i++)
		if(t & (1 << i))x = fa[x][i];
	for(int i = 14; i >= 0; i--)
		if(fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	if(x == y)return x;
	else return fa[x][0];
}
void build(int k, int l, int r) //建线段树
{
	t[k].l = l;
	t[k].r = r;
	if(l == r)return;
	int mid = (l + r) >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
}
void change(int k, int x, int y) //线段树单点修改
{
	int l = t[k].l, r = t[k].r, mid = (l + r) >> 1;
	if(l == r) {
		t[k].sum = t[k].mx = y;
		return;
	}
	if(x <= mid)change(k << 1, x, y);
	else change(k << 1 | 1, x, y);
	t[k].sum = t[k << 1].sum + t[k << 1 | 1].sum;
	t[k].mx = max(t[k << 1].mx, t[k << 1 | 1].mx);
}
int querysum(int k, int x, int y) //线段树区间求和
{
	int l = t[k].l, r = t[k].r, mid = (l + r) >> 1;
	if(l == x && y == r)return t[k].sum;
	if(y <= mid)return querysum(k << 1, x, y);
	else if(x > mid)return querysum(k << 1 | 1, x, y);
	else {
		return querysum(k << 1, x, mid) + querysum(k << 1 | 1, mid + 1, y);
	}
}
int querymx(int k, int x, int y) //线段树区间求最大值
{
	int l = t[k].l, r = t[k].r, mid = (l + r) >> 1;
	if(l == x && y == r)return t[k].mx;
	if(y <= mid)return querymx(k << 1, x, y);
	else if(x > mid)return querymx(k << 1 | 1, x, y);
	else {
		return max(querymx(k << 1, x, mid), querymx(k << 1 | 1, mid + 1, y));
	}
}
int solvesum(int x, int f)
{
	int sum = 0;
	while(belong[x] != belong[f]) { //不在一条重链上就将x跳到链首，走一条轻边，如此反复
		sum += querysum(1, pos[belong[x]], pos[x]);
		x = fa[belong[x]][0];
	}
	sum += querysum(1, pos[f], pos[x]);
	return sum;
}
int solvemx(int x, int f)
{
	int mx = -inf;
	while(belong[x] != belong[f]) {
		mx = max(mx, querymx(1, pos[belong[x]], pos[x]));
		x = fa[belong[x]][0];
	}
	mx = max(mx, querymx(1, pos[f], pos[x]));
	return mx;
}
void solve()
{
	build(1, 1, n);
	for(int i = 1; i <= n; i++)
		change(1, pos[i], v[i]);
	scanf("%d", &q);
	char ch[6];
	for(int i = 1; i <= q; i++) {
		int x, y;
		scanf("%s%d%d", ch, &x, &y);
		if(ch[0] == 'C') {
			v[x] = y;
			change(1, pos[x], y);
		} else {
			int t = lca(x, y);
			if(ch[1] == 'M')
				printf("%d\n", max(solvemx(x, t), solvemx(y, t)));
			else
				printf("%d\n", solvesum(x, t) + solvesum(y, t) - v[t]);
		}
	}
}
int main()
{
	ini();
	dfs1(1);
	dfs2(1, 1);
	solve();
	return 0;
}
