// by kririae
#define ls t[k].son[0]
#define rs t[k].son[1]
#define pls t[pre].son[0]
#define prs t[pre].son[1]
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

namespace PT
{
const int maxn = 200005;

struct Node
{
	int son[2];
	long long sum;
};

Node t[maxn * 20];
int root[maxn], cnt;
int n, m, l, r, k, a[maxn], b[maxn];

inline int build(int l, int r)
{
	int k = ++cnt;
	int mid = (l + r) >> 1;
	if(l < r)
		ls = build(l, mid),
		rs = build(mid + 1, r);
	return k;
}

inline int update(int pre, int l, int r, int val)
{
	// pre 左边的树 val 更新val位置（val+1，即val重新出现一次
	int k = ++cnt;
	ls = pls, rs = prs, t[k].sum = t[pre].sum + 1;
	// 复制原来节点的所有信息，并且更新新节点的信息。
	int mid = (l + r) >> 1;
	if(l < r)
	{
		if(val <= mid) ls = update(pls, l, mid, val);
		else rs = update(prs, mid + 1, r, val);
	}
	return k;
}

inline int query(int u, int v, int l, int r, int val)
{
	// u表示在第一棵树里的位置，v表示在第二棵树里的位置
	if(l >= r) return l;
	int k = t[t[v].son[0]].sum - t[t[u].son[0]].sum;
	// 区间[u, v]之间大于l小于r的个数
	int mid = (l + r) >> 1;
	if(k >= val) return query(t[u].son[0], t[v].son[0], l, mid, val);
	else return query(t[u].son[1], t[v].son[1], mid + 1, r, val - k);
}

inline void solve()
{
	using namespace IO;
	read(n), read(m); 
	
	for (int i = 1; i <= n; ++i)
		read(a[i]), b[i] = a[i];

	sort(b + 1, b + 1 + n);
	int sz = unique(b + 1, b + 1 + n) - b - 1;
	root[0] = build(1, sz);

	for (int i = 1; i <= n; ++i)
		root[i] = update(root[i - 1], 1, sz, lower_bound(b + 1, b + 1 + sz, a[i]) - b);

	while(m--)
	{
		read(l), read(r), read(k);
		cout << b[query(root[l - 1], root[r], 1, sz, k)] << endl;
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	PT::solve();
	return 0;
}