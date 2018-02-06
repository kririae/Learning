#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::bitset;
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
	for (c = read(), iosig = false; !isdigit(c); c = read()) {
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}

const int maxn = 50005;
int n;

struct Edge {
	int s, t, val;
	Edge() {}
	Edge(int from, int to, int v): s(from), t(to), val(v) {}
};

vector<Edge> edges[maxn];
int ai, bi, ci;
queue<int> q;
bitset<maxn> vis;
int cnt = 0;
unsigned int disf[maxn];
unsigned int diss[maxn];
unsigned int ans = (1 << 31);

inline void addedge(int s, int t, int v) 
{
	edges[s].push_back(Edge(s, t, v));
	edges[t].push_back(Edge(t, s, v));
	++cnt;
}

inline unsigned int spfa(int s, int t) 
{
	q.push(s);
	vis[s] = true;
	disf[s] = 0;
	while(!q.empty()) 
	{
		int cur = q.front();
		q.pop();
		vis[cur] = false;
		for (int i = edges[cur].size() - 1; i >= 0; --i) 
		{
			Edge &tpr = edges[cur][i];
			int dist = disf[cur] + tpr.val;
			if(disf[tpr.t] > dist) 
			{
				disf[tpr.t] = dist;
				if(!vis[tpr.t]) q.push(tpr.t), vis[tpr.t] = true;
			}
			if(diss[tpr.t] > dist && disf[tpr.t] < dist) {
				diss[tpr.t] = dist;
				if(!vis[tpr.t]) q.push(tpr.t), vis[tpr.t] = true;
			}
			if(diss[tpr.t] > diss[cur] + tpr.val && disf[tpr.t] < diss[cur] + tpr.val) {
				diss[tpr.t] = dist;
				if(!vis[tpr.t]) q.push(tpr.t), vis[tpr.t] = true;
			}
		}
	}
	return diss[t];
}

inline void init()
{
	freopen("in.txt", "r", stdin);
    std::fill(diss, diss + maxn, (1 << 31));
    std::fill(disf, disf + maxn, (1 << 31));
    int r;
	read(n); read(r);
	for (register int i = 0; i < n; ++i)
	{
		read(ai); read(bi); read(ci);
		addedge(ai, bi, ci);
	}
	fclose(stdin);
}

inline void solve()
{
    init();
	cout << spfa(1, n) << endl;
}
}

int main()
{
	solve::solve();
	return 0;
}

