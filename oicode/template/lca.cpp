#include <bits/stdc++.h>
using namespace std;
namespace lca
{
inline char read()
{
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	s == t ? t = (s = buf) +
				 fread(buf, 1, IN_LEN, stdin) : 0;
	return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
	static char c;
	static bool iosig;
	for (c = read(), iosig = false;
			!isdigit(c); c = read())
	{
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c);
			c = read())
		x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}

const int maxn = 500005;
vector<int> dfs, num;
vector<int> son[maxn];
int f[maxn][22];
int n, m, s, x, y;

inline void dfs_tree(int k)
{
	dfs.push_back(k);
	for (int i = 0; i < son[k].size(); ++i)
		dfs_tree(son[k][i]);
}

inline void init_st()
{
	for (int i = 1; i <= n; ++i) f[i][0] = dfs[i];
	int t = log(n) / log(2) + 1;
	for (int j = 1; j < t; ++j)
		for (int i = 1; i <= n - (1 << j) + 1; ++i)
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

inline int query(int l, int r)
{
	int k = log(r - l + 1) / log(2);
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

inline void init()
{
	read(n); read(m); read(s);
	for (int i = 1; i <= n; ++i)
	{
		read(x); read(y);
		son[x].push_back(y);
	}
	dfs_tree(s);
}

inline void solve()
{
	init();
	for (int i = 0; i < dfs.size(); ++i) cout << dfs[i] << " ";
// 	for (int i = 1; i <= m; ++i)
// 	{
// 		read(x); read(y);
// 		cout << query(x, y) << endl;
// 	}
}
}

int main()
{
	lca::solve();
	return 0;
}