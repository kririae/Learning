#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define LL long long
#define db int
#define eps 1e-8
#define N 605
#define M 4005
using namespace std;
inline int read() {
	char c = getchar();
	int ret = 0;

	while(c < '0' || c > '9') c = getchar();

	while(c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();

	return ret;
}
struct point {
	db x, y;
};
struct seg {
	point a, b;
	int d[2];
};
inline point operator -(const point &a, const point &b) {
	return (point) {
		a.x - b.x, a.y - b.y
	};
}
inline db getdis(point &a, point &b) {
	point c = a - b;
	return sqrt(c.x * c.x + c.y * c.y);
}
inline bool equ(const point &a, const point &b) {
	return (a.x == b.x) && (a.y == b.y);
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
//inline bool onright(const point &o,const point &a,const point &b){
//	return cross(a-o,b-o)<-eps;
//}
///////////////////////////////////////////库
int n, m;
point arm[N];
seg b[M];

//-------------------图论模型---------------
struct p2 {
	point a;
	int from;
	int name;
};
struct edge {
	int from, to;
	point v;
};
vector<edge> e;
int e_len;
int vis[4 * M];
vector<int> node[M];
inline void addedge(int from, int to, point f, point t) {
	e.push_back((edge) {
		from, to, t - f
	});
	node[from].push_back(e_len++);
	e.push_back((edge) {
		to, from, f - t
	});
	node[from].push_back(e_len++);
}
//------------------------------------------
p2 p[2 * M]; //端点
bool cmp1(const p2 &a, const p2 &b) {
	if(a.a.y != b.a.y) return a.a.y > b.a.y;

	return a.a.x < b.a.x;
}
int p_cnt;
point top[M];
void buildmap() {
	for(int i = 0; i < m; i++) {
		p[(i << 1)].a = b[i].a;
		p[(i << 1) ^ 1].a = b[i].b;
		p[(i << 1)].from = (i << 1);
		p[(i << 1) ^ 1].from = (i << 1) ^ 1;
	}

	p_cnt = 1;
	sort(p, p + 2 * m, cmp1);

	for(int i = 1; i < 2 * m; i++) {
		if(!equ(p[i].a, p[i - 1].a)) {
			p[i].name = cnt;
		} else {
			p[i].name = p[i - 1].name;
		}
	}

	for(int i = 0; i < 2 * m; i++) {
		b[p[i].from >> 1].d[p[i].from & 1] = p[i].name;
	}

	p_cnt = 0;
	top[p_cnt++] = p[0].a;

	for(int i = 1; i < 2 * m; i++) {
		if(!equ(p[i].a, p[i - 1].a)) {
			top[p_cnt++] = p[i].a;
		}
	}

	for(int i = 0; i < m; i++) {
		addedge(b[i].d[0], b[i].d[1], b[i].a, b[i].b);
	}
}//几何转图论
//----------外侧边界------------top[]各点坐标 p_cnt点的总数 e边 node[]图论点
inline bool onright(const point vfrom, const point &v1, const point &v2) { //以v1为基准，以vfrom为0度
	if(cross(vfrom, v1)*cross(vfrom, v2) < -eps) {
		if(cross(vfrom, v1) < -eps) {
			return false;
		}

		return true;
	} else {
		if(cross(v1, v2) < -eps) {
			return true;
		}

		return false;
	}
}
int pvis[2 * M];
void tb(int u, point &fr) {
	if(pvis[u] == 1) return;

	int right = 0;
	pvis[u] = 1;

	for(int i = 1; i < node[u].size(); i++) {
		if(vis[node[u][i]] == 1) continue;

		if(onright(top[u] - fr, e[node[u][right]].v, e[node[u][i]].v)) {
			right = i;
		}
	}

	vis[node[u][right]] = 1;
	tb(e[node[u][right]].to, top[u]);
}
//------------------划分区域---------------------------------------
/*
先留坑
*/
int main() {
	n = read();
	m = read();

	for(int i = 0; i < n; i++) {
		arm[i].x = read();
		arm[i].y = read();
	}

	for(int i = 0; i < m; i++) {
		b[i].a.x = read();
		b[i].a.y = read();
		b[i].b.x = read();
		b[i].b.y = read();
	}

	buildmap();
	point pstart = (point) {
		-100000, top[0].y
	};
	tb(0, pstart);

	for(int i = 1; i <= n; i++) {

	}

	return 0;
}
