/*
 *  @author kriaeth
 *  :time 2018/1/20
 *  dp + spfa
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>

namespace solve
{
	constexpr int maxn = 1e5 + 5;

	template<typename T>
	inline T min(T a, T b)
	{
		return a < b ? a : b;
	}

	template<typename T>
	inline T max(T a, T b)
	{
		return a < b ? b : a;
	}

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
		for (c = read(), iosig = false; !isdigit(c); c = read()) {
			if (c == -1) return;
			c == '-' ? iosig = true : 0;
		}
		for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
		iosig ? x = -x : 0;
	}

	struct Edge
	{
		int to, val;

		Edge(){}

		Edge(int a, int b)
		{
			to = a, val = b;
		}
	};

	// define
	int t, n, m, k, p;
	int ai, bi, ci;
	int d;
	vector<Edge> edges[maxn];
	bitset<maxn> vis;
	long long dis[maxn];
	queue<int> proc;
	int f[maxn][55];

	inline void f_spfa(int s, int t)
	{
		vis[s] = true;
		dis[s] = 0;

		proc.push(s);

		while(!proc.empty())
		{
			int curr = proc.front();
			proc.pop();
			vis[curr] = false;

			for (int i = edges[curr].size(); i >= 0; --i)
			{
				Edge &tempo = edges[curr][i];

				if(dis[tempo.to] > dis[curr] + tempo.val)
				{
					dis[tempo.to] = dis[curr] + tempo.val;

					if(!vis[tempo.to])
					{
						vis[tempo.to] = true;
						proc.push(tempo.to);
					}
				}
			}
		}

		d = dis[t] + k;
	}

	inline void
	inline void addedge(int a, int b, int c)
	{
		edges[a].push_back(Edge(b, c));
	}

	inline void init()
	{
		read(t);

		for (int rp = 0; rp < t; ++rp)
		{
			for (int i = 0; i < maxn; ++i)
			{
				edges[i].clear();
				dis[i] = maxn;
			}
			vis.clear();

			read(n); read(m); read(k); read(p);

			for (int i = 0; i < m; ++i)
			{
				read(ai); read(bi); read(ci);
				addedge(ai, bi, ci);
			}
		}

		f_spfa(1, n);


	}

	inline void solve()
	{
		// freopen("park.in", "r", stdin);
		// freopen("park.out", "w", stdout);
		init();


	}
}

int main()
{
	solve::solve();
	return 0;
}