#include<cstdio>
#include<iostream>
#define N 200005
using namespace std;
const int L = 0, R = 1;
int cnt;
struct node { //一定要这样开空间啊，不然慢一倍啊
	int son[2], fa, size, val, height; //val---(val+height-1)
} a[N];
inline void update(const int &k) {
	if(k == 0) return;

	node& t = a[k];
	a[k].size = a[a[k].son[L]].size + a[a[k].son[R]].size + t.height;
}
inline void rotate(const int &x, int &k) {
	int y = a[x].fa, z = a[y].fa;
	int s = (a[y].son[R] == x);
	a[y].son[s] = a[x].son[s ^ 1];
	a[a[y].son[s]].fa = y;
	a[x].son[s ^ 1] = y;
	a[x].fa = a[y].fa;
	a[y].fa = x;

	if(y == k) k = x;
	else a[z].son[a[z].son[R] == y] = x;

	update(y);
}
inline void splay(const int &x, int &k) {
	int y, z;

	while(x != k) {
		y = a[x].fa;
		z = a[y].fa;

		if(y != k) {
			if((a[y].son[L] == x) ^ (a[z].son[L] == y)) rotate(x, k);
			else rotate(y, k);
		}

		rotate(x, k);
	}

	update(x);
}
int make(int k, int x) { //分裂
	if(a[k].height == 1) return k;

	if(x == 1) {
		int t = ++cnt;
		a[t].fa = k;
		a[t].height = a[k].height - 1;
		a[t].son[R] = a[k].son[R];
		a[t].val = a[k].val + 1;
		a[a[k].son[R]].fa = t;
		update(t);
		a[k].height = 1;
		a[k].son[R] = t;
		return k;
	}

	int t = ++cnt;
	a[t].fa = k;
	a[t].height = a[k].height - x + 1;
	a[t].size = a[t].height;
	a[t].son[R] = a[k].son[R];
	a[t].val = a[k].val + x - 1;
	a[a[k].son[R]].fa = t;
	a[k].height = x - 1;
	a[k].son[R] = t;
	update(t);
	make(t, 1);
}
inline int kth(int k, int x) { //非递归好像更快
	//在k及其子树中找k大
	while(1) {
		int t1 = a[a[k].son[L]].size + a[k].height;
		int t2 = a[a[k].son[L]].size;

		if(t2 < x && x <= t1) return make(k, x - t2);

		if(t1 < x) {
			k = a[k].son[R];
			x -= t1;
			continue;
		} else {
			k = a[k].son[L];
			continue;
		}
	}
}
inline int get(int &root, int l, int r) { //一般序列使用
	l = kth(root, l);
	r = kth(root, r + 2);
	splay(l, root);
	splay(r, a[root].son[R]);
	return a[a[root].son[R]].son[L];
}
int hard[N];
void build(int &k, int l, int r, int from) {
	k = ++cnt;
	a[k].fa = from;
	a[k].size = r - l + 1;
	a[k].son[L] = 0;
	a[k].son[R] = 0;
	a[k].height = 1;
	int mid = (l + r) >> 1;
	a[k].val = hard[mid];

	if(l == r) return;

	if(r == l + 1) build(a[k].son[R], mid + 1, r, k);
	else build(a[k].son[L], l, mid - 1, k), build(a[k].son[R], mid + 1, r, k);
}
int n, m, root;
int main() {
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &hard[i]);
	}

	build(root, 0, n + 1, 0);

	for(int i = 1; i <= m; i++) {
		int ins, p, a2, b;
		scanf("%d", &ins);

		if(ins == 0) {
			scanf("%d%d%d", &p, &a2, &b);
			int root2 = ++cnt;
			a[root2].height = b - a2 + 1;
			a[root2].size = b - a2 + 1;
			a[root2].val = a2;
			get(root, p + 1, p);
			a[a[root].son[R]].son[L] = root2;
			a[root2].fa = a[root].son[R];
			update(a[root].son[R]);
			update(root);
		} else if(ins == 1) {
			scanf("%d%d", &a2, &b);
			int t = get(root, a2, b);
			a[t].fa = 0;
			a[a[root].son[R]].son[L] = 0;
			update(a[root].son[R]);
			update(root);
		} else {
			scanf("%d", &a2);
			int t = kth(root, a2 + 1);
			printf("%d\n", a[t].val);
		}
	}

	return 0;
}
