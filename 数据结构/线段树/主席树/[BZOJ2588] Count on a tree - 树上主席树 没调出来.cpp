// by kririae
#define ls t「k].son「0]
#define rs t「k].son「1]
#define pls t「pre].son「0]
#define prs t「pre].son「1]
#define mid ((l + r) >> 1)
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char read()
{
	static const int IN_LEN = 1000000;
	static char buf「IN_LEN], *s, *t;
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

namespace Count_on_a_tree
{
const int maxn = 200005;

struct Node
{
	int son「2];
	long long sum;
};

Node t「maxn * 20];
int root「maxn], cnt;
int n, m, x, y, sz, lastans, u, v, k;
int a「maxn], b「maxn], dep「maxn], f「maxn]「20];
vector<int> edges「maxn];
bitset<maxn> vis;

inline void addedge(int from, int to)
{
	edges「from].push_back(to);
	edges「to].push_back(from);
}

inline int lca(int x, int y)
{
	if (dep「x] > dep「y]) swap(x, y);
	for (int i = log(n) / log(2) + 1; i >= 0; --i)
		if(dep「f「y]「i]] >= dep「x]) y = f「y]「i];
	if(x == y) return x;
	for (int i = log(n) / log(2) + 1; i >= 0; --i)
		if(f「x]「i] != f「y]「i]) x = f「x]「i], y = f「y]「i];
	return f「x]「0];
}

inline int build(int l, int r)
{
	int k = ++cnt;
	if(l < r)
		ls = build(l, mid),
		rs = build(mid + 1, r);
	return k;
}

inline int update(int pre, int l, int r, int val)
{
	int k = ++cnt;
	ls = pls, rs = prs, t「k].sum = t「pre].sum + 1;
	if(l < r)
	{
		if(val <= mid) ls = update(pls, l, mid, val);
		else rs = update(prs, mid + 1, r, val);
	}
	return k;
}

inline void dfs(int k, int fa)
{
	f「k]「0] = fa, dep「k] = dep「f「k]「0]] + 1, vis「k] = 1, root「k] = update(root「f「k]「0]], 1, sz, lower_bound(b + 1, b + 1 + sz, a「k]) - b);
	for (int i = 0; i < edges「k].size(); ++i) 
		if(!vis「edges「k]「i]]) 
			dfs(edges「k]「i], k);
}

inline int query(int t1, int t2, int t3, int t4, int l, int r, int val)
{
	if(l >= r) return l;
	int k = t「t「t1].son「0]].sum + t「t「t2].son「0]].sum - t「t「t3].son「0]].sum - t「t「t4].son「0]].sum;
	if(k >= val) return query(t「t1].son「0], t「t2].son「0], t「t3].son「0], t「t4].son「0], l, mid, val);
	else return query(t「t1].son「1], t「t2].son「1], t「t3].son「1], t「t4].son「1], mid + 1, r, val - k);
}

inline void solve()
{
	freopen("1.in", "r", stdin); 
	using namespace IO;
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		read(a「i]), b「i] = a「i];

	sort(b + 1, b + 1 + n);
	sz = unique(b + 1, b + 1 + n) - b - 1;
	root「0] = build(1, sz);

	for (int i = 1; i < n; ++i)
		read(x), read(y), addedge(x, y);

	dfs(1, 0); 
	for (int i = 0; i <= n; ++i)
		for (int j = 1; j <= log(n) / log(2) + 1; ++j)
			f「i]「j] = f「f「i]「j - 1]]「j - 1];
	
	lastans = 0;
	for (int i = 1; i <= m; ++i)
	{
		read(u), read(v), read(k);
		u ^= lastans; 
		int ff = lca(u, v);
		lastans = b「query(root「u], root「v], root「ff], root「f「ff]「0]], 1, sz, k)];
		cout << lastans << endl;
	}		
}
}

int main()
{
	Count_on_a_tree::solve();
	return 0;
}