#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<vector>
#define LL long long
#define db double
#define eps 1e-8
#define N 100005
using namespace std;
/*
T了
只有50分
*/
const int L = 0;
const int R = 1;
const int CIR = 1;
const int POL = 2;
const int POI = 3;
const int CHG = 4;
const int MOV = 5;
const int IN = 6;
const int OUT = 7;
struct point {
	db x, y;
};
struct seg {
	point a, b;
};
inline char getc() {
	char c = getchar();

	while(c < 'A' || c > 'Z') c = getchar();

	return c;
}
inline point operator -(const point &a, const point &b) {
	return (point) {
		a.x - b.x, a.y - b.y
	};
}
inline db getdis(point &a, point &b) {
	point c = a - b;
	return sqrt(c.x * c.x + c.y * c.y);
}
inline bool equ(db a, db b) {
	return fabs(a - b) < eps;
}
inline db cross(point a, point b) {
	return a.x * b.y - b.x * a.y;
}
inline bool onleft(const point &o, const point &a, const point &b) {
	return cross(a - o, b - o) > eps;
}
point p0;
inline bool cmp1(const point &a, const point &b) {
	return cross(a - p0, b - p0) < -eps;
}
///////////////////////////////////////////库
struct graph { //本题不卡内存，不知卡不卡常数
	int kind, v, father, tree_name; //father 树上父亲
	//--------point------//该图形中的一个点
	point p;
	//--------circle-----//
	db cx, cy, cr; //circle
	//--------polygon---//
	int size;
	point t[36];
	//-------常规维护，上左右-----//
	db left, right, top, bot;
	//---------支持的函数----------//
	void pre() {
		if(kind == CIR) {
			p = (point) {
				cx, cy
			};
			left = cx - cr;
			right = cx + cr;
			top = cy + cr;
			bot = cy - cr;
		} else if(kind == POI) {
			left = right = p.x;
			top = bot = p.y;
		} else if(kind == POL) {
			p = t[0]; //t[0]为基准点
			left = right = t[0].x;
			top = bot = t[0].y;

			for(int i = 1; i < size; i++) {
				left = min(left, t[i].x);
				right = max(right, t[i].x);
				bot = min(bot, t[i].y);
				top = max(top, t[i].y);
			}

			p0 = t[0];
			sort(t + 1, t + size, cmp1);
		}
	}
	bool inside(point &k) {
		if(kind == POI) return false;

		if(kind == CIR) {
			if(getdis(k, p) < cr) return true;

			return false;
		} else if(kind == POL) {
			if((k.x < right - eps && k.x > left + eps) && (k.y < top - eps && k.y > bot + eps)) {
				int l = 1, r = size - 1;

				while(l + 1 < r) {
					int mid = (l + r) >> 1;

					if(onleft(t[0], t[mid], k)) {
						l = mid;
					} else {
						r = mid;
					}
				}

				return onleft(t[r], t[l], k);
			} else {
				return false;
			}
		}
	}
};
struct ins {
	int kind;
	int obj, v; //change
	int f, t; //move对应的graph
};
struct sc {
	int name, ins;
	db x, y;
	set<sc>::iterator father;
	bool operator <(const sc &b)const {
		if(equ(y, b.y)) {
			return name < b.name;
		}

		return y < b.y;
	}
};
inline bool cmpx(const sc &a, const sc &b) {
	if(a.ins == 0) return false;

	if(b.ins == 0) return true;

	return a.x < b.x;
}
//------------本题需要的坑---------------------
int n, m, cnt; //n-图形总数 m-操作
graph g[3 * N];
ins in[N];
sc sj[6 * N];
void scan() {
	for(int i = 0; i < cnt; i++) {
		int t = i;
		t <<= 1;
		sj[t].name = i;
		sj[t].ins = IN;
		sj[t].x = g[i].left;
		sj[t ^ 1].y = sj[t].y = g[i].top;
		sj[t ^ 1].name = i;
		sj[t ^ 1].ins = OUT;
		sj[t ^ 1].x = g[i].right;
	}

	sort(sj, sj + cnt * 2, cmpx);
	set<sc> x;

	for(int i = 0; i < (cnt << 1); i++) {
		if(sj[i].ins == IN) {
			set<sc>::iterator itr;
			pair<set<sc>::iterator, bool> pa = x.insert(sj[i]);

			if(pa.second == false) {
				while(1);
			} else {
				itr = pa.first;
			}

			itr++;

			while(itr != x.end() && !g[(*itr).name].inside(g[sj[i].name].p)) itr++;

			g[sj[i].name].father = (*itr).name;
		} else if(sj[i].ins == OUT) {
			x.erase(sj[i]);
		}
	}

	return;
}

