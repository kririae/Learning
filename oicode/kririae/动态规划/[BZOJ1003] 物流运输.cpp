// by kririae
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char gc()
{
	static const int LEN = 1e7;
	static char buf[LEN];
	static int s = 0, t = 0;
	s == t ? s = 0, t = fread(buf, 1, LEN, stdin) : 0;
	return s == t ? -1 : buf[s++];
}

template<class T>
inline void read(T &val)
{
	int m, c;
	for (m = 1, c = gc(); !isdigit(c); c = gc())
		m = c == '-' ? -1 : 1;
	if(c == -1) return;
	for (val = 0; isdigit(c); c = gc())
		val = (val << 3) + (val << 1) + (c - '0');
	val = m == -1 ? -val : val;
}
}

namespace BZOJ1003
{
const int maxn = 105, maxm = 20;

struct Edge
{
	int from, to, val;
	Edge() {}
	Edge(int f, int t, int v) :
	from(f), to(t), val(v) {}
};

vector<Edge> edges[maxm];

inline void addedge(int from, int to, int val)
{
	edges[from].push_back(Edge(from, to, val));
	edges[to].push_back(Edge(to, from, val));
}

int n, m, k, e, dd;
int d[maxm], f[maxn][maxn];
bitset<maxn> vis[maxm];
bitset<maxm> u;
deque<int> q;

inline bool avai(int a, int b, int c)
{
	for (int i = b; i <= c; ++i)
		if(vis[a][i]) return false;
	return true;
}

inline int SPFA(int l, int r)
{
	memset(d, 0x3f, sizeof(d)), q.clear();
	u.reset(), q.push_back(1), u[1] = 1;
	while(!q.empty())
	{
		int curr = q.front(); q.pop_front(), u[curr] = 0;
		for (int i = 0; i < edges[curr].size(); ++i)
		{
			Edge &e = edges[curr][i];
			if(avai(e.to, l, r) && d[e.from] + e.val < d[e.to])
			{
				d[e.to] = d[e.from] + e.val;
				if(!u[e.to]) u[e.to] = 1, q.push_back(e.to);
			}
		}
	}
	return d[m] == 0x3f3f3f ? 0 : d[m] * (r - l + 1);
}

inline void solve()
{
	using namespace IO;
	read(n), read(m), read(k), read(e);
	for (int i = 1; i <= e; ++i)
	{
		R int a, b, c;
		read(a), read(b), read(c);
		addedge(a, b, c);
	}
	read(dd);
	for (int i = 1; i <= dd; ++i)
	{
		R int p, a, b;
		read(p), read(a), read(b);
		for (int j = a; j <= b; ++j)
			vis[p][j] = 1;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			f[i][j] = SPFA(i, j);

	for (int k = 2; k <= n; ++k)
		for (int l = 1; (l + k - 1) <= n; ++l)
		{
			int r = l + k - 1;
			for (int p = l; p < r; ++p)
				f[l][r] = min(f[l][r], f[l][p] + k + f[p + 1][r]);
		}

	cout << f[1][n] << endl;
}
}

int main()
{
	BZOJ1003::solve();
	return 0;
}