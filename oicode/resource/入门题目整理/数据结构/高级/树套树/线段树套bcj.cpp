/*
并查集暴力维护两侧信息nmlogn
反正只要复杂度对了就是
树状数组套树状数组套bcj？
mnlog^2n
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#define N 105
using namespace std;
int n, m, cnt;
struct bcj {
	int bcj_[N * 2], size;
	void clear(int si) {
		size = si;

		for(int i = 1; i <= size; i++) {
			bcj_[i] = i;
		}
	}
	int ff(int x) {
		return bcj_[x] == x ? x : bcj_[x] = ff(bcj_[x]);
	}
	int connect(int fr, int to) {
		if(ff(fr) == ff(to)) return 0;

		if(ff(fr) < ff(to)) swap(fr, to);

		bcj_[ff(fr)] = ff(to);
		return 1;
	}
	void turnside(int s) {
		if(s == 1) {
			for(int i = 1; i <= n; i++) {
				if(ff(i) > n) {
					bcj_[ff(i)] = i;
					bcj_[i] = i;
				}
			}
		} else {
			for(int i = n + 1; i <= n + n; i++) {
				if(ff(i) <= n) {
					bcj_[ff(i)] = i;
					bcj_[i] = i;
				}
			}
		}
	}
	void prepare() {
		for(int i = 1; i <= n + n; i++) ff(i);
	}
};
//--------------------------------
int map[N][N];//1-black 0-white
const int L = 0, R = 1;
struct xds {
	bcj lr;//1-n l   n+1-n+n r
	int color[2];
	int fr, to, son[2];
} a[N * 2];
void pre(int k) {
	a[k].lr.clear(n << 1);
	a[k].lr.connect(n + 1, 1);

	for(int i = 2; i <= n; i++) {
		a[k].lr.connect(i + n, i);

		if(map[a[k].to][i] == map[a[k].to][i - 1]) {
			a[k].lr.connect(i, i - 1);
		}
	}

	a[k].color[0] = a[k].color[1] = 0;

	for(int i = 1; i <= n; i++) {
		if(a[k].lr.ff(i) == i) {
			a[k].color[map[a[k].to][i]]++;
		}
	}
}
void merge(int k) {
	a[k].color[1] = a[a[k].son[L]].color[1] + a[a[k].son[R]].color[1];
	a[k].color[0] = a[a[k].son[L]].color[0] + a[a[k].son[R]].color[0];
	bcj buf;
	buf.clear(n << 1);
	a[a[k].son[L]].lr.turnside(2);
	a[a[k].son[R]].lr.turnside(1);
	a[a[k].son[L]].lr.prepare();
	a[a[k].son[R]].lr.prepare();

	for(int i = n + 1; i <= n + n; i++) buf.bcj_[i - n] = a[a[k].son[L]].lr.bcj_[i] - n;

	for(int i = 1; i <= n; i++) buf.bcj_[i + n] = a[a[k].son[R]].lr.bcj_[i] + n;

	a[k].lr.clear(n << 1);
	a[a[k].son[L]].lr.turnside(1);
	a[a[k].son[R]].lr.turnside(2);
	a[a[k].son[L]].lr.prepare();
	a[a[k].son[R]].lr.prepare();

	for(int i = 1; i <= n; i++) a[k].lr.bcj_[i] = a[a[k].son[L]].lr.bcj_[i];

	for(int i = n + 1; i <= n + n; i++) a[k].lr.bcj_[i] = a[a[k].son[R]].lr.bcj_[i];

	for(int i = 1; i <= n; i++) {
		if(map[a[a[k].son[L]].to][i] == map[a[a[k].son[R]].fr][i]) {
			int ll = a[a[k].son[L]].lr.ff(i + n);
			int rr = a[a[k].son[R]].lr.ff(i);

			if(ll <= n && rr > n) a[k].lr.connect(rr, ll);

			a[k].color[map[a[a[k].son[L]].to][i]] -= buf.connect(i + n, i);
		}
	}
}
void build(int &k, int fr, int to) {
	k = ++cnt;
	a[k].fr = fr;
	a[k].to = to;

	if(fr == to) {
		pre(k);
	} else {
		int mid = (fr + to) >> 1;
		build(a[k].son[L], fr, mid);
		build(a[k].son[R], mid + 1, to);
		merge(k);
	}
}
void change(int k, int lie, int hang) {
	if(a[k].fr == a[k].to) {
		map[lie][hang] ^= 1;
		pre(k);
	} else {
		int mid = (a[k].fr + a[k].to) >> 1;

		if(lie <= mid) change(a[k].son[L], lie, hang);
		else change(a[k].son[R], lie, hang);

		merge(k);
	}
}
//--------------------------------
int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &map[j][i]);
		}
	}

	scanf("%d", &m);
	int root;
	build(root, 1, n);

	for(int i = 1, ha, lie; i <= m; i++) {
		scanf("%d%d", &ha, &lie);

		if(ha == -1) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					printf("%d ", map[j][i]);
				}

				puts("");
			}

			continue;
		}

		change(root, lie, ha);
		printf("%d %d\n", a[root].color[1], a[root].color[0]);
	}

	return 0;
}
