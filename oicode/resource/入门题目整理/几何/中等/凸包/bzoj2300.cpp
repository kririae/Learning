/*
现在完全没心情写程序
貌似省选会变简单、
oh、灾难

动态凸包加点维护
选取一个点作为基准、其他的点关于他极角排序
这样可以很方便地查询
还可以完成整个凸包
同时发现、什么平衡树维护凸包都被set秒了
*/
#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
#define eps 1e-8
#define N 100005
#define db int
using namespace std;
//------------几何库--------
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
};
inline point operator -(const point &a, const point &b) {
	return (point) {
		a.x - b.x, a.y - b.y
	};
}
inline bool equ(db a, db b) {
	return fabs(a - b) < eps;
}
inline bool operator <(const point &a, const point &b) {
	if(equ(a.x, b.x)) return a.y < b.y;

	return a.x < b.x;
}
inline double getdis(const point &a, const point &b) {
	point c = a - b;
	return sqrt(c.x * c.x + c.y * c.y);
}
inline db cross(point a, point b) {
	return a.x * b.y - b.x * a.y;
}
inline bool onleft(const point &o, const point &a, const point &b) { //o->a
	return cross(a - o, b - o) > eps;
}
//---------实际上set好像更好水------------

int n, m, p;
struct city {
	point p;
	int alive;//1 2-die
} ci[N];
double ans[N * 2];
int ins[N * 2], obj[N * 2];
point base;
double ansnow;
//-----------------------------------
struct node {
	double ang;
	point p;
	inline bool operator <(const node &bb)const {
		return ang > bb.ang;
	}
};
set<node> st;
inline void insert(point p) {
	node t = (node) {
		atan2(p.y - base.y, p.x - base.x), p
	};
	set<node>::iterator l, r, rr, ll;
	r = st.lower_bound(t);
	l = r;
	l--;
	rr = r;
	rr++;

	if(onleft((*r).p, (*l).p, p)) return;

	ansnow -= getdis((*l).p, (*r).p);

	while(rr != st.end()) {
		if(onleft((*rr).p, (*r).p, p)) break;

		ansnow -= getdis((*r).p, (*rr).p);
		st.erase(r);
		r = rr;
		rr++;
	}

	ansnow += getdis(p, (*r).p);

	while(l != st.begin()) {
		ll = l;
		ll--;

		if(onleft((*l).p, (*ll).p, p)) break;

		ansnow -= getdis((*l).p, (*ll).p);
		st.erase(l);
		l = ll;
	}

	ansnow += getdis(p, (*l).p);
	st.insert(t);
}
//---------------------------------------
inline bool cmp(const city& a1, const city& b1) {
	return a1.p.x < b1.p.x;
}
void init() {
	int x, y;
	n = read();
	x = read(), y = read();
	m = read();

	for(int i = 1; i <= m; i++) {
		ci[i].p.x = read();
		ci[i].p.y = read();
	}

	ci[m + 1].p = (point) {
		x, y
	};
	ci[m + 2].p = (point) {
		n, 0
	};
	ci[m + 3].p = (point) {
		0, 0
	};
	base = (point) {
		0, 0
	};
	st.insert((node) {
		atan2(0, n), ci[m + 2].p
	});
	st.insert((node) {
		2, ci[m + 3].p
	});
	st.insert((node) {
		atan2(y, x), ci[m + 1].p
	});
	ansnow = getdis(ci[m + 1].p, base) + getdis(ci[m + 1].p, ci[m + 2].p);
	p = read();

	for(int i = 1; i <= p; i++) {
		ins[i] = read();

		if(ins[i] == 1) {
			obj[i] = read();
			ci[obj[i]].alive++;
		}
	}

	for(int i = 1; i <= m; i++) {
		if(ci[i].alive == 0) insert(ci[i].p);
	}

	for(int i = p; i; i--) {
		if(ins[i] == 1) {
			int t = obj[i];
			ci[t].alive--;

			if(ci[t].alive == 0) insert(ci[t].p);

			ans[i] = -1;
		} else if(ins[i] == 2) {
			ans[i] = ansnow;
		}
	}

	for(int i = 1; i <= p; i++) {
		if(ans[i] != -1) printf("%.2lf\n", ans[i]);
	}
}
int main() {
	init();

	return 0;
}
