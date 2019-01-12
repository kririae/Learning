// by kririae
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define ls t[k].son[0]
#define rs t[k].son[1]
using namespace std;

const int N = 100005;
struct Node
{
	int l, r, son[2];
	ll add, cnt[10];
} t[N << 2];
int n, q, cnt, root, a[N], tmp[10];
inline void pushup(int k)
{
	for (int i = 0; i <= 6; ++i)
		t[k].cnt[i] = t[ls].cnt[i] + t[rs].cnt[i];
}
inline void pushdown(int k)
{
	if(t[k].add == 0) return;
	t[ls].add += t[k].add, t[rs].add += t[k].add;
	for (int i = 0; i <= 6; ++i) tmp[i] = t[ls].cnt[i];
	for (int i = 0; i <= 6; ++i) t[ls].cnt[(i + t[k].add) % 7] = tmp[i];
	for (int i = 0; i <= 6; ++i) tmp[i] = t[rs].cnt[i];
	for (int i = 0; i <= 6; ++i) t[rs].cnt[(i + t[k].add) % 7] = tmp[i];
	t[k].add = 0;
}
inline void build(int &k, int l, int r) 
{
	k = ++cnt, t[k].l = l, t[k].r = r;
	if(l == r) return ++t[k].cnt[a[l] % 7], void();
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(k);
}
inline void add(int k, int l, int r, ll val)
{
	if(t[k].l == l && t[k].r == r) {
		t[k].add += val;
		for (int i = 0; i <= 6; ++i) tmp[i] = t[k].cnt[i];
		for (int i = 0; i <= 6; ++i) t[k].cnt[(i + val) % 7] = tmp[i];
		return;
	}
	pushdown(k);
	int mid = (t[k].l + t[k].r) >> 1;
	if(r <= mid) add(ls, l, r, val);
	else if(l > mid) add(rs, l, r, val);
	else add(ls, l, mid, val), add(rs, mid + 1, r, val);
	pushup(k);
}
inline int query(int k, int l, int r)
{
	if(t[k].l == l && t[k].r == r)
		return t[k].cnt[0];
	pushdown(k);
	int mid = t[k].l + t[k].r >> 1;
	if(r <= mid) return query(ls, l, r);
	else if(l > mid) return query(rs, l, r);
	else return query(ls, l, mid) + query(rs, mid + 1, r);
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build(root, 1, n); ll a, b, c; char op[10];
	cin >> q;
	while(q--) {
		cin >> op;
		switch(op[0]) {
			case 'a': cin >> a >> b >> c, add(root, a, b, c); break;
			case 'c': cin >> a >> b, printf("%d\n", query(root, a, b)); break;
		}
	}
}