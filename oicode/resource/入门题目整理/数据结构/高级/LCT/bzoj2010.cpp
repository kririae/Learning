#include<cstdio>
#include<iostream>
#define N 200005
#define ls a[t.son[L]]
#define rs a[t.son[R]]
using namespace std;
//bzoj2010  写太丑T了
inline void read(int &x) {
	x = 0;
	char c = getchar();
	int f = 1;

	while(c < '0' || c > '9') {
		if(c == '-') f = -1;

		c = getchar();
	}

	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();

	x *= f;
}
const int L = 0, R = 1;
struct splay_tree {
	int cnt;
	struct node { //一定要这样开空间啊，不然慢一倍啊
		int son[2], fa, turn, size, val;
	} a[N];
	inline void update(const int &k) {
		if(k == 0) return;

		node& t = a[k];
		t.size = ls.size + rs.size + 1;
	}
	inline void pushdown(const int &k) {
		if(k == 0) return;

		node& t = a[k];

		if(t.size == 1) {
			t.turn = 0;
			return;
		}

		if(t.turn) {
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

		if(y == k) k = x;
		else a[z].son[a[z].son[R] == y] = x;

		update(y);
	}
	inline void splay(const int &x, int k) { //没有全局root
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
	inline int kth(int k, int x) { //非递归好像更快
		//在k及其子树中找k小
		while(1) {
			pushdown(k);
			int t = a[a[k].son[L]].size + 1;

			if(t == x) return k;

			if(t < x) {
				k = a[k].son[R];
				x -= t;
				continue;
			} else {
				k = a[k].son[L];
				continue;
			}
		}
	}
	inline int get(int root, int l, int r) { //一般序列使用
		l = kth(root, l);
		r = kth(root, r + 2);
		splay(l, root);
		splay(r, a[root].son[R]);
		return a[a[root].son[R]].son[L];
	}
	inline int get_root(int k) {
		while(a[k].fa != 0) {
			k = a[k].fa;
		}

		return k;
	}
	inline int splay_root(int k) {
		int t = get_root(k);
		int t2 = kth(t, 1);
		splay(t2, t);
		return t2;
	}
	inline void cut_right(int k) {
		int t = get_root(k);
		splay(k, t);
		a[a[k].son[R]].fa = 0;
		a[k].son[R] = 0;
		update(k);
	}
	inline int insert(int k, int place, int val_) { //在k的子树中作为第place小  请确保k是root
		int last = a[k].fa;
		int end = k;

		while(1) {
			if(k == 0) {
				k = ++cnt;
				a[k].fa = last;
				a[k].val = val_;
				a[k].size = 1;
				break;
			} else {
				a[k].size++;
				int t = a[a[k].son[L]].size + 1;

				if(place <= t) {
					last = k;
					k = a[k].son[L];
					continue;
				} else {
					last = k;
					k = a[k].son[R];
					place -= t;
					continue;
				}
			}
		}

		splay(k, end);
		return k;
	}
};
struct LCT {
	splay_tree hh;
	int root, size;
	struct treenode {
		int fa, val, hson, splay; //spl所在splay中的节点编号
	} b[N];
	inline int newtree(int val_) {
		int k = ++hh.cnt;
		hh.a[k].fa = 0;
		hh.a[k].size = 1;
		hh.a[k].son[L] = 0;
		hh.a[k].son[R] = 0;
		hh.a[k].val = val_;
	}
	inline void make(int k, int fath, int value) {
		b[k].fa = fath;
		b[k].val = value;
	}
	inline void build(int root_, int size_) {
		root = root_;
		size = size_;

		for(int i = 1; i <= size; i++) { //随机切割
			b[b[i].fa].hson = i;
		}

		//以拓扑序建立
		for(int i = 1; i <= size; i++) {
			if(b[i].hson == 0) {
				b[i].splay = newtree(i);
			} else {
				b[i].splay = hh.insert(b[b[i].hson].splay, 1, i);
			}
		}
	}
	inline void access(int k) { //最著名的操作来了
		hh.cut_right(b[k].splay);
		int t = hh.a[hh.splay_root(k)].val;

		while(t != root) {
			int a1 = b[t].fa;
			hh.cut_right(b[a1].splay);
			hh.a[b[a1].splay].son[R] = b[t].splay;
			hh.a[b[t].splay].fa = b[a1].splay;
			hh.update(b[a1].splay);
			b[a1].hson = t;
			t = hh.a[hh.splay_root(k)].val;
		}
	}
	inline void cut(int k) {
		hh.cut_right(b[b[k].fa].splay);
		b[k].fa = size;
	}
	inline void link(int k, int to) {
		b[k].fa = to;
	}
	inline int getans(int k) {
		hh.splay(b[k].splay, b[root].splay);
		return hh.a[b[k].splay].size;
	}
};
int hash[N];//hash和b一一对应
int n, m;
LCT forest;
int main() {
	read(n);

	for(int i = 1; i <= n; i++) {
		read(hash[i]);
		forest.make(i, min(i + hash[i], n + 1), 1);
	}

	forest.build(n + 1, n + 1);
	read(m);

	for(int i = 1; i <= m; i++) {
		int ins;
		read(ins);

		if(ins == 1) {
			int t;
			read(t);
			t++;
			forest.access(t);
			int ans = forest.getans(t);
			printf("%d\n", ans - 1);
		} else {
			int t, v;
			read(t);
			read(v);
			t++;
			hash[t] = v;
			forest.cut(t);
			forest.link(t, min(n + 1, t + v));
		}
	}

	return 0;
}
