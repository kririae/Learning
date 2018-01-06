//好像非旋转treap是比spaly要好写一点
#include<bits/stdc++.h>
#define N 100005
#define INF 0x3f3f3f3f
using namespace std;
//--treap--
struct treap {
	int son[2], pri, val;
	int size, rv;
} a[N];
int cnt;
const int L = 0, R = 1;
void update(int k) {
	a[k].size = 1 + a[a[k].son[L]].size + a[a[k].son[R]].size;
}
void pushdown(int k) {
	if(a[k].rv == 0) return;

	a[k].rv = 0;
	swap(a[k].son[L], a[k].son[R]);
	a[a[k].son[L]].rv ^= 1;
	a[a[k].son[R]].rv ^= 1;
}
int merge(int x, int y) { //valy>valx
	if(x == 0 || y == 0) return x + y;

	pushdown(x), pushdown(y);
	int s = a[y].pri < a[x].pri ? swap(x, y), swap(a[x].son[L], y), L : R;
	a[x].son[s] = merge(a[x].son[s], y);
	return update(x), x;
}
void split(int &k, int val, int& y) {
	pushdown(k);

	if(a[k].size == val) {
		y = 0;
		return;
	}

	if(a[a[k].son[L]].size >= val) {
		split(a[k].son[L], val, y);
		swap(a[k].son[L], y);
		swap(k, y);
		update(y);
	} else {
		split(a[k].son[R], val - a[a[k].son[L]].size - 1, y);
		update(k);
	}
}
void insert(int &root, int val) {
	int t = ++cnt;
	a[t].pri = rand() * rand() % INF;
	a[t].val = val;
	a[t].size = 1;
	root = merge(root, t);
}
void getseg(int root, int l, int r, int &tl, int &tm, int &tr) {
	split(root, r, tr);
	split(root, l - 1, tm);
	tl = root;
}
int root;
int n, m;
void reverse(int l, int r) {
	int tl, tm, tr;
	getseg(root, l, r, tl, tm, tr);
	a[tm].rv ^= 1;
	root = merge(tl, tm);
	root = merge(root, tr);
}
void out(int k) {
	pushdown(k);

	if(a[k].son[L] != 0) out(a[k].son[L]);

	printf("%d ", a[k].val);

	if(a[k].son[R] != 0) out(a[k].son[R]);
}
//---------
int main() {
	srand(233333);
	a[0].pri = INF;
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++) insert(root, i);

	for(int i = 1, l, r; i <= m; i++) {
		scanf("%d%d", &l, &r);
		reverse(l, r);
	}

	out(root);
	return 0;
}
