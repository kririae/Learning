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

namespace Count_on_a_tree
{
const int maxn = 100005;

struct Node
{
	int son[2];
	long long sum;
};

Node t[maxn * 20];
int root, cnt;
int n, m, x, y, lastans, a[maxn], dep[maxn], father[maxn];
vector<int> edges[maxn];

inline void addedge(int from, int to)
{
	edges[from].push_back(to);
}

inline void dfs(int k, int fa)
{

}

inline void solve()
{
	using namespace IO;
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		read(a[i]);

	for (int i = 1; i < n; ++i)
		read(x), read(y), addedge(x, y), father[y] = x;


	for (int i = 1; i <= m; ++i)
	{

	}
}
}