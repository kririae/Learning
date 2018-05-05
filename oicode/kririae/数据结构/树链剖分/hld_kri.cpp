#include <bits/stdc++.h>

using namespace std;

namespace HLD
{
const int maxn = 500005;

struct Edge
{
	int from, to;
	Edge() {}
	Edge(int f, int t) : from(f), to(t) {}
};

struct Node
{
	int l, r, son[2];
	
}
vector<Edge> edges;
vector<int> G[maxn];
int cnt;
int dep[maxn], top[maxn], son[maxn], father[maxn], size[maxn], i2d[maxn], d2i[maxn];
int pre[maxn], deal[maxn];
// i2d[i] = id to dfs_id -> dfs2
// d2i[i] = dfs_id to id
// dep[i] = deepth of a node -> dfs1
// top[i] = the top of the chain -> dfs2
// son[i] = heavyson -> dfs1
// father[i] = father -> dfs1
// size[i] = size of a Node -> dfs1
// deal
// pre

inline void addedge(int from, int to)
{
	edges.push_back(Edge(from, to));
	G[from].push_back(edges.size() - 1);
}

inline int dfs1(int k, int fa, int deep)
{
	// initalize infomation of deepth, father ans its size
	dep[k] = deep, father[k] = fa, size[k] = 1;
	int ms = -1;
	for (int i = 0; i < G[k].size(); ++i)
	{
		Edge &e = edges[G[x][i]];
		if(e.to == fa) continue;
		size[k] += dfs1(e.to, k, deep + 1);
		if(size[e.to] > ms) ms = size[e.to], son[k] = e.to; 
	}
	return size[k];
}

inline void dfs2(int k, int topf)
{
	i2d[k] = ++cnt; // current node's index in the dfs seq
	d2i[cnt] = k; 
	top[k] = topf;
	// if current Node isn't on any heavy chain
	if(!son[k]) return;
	// set its heavy son's top[i] 2 k
	dfs2(son[k], topf);
	for (int i = 0; i < G[k].size(); ++i)
	{
		Edge &e = edges[G[k][i]];
		/// if !vis
		if(e.to != son[k] && e.to != father[k])
			// build a heavy chain
			dfs2(e.to, e.to);
	}
}

inline void solve()
{

}
}

int main()
{

}