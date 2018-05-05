// by kririae
// dp
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

namespace NOIP2017D1T3
{
const int maxn = 1e5 + 5;
const int maxk = 50 + 5;

struct Edge {
	int from, to, val;
	Edge() {}
	Edge(int f, int t, int v) : from(f), to(t), val(v) {}
};

int t, n, m, k, p, ai, bi, ci, flag;
int dist[maxn], f[maxn][maxk];
vector<Edge> edges[maxn], redges[maxn];
bitset<maxn> vis, r[maxk];
deque<int> q;

template<typename T>
inline void inc(T &a, T b)
{
	a = (long long)(a + b) % p;
}

inline void addedge(int from, int to, int val)
{
	edges[from].push_back(Edge(from, to, val));
	redges[to].push_back(Edge(to, from, val));
}

inline void reSPFA()
{
	q.push_back(n); dist[n] = 0; vis[n] = 1;

	while(!q.empty())
	{
		int curr = q.front(); q.pop_front(); vis[curr] = 0;

		for (int i = 0; i < redges[curr].size(); ++i)
		{
			Edge &e = redges[curr][i];
			if(dist[curr] + e.val < dist[e.to])
			{
				dist[e.to] = dist[curr] + e.val;
				if(!vis[e.to]) vis[e.to] = 1, q.push_back(e.to);
			}
		}
	}
}

inline int dp(int curr, int val)
{	
	if(r[val][curr]) return flag = 1, 0;
	if(curr == n && val == 0) return f[curr][val] = 1;
	if(f[curr][val]) return f[curr][val];
	
	r[val][curr] = 1;
	
	int sum = 0;
	for (int i = 0; i < edges[curr].size(); ++i)
	{
		Edge &e = edges[curr][i];
		int sub = val - (dist[e.to] - dist[e.from] + e.val);
		if(sub >= 0 && sub <= k)
			inc(sum, dp(e.to, sub));
	}
	
	r[val][curr] = 0;
	return f[curr][val] = sum;
}

inline void init()
{
	memset(f, 0, sizeof(f));
	for (int i = 0; i < maxn; ++i)
		edges[i].clear(), redges[i].clear();
	vis.reset();
	memset(dist, 0x3f, sizeof(dist));
	flag = 0;
	q.clear();
}

inline void solve()
{
	freopen("park.txt", "r", stdin);
	using namespace IO;
	read(t);
	while(t--)
	{
		init();
		read(n), read(m), read(k), read(p);
		for (int i = 1; i <= m; ++i)
			read(ai), read(bi), read(ci), addedge(ai, bi, ci);
		
		reSPFA();
		
		int ans = 0;
		for (int i = 0; i <= k; ++i)
		{
			for (int j = 0; j <= k; ++j)
			    r[j].reset();
			inc(ans, dp(1, i));
		}
				
		cout << (flag ? -1 : ans) << endl;
	}
}
}

int main()
{
	NOIP2017D1T3::solve();
	return 0;
}