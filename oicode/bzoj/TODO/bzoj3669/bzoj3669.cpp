/*
* by kriaeth 2018/1/13
* 讲真 不看题解我还真的想不出这个...
* spfa动态加点...貌似还挺新鲜的qwq
*/

#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <vector>
#include <priority_queue>
#include <queue>
#include <bitset>

namespace solve 
{
	const int maxn = 1e5 + 5;

	struct Edge 
	{
		int from, to, a, b;

		Edge(){}

		// Edge(int t, int a, int b) 
		// {
		// 	to = t, a = a, b = b;
		// }

		Edge(int f, int t, int a, int b) 
		{
			from = f, to = t, a = a, b = b;
		}

		bool operator < (const Edge (&e)) const
		{
			return a <= e.a;
		}
	};

	int n, m;
	int xi, yi, ai, bi;
	vector<Edge> edges[maxn];
	priority_queue<Edge> tempo;
	queue<int> proc;
	int dis[maxn];
	bitset<maxn> vis;

	int res = 1e9;

	template<typename T>
	inline T min(T a, T b) 
	{
		return a < b ? a : b;
	}

	template<typename T>
	inline T max(T a, T b) 
	{
		return a > b ? a : b;
	}

	inline void read(int &val)
	{
		val = 0; char c = getchar();
		while(!isdigit(c)) c = getchar();
		while(isdigit(c)) {val = val * 10 + c - '0'; c = getchar();}
	}

	inline void addedge(int xi, int yi, int ai, int bi, bool add)
	{
		if(add)
		{
			edges[xi].push_back(Edge(xi, yi, ai, bi));
			edges[yi].push_back(Edge(yi, xi, ai, bi));
		}
		else {
			tempo.push(Edge(xi, yi, ai, bi));
		}
	}

	inline int spfa(const Edge (&e)) 
	{
		proc.push(e.from);
		proc.push(e.to);

		vis[e.from] = true;
		vis[e.to] = true;

		while(!proc.empty()) 
		{
			int curr = proc.front();
			proc.pop();
			vis[curr] = false;
			for (int i = edges[curr].size() - 1; i >= 0; --i) 
			{
				Edge tempo = edges[curr][i];
				dis[tempo.to] = min(dis[tempo.to], dis[curr] + tempo.b);

				if(!vis[tempo.to])
				{
					vis[tempo.to] = true;
					proc.push(tempo.to);
				}
			}
		}

		return dis[n];
	}
	inline void init() 
	{
		for (register int i = 0; i < maxn; ++i) dis[i] = 1e9;
		read(n); read(m);
		for (register int i = 0; i < m; ++i) 
		{
			read(xi); read(yi); read(ai); read(bi);
			addedge(xi, yi, ai, bi, false);
		}
	}

	inline void solve()
	{
		init();
		for (int i = 0; i < m; ++i)
		{
			while(!tempo.empty()) 
			{
				Edge curr = tempo.front();
				tempo.pop();

				addedge(curr.from, curr.to, curr.a, curr.b, true);
				res = min(res, spfa(curr) + curr.a);
			}
		}	
		std::cout << res << std::endl;
	}
}

int main() 
{
	solve::solve();	
}