#include<cstdio>
#include<iostream>
#define N 100005
using namespace std;
int n, m, cnt, root;
const int L = 0, R = 1;
//--------------------
int son[N][2], fa[N], tag[N], meg[N], size[N];
inline void pushdown(int &k)
{
	if(k == 0 || tag[k] == 0) return;
	swap(son[k][L], son[k][R]);
	tag[son[k][L]] ^= 1;
	tag[son[k][R]] ^= 1;
	tag[k] = 0;
}
inline void update(int &k)
{
	if(k == 0) return;
	size[k] = size[son[k][L]] + size[son[k][R]] + 1;
}
inline void rotate(int x, int &k)
{
	int y = fa[x], z = fa[y];
	int s = son[y][L] == x ? L : R;
	int s2 = son[z][L] == y ? L : R;
	son[y][s] = son[x][s ^ 1];
	fa[son[x][s ^ 1]] = y;
	son[x][s ^ 1] = y;
	fa[x] = fa[y];
	fa[y] = x;
	if(y == k) k = x;
	else {
		son[z][s2] = x;
	}
	update(y);
	update(x);
}
void splay(int x, int &k)
{
	int y, z;
	while(x != k) {
		y = fa[x];
		z = fa[y];
		pushdown(fa[z]);
		pushdown(z);
		pushdown(y);
		pushdown(x);//注意pushdown fa[z]因为是双旋
		if(y != k) {
			if((son[z][L] == y) ^ (son[y][L] == x)) { //zig
				rotate(x, k);
			} else { //zag
				rotate(y, k);
			}
		}
		rotate(x, k);
	}
}
int kth(int k, int x)
{
	pushdown(k);//pay attention
	int t = size[son[k][L]];
	if(x == t + 1) return k;
	if(x > t + 1) return kth(son[k][R], x - t - 1);
	if(x < t + 1) return kth(son[k][L], x);
}
void turn(int l, int r)
{
	l = kth(root, l);
	r = kth(root, r + 2);
	splay(l, root);
	splay(r, son[root][R]);
	tag[son[son[root][R]][L]] ^= 1;
}
//--------------------
void print(int k)
{
	if(k == 0) return;
	pushdown(k);
	print(son[k][L]);
	if(meg[k] != 0 && meg[k] != n + 1) printf("%d ", meg[k]);
	print(son[k][R]);
}
int a[N];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n + 2; i++) {
		meg[i] = i - 1;
		fa[i] = i + 1;
		son[i][L] = i - 1;
		son[i][R] = 0;
		size[i] = i;
	}
	fa[n + 2] = 0;
	root = n + 2;
	for(int i = 1, l, r; i <= m; i++) {
		scanf("%d%d", &l, &r);
		turn(l, r);
	}
	print(root);
	return 0;
}
