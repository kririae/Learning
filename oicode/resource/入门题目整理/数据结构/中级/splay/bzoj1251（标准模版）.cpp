#include<cstdio>
#include<iostream>
#define N 50005
#define ls a[t.son[L]]
#define rs a[t.son[R]]
using namespace std;
int n, m, cnt, root;
const int L = 0, R = 1, INF = 1000009999;
//--------------记着把maxn[0]=-inf ---
struct node { //一定要这样开空间啊，不然慢一倍啊
	int son[2], fa, turn, add, maxn, size, val;
} a[N];
inline void read(int &x)
{
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
inline void update(const int &k)
{
	if(k == 0) return;
	node& t = a[k];
	t.size = ls.size + rs.size + 1;
	t.maxn = max(max(ls.maxn, rs.maxn) + t.add, t.val);
}
inline void pushdown(const int &k)
{
	if(k == 0) return;
	node& t = a[k];
	if(t.size == 1) {
		t.add = 0;
		t.turn = 0;
		return;
	}
	if(k != 0 && t.turn == 1) {
		swap(t.son[L], t.son[R]);
		t.turn = 0;
		ls.turn ^= 1;
		rs.turn ^= 1;
	}
	if(k != 0 && t.add != 0) {
		if(t.son[L]) {
			ls.add += t.add;
			ls.maxn += t.add;
			ls.val += t.add;
		}
		if(t.son[R]) {
			rs.add += t.add;
			rs.maxn += t.add;
			rs.val += t.add;
		}
		t.add = 0;
	}
}
inline void rotate(const int &x, int &k)
{
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
inline void splay(const int &x, int &k)
{
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
inline int kth(int x) //非递归好像更快
{
	int k = root;
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
inline int get(int l, int r)
{
	l = kth(l);
	r = kth(r + 2);
	splay(l, root);
	splay(r, a[root].son[R]);
	return a[a[root].son[R]].son[L];
}
//-----------------
inline void turn_around(const int &l, const int &r)
{
	int t = get(l, r);
	a[t].turn ^= 1;
}
inline int getmax(const int &l, const int &r)
{
	int t = get(l, r);
	return a[t].maxn;
}
inline void adds(const int &l, const int &r, const int &v)
{
	node &t = a[get(l, r)];
	t.add += v;
	t.val += v;
	t.maxn += v;
}
int main()
{
	read(n);
	read(m);
	for(int i = 1; i <= n + 2; i++) {
		a[i].son[L] = i - 1;
		a[i].fa = i + 1;
		a[i].maxn = 0;
		a[i].val = 0;
		a[i].size = i;
	}
	root = n + 2;
	a[0].maxn = -INF;
	a[0].val = -INF;
	a[root].fa = 0;
	for(int i = 1, k, l, r, v; i <= m; i++) {
		read(k);
		if(k == 1) {
			read(l);
			read(r);
			read(v);
			adds(l, r, v);
		} else if(k == 2) {
			read(l);
			read(r);
			turn_around(l, r);
		} else {
			read(l);
			read(r);
			printf("%d\n", getmax(l, r));
		}
	}
	return 0;
}
