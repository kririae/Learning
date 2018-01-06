/*
竟然找到的hht出题的出处
*/
#include<cstdio>
#define N 500005
using namespace std;
struct edge {
	int to, next;
	double p;
};
edge e[2 * N];
int elen = 0;
int head[N];
void addedge(int f, int t, double p) {
	e[++elen] = (edge) {
		t, head[f], p
	};
	head[f] = elen;
	e[++elen] = (edge) {
		f, head[t], p
	};
	head[t] = elen;
}
inline double fabs(double k) {
	return k < 0 ? -k : k;
}
//---------------------------------------
int n, pi[N];
double f[N];
void DFS1(int u, int fr) { //考虑子树的贡献
	for(int i = head[u]; i; i = e[i].next) {
		if(e[i].to != fr) DFS1(e[i].to, u);
	}

	for(int i = head[u]; i; i = e[i].next) {
		if(e[i].to != fr) f[u] *= 1 - (e[i].p * (1 - f[e[i].to]));
	}
}
void DFS2(int u, int fr) { //考虑父亲对儿子的贡献
	for(int i = head[u]; i; i = e[i].next) {
		if(e[i].to != fr && fabs(f[e[i].to]) > 1e-8) f[e[i].to] *= 1 - (1 - (f[u] / (1 - e[i].p * (1 - f[e[i].to])))) * e[i].p;
	}

	for(int i = head[u]; i; i = e[i].next) {
		if(e[i].to != fr) DFS2(e[i].to, u);
	}
}

void init() {
	scanf("%d", &n);

	for(int i = 1; i < n; i++) {
		static int a, b, p;
		scanf("%d%d%d", &a, &b, &p);
		double p2 = p;
		addedge(a, b, p / 100.0);
	}

	for(int i = 1; i <= n; i++) {
		static int p;
		scanf("%d", &p);
		f[i] = 1 - p / 100.0;
	}
}
int main() {
	init();
	DFS1(1, 0);
	DFS2(1, 0);
	double ans = 0;

	for(int i = 1; i <= n; i++) ans += 1 - f[i];

	printf("%.6lf", ans);
	return 0;
}
