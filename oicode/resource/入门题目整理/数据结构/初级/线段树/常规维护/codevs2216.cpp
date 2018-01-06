#include<cstdio>
#include<iostream>
#define N 1<<18
#define LL long long
using namespace std;
LL P, n, m, nn;
LL adds[N], multi[N], sum[N], size[N]; //看我如何用zkw维护一抹多变量 初始化muti=1 adds=0
inline void add_one_number(int k, int a) {
	if(k >= nn) {
		sum[k] += a, sum[k] %= P;
		return;
	}

	adds[k] += a;
	sum[k] += size[k] * a;
	sum[k] %= P;
	adds[k] %= P;
}
inline void update(int k) {
	if(k >= nn) return;

	sum[k] = sum[k << 1] + sum[(k << 1) | 1];
	sum[k] *= multi[k];
	sum[k] += adds[k] * size[k];
	sum[k] %= P;
}
inline void multi_one(int k, int a) {
	if(k >= nn) {
		sum[k] *= a, sum[k] %= P;
		return;
	}

	adds[k] *= a;
	adds[k] %= P;
	multi[k] *= a;
	multi[k] %= P;
	update(k);
}
void push_down(int k) { //貌似有些标记永久化会坑
	int u = 0;
	int f = nn;

	while(f != 1) {
		if(k & f) u = (u << 1) | 1;
		else u <<= 1;

		f >>= 1;
		multi_one(u << 1, multi[u]);
		multi_one((u << 1) | 1, multi[u]);
		add_one_number(u << 1, adds[u]);
		add_one_number((u << 1) | 1, adds[u]);
		multi[u] = 1;
		adds[u] = 0;
	}
}
void add(int l, int r, int c) {
	push_down(l + nn - 1);
	push_down(r + nn + 1);

	for(l = nn + l - 1, r = nn + r + 1; (l ^ r) != 1; l >>= 1, r >>= 1) {
		if((l & 1) == 0) add_one_number(l + 1, c);

		if((r & 1) == 1) add_one_number(r - 1, c);

		update(l);
		update(r);
	}

	update(r);

	for(; l != 0; l >>= 1) update(l);
}
void multiplicative(int l, int r, int c) {
	push_down(l + nn - 1);
	push_down(r + nn + 1);

	for(l = nn + l - 1, r = nn + r + 1; (l ^ r) != 1; l >>= 1, r >>= 1) {
		if((l & 1) == 0) multi_one(l + 1, c);

		if((r & 1) == 1) multi_one(r - 1, c);

		update(l);
		update(r);
	}

	update(r);

	for(; l != 0; l >>= 1) update(l);
}
LL getsum(int l, int r) {
	push_down(l + nn - 1);
	push_down(r + nn + 1);
	LL ansl = 0, ansr = 0;

	for(l = nn + l - 1, r = nn + r + 1; (l ^ r) != 1; l >>= 1, r >>= 1) {
		if((l & 1) == 0) ansl += sum[l + 1], ansl %= P;

		if((r & 1) == 1) ansr += sum[r - 1], ansr %= P;
	}

	return (ansl + ansr) % P;
}
int main() {
	scanf("%d%d", &n, &P);

	for(nn = 1; nn < n + 3; nn <<= 1) {}

	for(int i = nn + 1; i <= nn + n; i++) {
		scanf("%d", &sum[i]);
		size[i] = 1;
		multi[i] = 1;
		adds[i] = 0;
	}

	for(int i = nn - 1; i > 0; i--) {
		sum[i] = sum[i << 1] + sum[(i << 1) | 1];
		size[i] = size[i << 1] + size[(i << 1) | 1];
		multi[i] = 1;
		adds[i] = 0;
	}

	scanf("%d", &m);

	for(int i = 1; i <= m; i++) {
		int ins, t, g, c;
		scanf("%d", &ins);

		if(ins == 1) {
			scanf("%d%d%d", &t, &g, &c);
			multiplicative(t, g, c);
		} else if(ins == 2) {
			scanf("%d%d%d", &t, &g, &c);
			add(t, g, c);
		} else if(ins == 3) {
			scanf("%d%d", &t, &g);
			printf("%d\n", (int)getsum(t, g));
		}
	}

	return 0;
}
