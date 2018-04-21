// by kririae
// NOIP2017 D2T3
// SegmentTree ver
// TODO~
#define ls t[k].son[0]
#define rs t[k].son[1]
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char read()
{
	static const int len = 1000000;
	static char buf[len], *s, *t;
	s == t ? t = (s = buf) + fread(buf, 1, len, stdin) : 0;
	return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
	static char c;
	static bool minus;
	for (c = read(), minus = false; !isdigit(c); c = read())
	{
		if (c == -1) return;
		c == '-' ? minus = true : 0;
	}
	for (x = 0; isdigit(c); c = read()) 
		x = (x + (x << 2) << 1) + (c ^ '0');
	minus ? x = -x : 0;
}
}

namespace Sylvia
{
const int maxn = 300005;

struct Node
{
	int l, r, son[2];
	long long sum, add;
};

vector<Node> t[maxn];
int n, m, q, x, y;
// 第0棵不存在qwq

inline long long summ(int line, int l, int r)
{
	return ((2 + (m * line) << 1 + l + r - 2) * (r - l + 1)) >> 1;
}

inline int New(int root)
{
	t[root].push_back(Node());
	return t[root].size() - 1;
}

inline void add(int root, int &k, int l, int r, int val)
{
	k = New(root);
}

inline void set(int root, int &k, int pos, int val)
{

}

inline long long query(int root, int &k, int pos)
{

}

inline void solve()
{
	using namespace IO;
	read(n); read(m); read(q);

	for (int i = 1; i <= n; ++i)
	{
		t[i].push_back
		((Node) {1, m, {0, 0}, (2 + 2 * m * i) * m / 2, 0})
	}

	for (int i = 1; i <= n; ++i)
	{
		read(x); read(y);

	}
}
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	Sylvia::solve();
	return 0;
}