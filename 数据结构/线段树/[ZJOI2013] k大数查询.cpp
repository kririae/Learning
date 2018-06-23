// by kririae
#define ls t[k].son[0]
#define rs t[k].son[1]
#define mid ((l + r) >> 1)
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char read()
{
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
	return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
	static char c;
	static bool iosig;
	for (c = read(), iosig = false; !isdigit(c); c = read())
	{
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c); c = read()) 
		x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}
}

namespace kth
{
const int maxn = 50005;

int n, m, tot;
int op[maxn], a[maxn], b[maxn], c[maxn];
int s[maxn], sz;

struct Node
{
	int son[2], add;
	long long sum;

	Node() {}
};

int cnt, root[maxn << 2];
Node t[maxn * 400];

inline void pushup(int k)
{
	t[k].sum = t[ls].sum + t[rs].sum;
}

inline void pushdown(int &k, int l, int r)
{
	if(!t[k].sum) return;
	if(!ls) ls = ++cnt;
	if(!rs) rs = ++cnt;
	t[ls].add += t[k].add, t[rs].add += t[k].add;
	t[ls].sum += (r - mid) * t[k].sum, t[rs].sum += (mid - l + 1) * t[k].sum;
	t[k].add = 0;
}

inline void update2(int &k, int l, int r, int a, int b)
{
	if(!k) k = ++cnt;
	pushdown(k, l, r);

	if(l == a && r == b)
	{
		t[k].sum += (r - l + 1), ++t[k].add;
		return;
	}

	if(b <= mid) update2(ls, l, mid, a, b);
	else if(a > mid) update2(rs, mid + 1, r, a, b);
	else update2(ls, l, mid, a, mid), update2(rs, mid + 1, r, mid + 1, b);
	pushup(k);
}

inline void update1(int a, int b, int c)
{
	int l = 1, r = sz, k = 1;
	while(l < r)
	{
		update2(root[k], 1, n, a, b);
		if(c <= mid) k <<= 1, r = mid;
		else k = (k << 1) | 1, l = mid + 1;
	}
	// if l == r
	update2(root[k], 1, n, a, b);
}

inline int query2(int k, int l, int r, int a, int b)
{
	if(!k) return 0;
	pushdown(k, l, r);
	if(l == a && r == b)
		return t[k].sum;
	if(b <= mid) return query2(ls, l, mid, a, b);
	else if(a > mid) return query2(rs, mid + 1, r, a, b);
	else return query2(ls, l, mid, a, mid) + query2(rs, mid + 1, r, mid + 1, b);
}

inline int query1(int a, int b, int c)
{
	int l = 1, r = sz, k = 1;
	while(l < r)
	{
		int k = query2(root[k << 1], 1, n, a, b);
		if(c <= k) k <<= 1, r = mid;
		else k = (k << 1) | 1, l = mid + 1, c -= k;
	}
	return l;
}

inline void solve()
{
	using namespace IO;
	read(n), read(m);
	for (int i = 1; i <= m; ++i)
	{
		read(op[i]), read(a[i]), read(b[i]), read(c[i]);
		if(op[i] == 1) s[++tot] = c[i];
	}

	sort(s + 1, s + 1 + tot);
	sz = unique(s + 1, s + 1 + tot) - s - 1; // 离散化所有的c

	for (int i = 1; i <= m; ++i)
	{
		if(op[i] == 1) update1(a[i], b[i], sz - (lower_bound(s + 1, s + 1 + sz, c[i]) - s) + 1);
		if(op[i] == 2) cout << s[sz - query1(a[i], b[i], lower_bound(s + 1, s + 1 + sz, c[i]) - s) + 1] << endl;
	}
}
}

int main()
{
	kth::solve();
	return 0;
}