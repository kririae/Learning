/*
* by kriaeth
* 2018/1/13
* spfa
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>

namespace solve
{
const int maxn = 1e5 + 5;
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

inline void read(int &val)
{
	val = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) {
		val = val * 10 + c - '0';
		c = getchar();
	}
}

struct Edge {
	int to, int val;

	Edge() {}

	Edge(int t, int v)
	{
		to = t, val = v;
	}
};

int t;
int n, m, k, p;
int ai, bi, ci;
vector<Edge> edges[maxn];

inline void addedge(int ai, int bi, int ci)
{

}

inline void init()
{
	read(t);
	read(n);
	read(m);
	read(k);
	read(p);
	for (int rp = 0; rp < t; ++rp) {
		read(ai);
		read(bi);
		read(ci);
		addedge(ai, bi, ci);
	}
}
}