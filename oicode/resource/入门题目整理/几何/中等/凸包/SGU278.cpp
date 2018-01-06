/*
其实式子推出来就简单了
求一下对偶 发现可以用半平面配凸包
so easy,还可以支持动态哦
（带删点的动态凸包，强制在线的话就分块搞，n^1.5logn,也许换一下块的大小可以更优）
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 75050
#define db long double
#define eps 1e-8
using namespace std;
//------------------------
struct point {
	db x, y;
};
inline int sg(db a) {
	if(a < eps && a > -eps) return 0;

	return a > 0 ? 1 : -1;
}
inline db cross(point a, point b) {
	return a.x * b.y - a.y * b.x;
}
inline point operator -(point &a, point &b) {
	return (point) {
		a.x - b.x, a.y - b.y
	};
}
inline point operator +(point &a, point &b) {
	return (point) {
		a.x + b.x, a.y + b.y
	};
}
inline int onside(point &o, point &a, point &b) {
	return sg(cross(a - o, b - o));
}
//------------------------
/*只有四分之一个半平面*/
struct line {
	db k, b;
	int name;
};
inline bool operator <(const line &a, const line &b) {
	if(sg(a.k - b.k))return a.k < b.k;

	return a.b > b.b;
}
inline point get_inter(const line &a, const line &b) {
	return (point) {
		(b.b - a.b) / (a.k - b.k), a.k*(b.b - a.b) / (a.k - b.k) + a.b
	};
}
inline int onside(const line &a, point b) {
	return sg(b.y - (a.k * b.x + a.b));
}
line bpmin[N], bpmout[N];
int szin, szout;
void bpm() {
	sort(bpmin + 1, bpmin + szin + 1);
	int szcnt = 0;
	bpmin[0].k = 105;

	for(int i = 1; i <= szin; i++) {
		if(sg(bpmin[i].k - bpmin[i - 1].k)) bpmin[++szcnt] = bpmin[i]; //去重
	}

	for(int i = 1; i <= szcnt; i++) {
		while(szout >= 2 && onside(bpmin[i], get_inter(bpmout[szout], bpmout[szout - 1])) <= 0) szout--;

		bpmout[++szout] = bpmin[i];
	}
}
//------------------------
int bufa[N], bufb[N], bufc[N];
int n, A, B;
int main() {
	scanf("%d%d%d", &n, &A, &B);

	for(int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		if(a == 0 && b == 0 && c == 0) {
			i--, n--;
			continue;
		}

		if(b != 0) {
			bpmin[i].k = -a / (db)b;
			bpmin[i].b = c / (db)b;
		} else {
			bpmin[i].k = -1e13;
			bpmin[i].b = c * 1e13 / (db)a;
		}

		bpmin[i].name = i;
		bufa[i] = a;
		bufb[i] = b;
		bufc[i] = c;
	}

	szin = n;
	bpm();
	db ans = 1e9;

	if(szout == 1) {
		int v = bpmout[1].name;
		ans = min(A / (db)bufa[v], B / (db)bufb[v]) * bufc[v];
	} else {
		for(int i = 2; i <= szout; i++) {
			point p = get_inter(bpmout[i - 1], bpmout[i]);
			ans = min(ans, A * p.x + B * p.y);
		}
	}

	printf("%.6lf\n", (double)ans);
	return 0;
}
