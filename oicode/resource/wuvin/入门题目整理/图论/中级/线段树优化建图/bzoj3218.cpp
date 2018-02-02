/*
特NB可持久化线段树构图
我为什么不写一个优化网络流构图的函数
黑和白可以集合到一个点不然是错的
我今天才知道，自己画一画就是了，还是按照线规的方式建图靠谱啊
VFK的样例也不靠谱
此题如果采用前向星可以快到1.5s
如果采用isap可以在快到0.5s
如果再优化构图，可以快到0.3s
真是vector+Dinic太蛋疼了6.5s啊！
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define N 250005
#define ints unsigned int
using namespace std;
//-------------------------------------------------------------
char ccc;
int retdr, fh;
inline int read()
{
	ccc = getchar();
	fh = 1, retdr = 0;
	while(ccc < '0' || ccc > '9') {
		if(ccc == '-') fh = -1;
		ccc = getchar();
	}
	while(ccc >= '0' && ccc <= '9') retdr = retdr * 10 + ccc - '0', ccc = getchar();
	return retdr * fh;
}
//-------------------------------------------------------------
const int INF = 99999999;
int S, T, sz;
struct edge {
	int from, to, flow;
};
vector<edge> e;
int e_len = 0;
vector<int> node[N];
inline void addedge(int from, int to, int flow)
{
	e.push_back((edge) {
		from, to, flow
	});
	node[from].push_back(e_len++);
	e.push_back((edge) {
		to, from, 0
	});
	node[to].push_back(e_len++);
}
int dis[N], cur[N]; //分层图
queue<int> x;
bool BFS() //分层
{
	memset(dis, 0, sizeof(int) * (sz + 2));
	dis[S] = 1;
	x.push(S);
	while(!x.empty()) {
		int u = x.front();
		x.pop();
		for(int i = 0, len = node[u].size(); i < len; i++) {
			edge& ed = e[node[u][i]];
			if(dis[ed.to] != 0 || ed.flow == 0) continue;
			dis[ed.to] = dis[u] + 1;
			x.push(ed.to);
		}
	}
	return dis[T] != 0;
}
int DFS(int u, int a) //多路增广  a-可行流
{
	if(u == T || a == 0) return a;
	int flow = 0;
	for(int &i = cur[u], len = node[u].size(); i < len; i++) { //pay attention to &i
		edge& ed = e[node[u][i]];
		if(dis[ed.to] != dis[u] + 1 || ed.flow == 0) continue;
		int f = DFS(ed.to, min(a, ed.flow));
		if(f) {
			a -= f;
			flow += f;
			ed.flow -= f;
			e[node[u][i] ^ 1].flow += f;
			if(a == 0) return flow;
		}
	}
	return flow;
}
ints Dinic()
{
	ints maxflow = 0;
	while(BFS()) {
		memset(cur, 0, sizeof(int) * (sz + 2));
		maxflow += DFS(S, INF);
	}
	return maxflow;
}
//-----------------------------------------------------------------
int n, cnt, valsz;
ints sumb, sumw;
int *lsh[5005 * 3];
int lscnt;
struct block {
	int a, b, w, l, r, p;
} bl[5005];
//-----------------------------------------------------------------
inline int c(int x, int color) //0-white 1-black
{
	return x + color * n;
}
void init()
{
	n = read();
	lscnt = 0;
	for(int i = 1; i <= n; i++) {
		bl[i].a = read();
		bl[i].b = read();
		bl[i].w = read();
		bl[i].l = read();
		bl[i].r = read();
		bl[i].p = read();
		lsh[++lscnt] = &bl[i].a;
		lsh[++lscnt] = &bl[i].l;
		lsh[++lscnt] = &bl[i].r;
		sumb += bl[i].b;
		sumw += bl[i].w;
	}
}
inline bool cmp(int *a, int *b)
{
	return (*a) < (*b);
}
void dolsh()
{
	sort(lsh + 1, lsh + lscnt + 1, cmp);
	for(int i = 1, last = -100; i <= lscnt; i++)
		if(*lsh[i] != last) last = *lsh[i], *lsh[i] = ++valsz;
		else *lsh[i] = valsz;
}
//-----------------------------------------------------------------
struct xdsjyl {
	int son[2], name;
} xds[225005];
const int L = 0, R = 1;
int xdscnt;
void insert(int &k, int fr, int to, int v, int cnn)
{
	int t = ++xdscnt;
	xds[t].son[L] = xds[k].son[L];
	xds[t].son[R] = xds[k].son[R];
	xds[t].name = ++cnt;
	if(k) addedge(xds[t].name, xds[k].name, INF);
	k = t;
	if(fr == to) {
		addedge(xds[t].name, cnn, INF);
	} else {
		int mid = (fr + to) >> 1;
		if(v <= mid) insert(xds[t].son[L], fr, mid, v, cnn), addedge(xds[t].name, xds[xds[t].son[L]].name, INF);
		else insert(xds[t].son[R], mid + 1, to, v, cnn), addedge(xds[t].name, xds[xds[t].son[R]].name, INF);
	}
}
void connect_to(int k, int fr, int to, int vfr, int vto, int cnn)
{
	if(k == 0) return;
	if(vfr == fr && to == vto) {
		addedge(cnn, xds[k].name, INF);
	} else {
		int mid = (fr + to) >> 1;
		if(vfr > mid) connect_to(xds[k].son[R], mid + 1, to, vfr, vto, cnn);
		else if(vto <= mid) connect_to(xds[k].son[L], fr, mid, vfr, vto, cnn);
		else connect_to(xds[k].son[L], fr, mid, vfr, mid, cnn), connect_to(xds[k].son[R], mid + 1, to, mid + 1, vto, cnn);
	}
}
//-----------------------------------------------------------------
void buildmap()
{
	int root = 0;
	for(int i = 1; i <= n; i++) {
		int p = ++cnt; //addedge(c(i,1),p,bl[i].p);
		addedge(i, p, bl[i].p);
		connect_to(root, 1, valsz, bl[i].l, bl[i].r, p);
		insert(root, 1, valsz, bl[i].a, i);
		addedge(S, i, bl[i].b);
		//addedge(S,c(i,1),bl[i].b);addedge(c(i,1),c(i,0),INF);
		addedge(i, T, bl[i].w);
	}
	sz = cnt;
}
//-----------------------------------------------------------------
int main()
{
	init();
	dolsh();//离散化
	S = n + 1;
	T = n + 2;
	cnt = n + 2;
	buildmap();
	ints ans = sumb + sumw - Dinic();
	cout << ans;
	return 0;
}
