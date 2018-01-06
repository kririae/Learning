/*
又是数据结构优化暴力
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#define LL long long
#define N 200005
using namespace std;
LL n, m;
LL a[N];
int root[N];
//------------------tree-----------------
const int L = 0, R = 1;
struct node {
	int son[2], size;
} x[N * 20];
int xdscnt;
void build(int &k, int fr, int to, int val) {
	int t = ++xdscnt;
	x[t].size = x[k].size + 1;
	x[t].son[L] = x[k].son[L];
	x[t].son[R] = x[k].son[R];
	k = t;

	if(fr == to) return;

	int mid = (fr + to) >> 1;

	if(mid < val) build(x[t].son[R], mid + 1, to, val);
	else build(x[t].son[L], fr, mid, val);
}
int rank(int k, int fr, int to, int val) {
	if(fr == to) return x[k].size;

	int mid = (fr + to) >> 1;

	if(mid < val) return rank(x[k].son[R], mid + 1, to, val) + x[x[k].son[L]].size;
	else return rank(x[k].son[L], fr, mid, val);
}
int kth(int k, int fr, int to, int val) {
	if(fr == to) return fr;

	int t = x[x[k].son[L]].size;
	int mid = (fr + to) >> 1;

	if(t < val) return kth(x[k].son[R], mid + 1, to, val - t);
	else return kth(x[k].son[L], fr, mid, val);
}
//----lsh----------------------------------
struct lshgxy {
	int name;
	LL *a;
	bool operator < (const lshgxy& b)const {
		return (*a) < *(b.a);
	}
} lsh[N];
LL name2val[N];
//---------
int main() {
	scanf("%lld%lld", &n, &m);

	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);

		while(a[i] < 0) {
			a[i] %= m;
			a[i] += m;
		}

		a[i] %= m;
	}

	for(int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
		a[i] %= m;
	}

	//---离散化---
	for(int i = 1; i <= n; i++) {
		lsh[i].a = &a[i];
	}

	sort(lsh + 1, lsh + n + 1);
	int lscnt = 1;
	lsh[1].name = 1;

	for(int i = 2; i <= n; i++) {
		if(*(lsh[i].a) == *(lsh[i - 1].a)) lsh[i].name = lsh[i - 1].name;
		else lsh[i].name = ++lscnt;
	}

	for(int i = 1; i <= n; i++) {
		name2val[lsh[i].name] = *lsh[i].a;
		*lsh[i].a = lsh[i].name;
	}

	//------------
	LL ans = 0;

	for(int i = 1; i <= n; i++) {
		root[i] = root[i - 1];
		build(root[i], 1, n, a[i]);
	}

	for(int i = 1; i <= n; i++) {
		int t = rank(root[i], 1, n, a[i]); //获得比a[i]大一点的

		if(t != i) {
			t = kth(root[i], 1, n, t + 1);
			ans = max(ans, (name2val[a[i]] - name2val[t] + m) % m);
		}

		ans = max(ans, name2val[a[i]]);
	}

	printf("%lld\n", ans);
	return 0;
}
//其实好像插叙kth可以不用主席树、set水、还不用离散化
