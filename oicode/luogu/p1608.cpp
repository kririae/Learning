/*
* by kriaeth
* status: AC
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using std::pair;
using std::cout;
using std::endl;
namespace solve
{
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
	for (c = read(), iosig = false; !isdigit(c); c = read()) 
	{
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}

struct Edge
{
	int from, to, val;

	Edge(){}
	Edge(int f, int t, int v): from(f), to(t), val(v){}
};

const int maxn = 2005;
int n, e, i, j, c;
std::vector<Edge> edges[maxn];
unsigned long long dis[maxn];
int cnt[maxn];
std::queue<int> proc;
std::bitset<maxn> vis;

inline void add_edge(int from, int to, int val)
{
	edges[from].push_back(Edge(from, to, val));
}

inline pair<int, int> spfa(int s, int t)
{
	vis[s] = true;
	dis[s] = 0;
	proc.push(s);
	cnt[s] = 1;
	while(!proc.empty())
	{
		int curr = proc.front();
		proc.pop();
		vis[curr] = false;
		for (int i = edges[curr].size() - 1; i >= 0; --i)
		{
			Edge tempo = edges[curr][i];
			if(dis[tempo.from] + tempo.val <= dis[tempo.to])
			{
				if(dis[tempo.from] + tempo.val == dis[tempo.to]) {
					cnt[tempo.to] += cnt[tempo.from];
					// cnt[tempo.to] += 1;
				}
				else {
					cnt[tempo.to] = cnt[tempo.from];
				}
				dis[tempo.to] = dis[tempo.from] + tempo.val;
				if(!vis[tempo.to] && cnt[tempo.to])
				{
					vis[tempo.to] = true;
					proc.push(tempo.to);
				}
			}
		}
	}
	static pair<int, int> a(dis[t], cnt[t]);
	return a;
}

inline void init()
{
	read(n); read(e);
	for (int qwq = 0; qwq < e; ++qwq)
	{
		read(i); read(j); read(c);
		add_edge(i, j, c);
	}
	for (int i = 0; i < maxn; ++i) dis[i] = 1e18;
}

inline void solve() 
{
	init();
	pair<int, int> ret = spfa(1, n);
	cout << ret.first << " " << ret.second + 1 << endl;
}
}

int main()
{
	solve::solve();
	return 0;
}