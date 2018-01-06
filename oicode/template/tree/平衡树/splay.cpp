#include<cstdio>
#include<iostream>

#define N 20005
#define ls a[t.son[L]]
#define rs a[t.son[R]]
using namespace std;
const int L = 0, R = 1;

struct splay_tree {
	int cnt;

	inline int read() {
		int x = 0;
		char c = getchar();
		int f = 1;

		while (c < '0' || c > '9') {
			if (c == '-') f = -1;

			c = getchar();
		}

		while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();

		return x * f;
	}

	struct node {//一定要这样开空间啊，不然慢一倍啊
		int son[2], fa, turn, size, val;
	} a[N];

	inline void update(const int &k) {
		if (k == 0) return;

		node &t = a[k];
		t.size = ls.size + rs.size + 1;
	}

	inline void pushdown(const int &k) {
		if (k == 0) return;

		node &t = a[k];

		if (t.size == 1) {
			t.turn = 0;
			return;
		}

		if (t.turn) {
			swap(t.son[L], t.son[R]);
			t.turn = 0;
			a[t.son[L]].turn ^= 1;
			a[t.son[R]].turn ^= 1;
		}
	}

	inline void rotate(const int &x, int &k) {
		int y = a[x].fa, z = a[y].fa;
		pushdown(y);
		pushdown(x);
		int s = (a[y].son[R] == x);
		a[y].son[s] = a[x].son[s ^ 1];
		a[a[y].son[s]].fa = y;
		a[x].son[s ^ 1] = y;
		a[x].fa = a[y].fa;
		a[y].fa = x;

		if (y == k) k = x;
		else a[z].son[a[z].son[R] == y] = x;

		update(y);
	}

	inline void splay(const int &x, int &k) {
		int y, z;

		while (x != k) {
			y = a[x].fa;
			z = a[y].fa;

			if (y != k) {
				if ((a[y].son[L] == x) ^ (a[z].son[L] == y)) rotate(x, k);
				else rotate(y, k);
			}

			rotate(x, k);
		}

		update(x);
	}

	inline int kth(int k, int x) { //非递归好像更快
		//在k及其子树中找k大
		while (1) {
			pushdown(k);
			int t = a[a[k].son[L]].size + 1;

			if (t == x) return k;

			if (t < x) {
				k = a[k].son[R];
				x -= t;
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

	void build(int &k, int l, int r, int from) {
		k = ++cnt;
		a[k].fa = from;
		a[k].val = 0;
		a[k].size = r - l + 1;

		if (l == r) return;

		int mid = (l + r) >> 1;

		if (r == l + 1) build(a[k].son[R], r, r, k);
		else build(a[k].son[L], l, mid - 1, k), build(a[k].son[R], mid + 1, r, k);
	}
};

int main() {


	return 0;
}