void init() {
	cnt = 0;
	g[cnt].kind = CIR;
	g[cnt].cx = 0;
	g[cnt].cy = 0;
	g[cnt].cr = 1e30;
	g[cnt].v = 0;
	cnt++;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++) {
		char ins = getc();

		if(ins == 'C') {
			scanf("%lf%lf%lf%d", &g[cnt].cx, &g[cnt].cy, &g[cnt].cr, &g[cnt].v);
			g[cnt].kind = CIR;
		} else {
			scanf("%d", &g[cnt].size);

			for(int j = 0; j < g[cnt].size; j++) {
				scanf("%lf%lf", &g[cnt].t[j].x, &g[cnt].t[j].y);
			}

			g[cnt].kind = POL;
			scanf("%d", &g[cnt].v);
		}

		cnt++;
	}

	for(int i = 0; i < m; i++) {
		char ins = getc();

		if(ins == 'Q') {
			scanf("%lf%lf", &g[cnt].p.x, &g[cnt].p.y);
			g[cnt].kind = POI;
			in[i].f = cnt++;
			scanf("%lf%lf", &g[cnt].p.x, &g[cnt].p.y);
			g[cnt].kind = POI;
			in[i].t = cnt++;
			in[i].kind = MOV;
		} else {
			scanf("%d%d", &in[i].obj, &in[i].v);
			in[i].kind = CHG;
		}
	}

	for(int i = 0; i < cnt; i++) {
		g[i].pre();
	}
}
void build();//建立树
int DFS1(int u, int deeps); //返回子树size
void DFS2(int u, int ances);
int build_segtree(int &k, int fr, int to);
inline void change(int u2, int v); //u a b是g中的标号
int query(int a, int b);
int root;
int t_cnt = 0; //树的节点个数
int main() {
	init();
	scan();
	build();
	DFS1(root, 0);
	DFS2(root, root);
	build_segtree(root, 0, t_cnt - 1);
	int last = 0;

	for(int i = 0; i < m; i++) {
		if(in[i].kind == CHG) {
			change(in[i].obj, in[i].v);
		} else if(in[i].kind == MOV) {
			last ^= query(g[g[in[i].f].father].tree_name, g[g[in[i].t].father].tree_name);
			printf("%d\n", last);
		}
	}

	return 0;
}
vector<int> node[N];
int v[N], size[N], deep[N], father[N]; //size 子树
int rct[N], anc[N]; //recount 新标号 线段树  anc链顶
int xdv[N];//线段树维护的v
int r_cnt = 0;
inline void addedge(int f, int t) {
	node[f].push_back(t);
}
void build() { //建立树
	g[0].tree_name = t_cnt++;
	v[0] = 0;

	for(int i = 1; i < cnt; i++) {
		if(g[i].kind == CIR || g[i].kind == POL) {
			v[t_cnt] = g[i].v;
			g[i].tree_name = t_cnt++;
		}
	}

	for(int i = 1; i < cnt; i++) {
		if(g[i].kind == CIR || g[i].kind == POL) {
			addedge(g[g[i].father].tree_name, g[i].tree_name);
			father[g[i].tree_name] = g[g[i].father].tree_name;
		}
	}
}
int DFS1(int u, int deeps) {
	size[u] = 1;
	int hson = 0, hs = 0;
	deep[u] = deeps;

	for(int i = 0, len = node[u].size(); i < len; i++) {
		int ret = DFS1(node[u][i], deeps + 1);

		if(ret > hs) {
			hson = i;
			hs = ret;
		}

		size[u] += ret;
	}

	if(hs) swap(node[u][0], node[u][hson]);

	return size[u];
}
void DFS2(int u, int ances) {
	rct[u] = r_cnt++;
	xdv[rct[u]] = v[u];
	anc[u] = ances;

	for(int i = 0, len = node[u].size(); i < len; i++) {
		if(i == 0) DFS2(node[u][i], ances);
		else DFS2(node[u][i], node[u][i]);
	}
}
int xo[N], son[N][2], st[N], en[N], mid[N];
int xds_cnt = 0;
int build_segtree(int &k, int fr, int to) { //子节点标志是left[k]==0,划分值mid[k]
	k = xds_cnt++;
	st[k] = fr;
	en[k] = to;

	if(fr == to) {
		xo[k] = xdv[fr];
	} else {
		mid[k] = (fr + to) >> 1;
		xo[k] ^= build_segtree(son[k][L], fr, mid[k]);
		xo[k] ^= build_segtree(son[k][R], mid[k] + 1, to);
	}

	return xo[k];
}
void seg_change(int k, int u, int v) { //节点u改到v
	if(st[k] == en[k]) {
		xo[k] = v;
	} else {
		int side = u <= mid[k] ? L : R;
		xo[k] ^= xo[son[k][side]];
		seg_change(son[k][side], u, v);
		xo[k] ^= xo[son[k][side]];
	}
}
int seg_query(int k, int fr, int to) {
	if(fr == st[k] && en[k] == to) {
		return xo[k];
	} else {
		if(mid[k] < fr)	return seg_query(son[k][R], fr, to);

		if(mid[k] >= to) return seg_query(son[k][L], fr, to);

		return seg_query(son[k][L], fr, mid[k])^seg_query(son[k][R], mid[k] + 1, to);
	}
}
inline void change(int u2, int v) {
	int u = g[u2].tree_name;
	seg_change(root, rct[u], v);
}
int query(int a, int b) {
	int ret = 0;
	int u = g[a].tree_name;
	int v = g[b].tree_name;

	//为了不用维护2^k级祖先，直接u,v提升到root
	while(u != root) {
		if(anc[u] == u) {
			ret ^= seg_query(root, rct[u], rct[u]);
			u = father[u];
		} else {
			ret ^= seg_query(root, rct[node[anc[u]][0]], rct[u]);
			u = anc[u];
		}
	}

	while(v != root) {
		if(anc[v] == v) {
			ret ^= seg_query(root, rct[v], rct[v]);
			v = father[v];
		} else {
			ret ^= seg_query(root, rct[node[anc[v]][0]], rct[v]);
			v = anc[v];
		}
	}

	return ret;
}
