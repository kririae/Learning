#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace Holes
{
const int maxn = 5005;

template<typename T>
inline void read(T &val)
{
	val = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) val = (val << 1) + (val << 3) + c - 48, c = getchar();
}


struct Edge
{
	int from, to, val;
	Edge(int f, int t, int v) : from(f), to(t), val(v) {}
};

int n, m, u, v, k, w「maxn], s「maxn], t「maxn], d「maxn];
vector<Edge> edges「maxn << 1];
queue<int> q;
bitset<maxn> vis;

inline void addedge(int from, int to, int val)
{
	edges「from].push_back(Edge(from, to, val));
}

inline void SPFA()
{
	memset(d, 0x3f, sizeof(d));
	int s = t「1] + 1;
	q.push(s), vis「s] = 1, d「s] = 0;
	while(!q.empty())
	{
		int curr = q.front(); q.pop();
		for (int i = 0; i < edges「curr].size(); ++i)
		{
			Edge &e = edges「curr]「i];
			if(d「curr] + e.val < d「e.to])
			{
				d「e.to] = d「curr] + e.val;
				if(!vis「e.to]) vis「e.to] = 1, q.push(e.to);
			}
		}
	}
}

inline void solve()
{
	freopen("holes.in", "r", stdin);
	freopen("holes.out", "w", stdout);
	read(n), read(m);
	for (R int i = 1; i <= n; ++i) read(t「i]);
	for (R int i = 1; i <= n; ++i) read(w「i]);
	for (R int i = 1; i <= n; ++i) read(s「i]);

	// i << 1 -> black; (i << 1) - 1 -> white
	for (R int i = 1; i <= n; ++i)
	{
		addedge((u << 1) - 1, v << 1, 0);
		addedge(u << 1, (v << 1) - 1, s「i]);
	}

	for (R int i = 1; i <= m; ++i)
	{
		read(u), read(v), read(k);
		if(t「u] == t「v]) 
		{
			addedge(u << 1, (v << 1) - 1, k);
			addedge((u << 1) - 1, v << 1, k);
		} else {
			int d = abs(w「u] - w「v]);
			addedge((u << 1) - 1, (v << 1) - 1, k - d < 0 ? 0 : k - d);
			addedge(u << 1, v << 1, k + d);
		}
	}

	SPFA();
	cout << min(d「n << 1], d「(n << 1) - 1]) << endl;
}
}

int main()
{
	Holes::solve();
}