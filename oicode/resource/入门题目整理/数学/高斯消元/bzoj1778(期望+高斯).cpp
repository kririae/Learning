/*
-1 x2 x3 x4 .... p/q
x1 -1 x3 x4 .... 0
x1 x2 -1 x4 .... 0
x1 x2 x3 -1 .... 0

精度坑啊，只差1e-7
在精度要求较高的情况下，请使用标准高斯消元
如下是错误示范
*/
#include<cstdio>
#include<iostream>
#define eps 1e-9
#define N 305
using namespace std;
long double mfx[N][N];
long double *a[N];
int n, m;
inline long double fabs(const double &b) {
	return b < 0 ? -b : b;
}
inline int wsg(const long double &b) {
	return (int)(b > -eps) - (int)(b < eps);
}
void gauss() {
	for(int i = 1; i <= n; i++) a[i] = mfx[i];

	static int p, buf;

	for(int i = 1; i <= n; i++) {
		for(p = i, buf = i + 1; buf <= n; buf++)
			if(fabs(a[buf][i]) > fabs(a[p][i])) p = buf; //提高精度

		swap(a[p], a[i]);

		for(int j = 1; j <= n; j++) {
			if(j != i && wsg(a[j][i])) {
				long double t = -a[j][i] / a[i][i];

				for(int k = 1; k <= n + 1; k++) a[j][k] += a[i][k] * t;
			}
		}
	}
}
//--------------------------------------------------
struct edge {
	int to, next;
} e[100005];
int elen = 0;
int head[N];
int size[N];
inline void addedge(int &f, int &t) {
	e[++elen] = (edge) {
		t, head[f]
	};
	head[f] = elen;
	size[f]++;
	e[++elen] = (edge) {
		f, head[t]
	};
	head[t] = elen;
	size[t]++;
}
//--------------------------------------------------
int main() {
	int p, q;
	long double pfq;
	scanf("%d%d%d%d", &n, &m, &p, &q);

	if(p > q) p = q;

	pfq = p / (long double)q;

	for(int i = 1, f, t; i <= m; i++) scanf("%d%d", &f, &t), addedge(f, t);

	for(int i = 1; i <= n; i++) {
		long double ad = (1 - pfq) / (long double)size[i];

		for(int j = head[i]; j; j = e[j].next) mfx[e[j].to][i] += ad;
	}

	for(int i = 1; i <= n; i++) mfx[i][i] -= 1.0;

	mfx[1][n + 1] = -pfq;
	gauss();

	for(int i = 1; i <= n; i++) {
		a[i][n + 1] /= a[i][i];

		if(!wsg(a[i][n + 1])) a[i][n + 1] = 0;

		printf("%.9lf\n", (double)a[i][n + 1]);
	}

	return 0;
}
