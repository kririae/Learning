#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;
namespace solve
{

template<typename T>
inline T min(T a, T b) {
	return a < b ? a : b;
}

template<typename T>
inline T max(T a, T b) {
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
int size = 0;
struct Matrix {
	int edges[205][205];
	Matrix() {}
	Matrix operator * (const Matrix &a) const 
	{
		Matrix ret;
		std::memset(ret.edges, 127 / 3, sizeof(ret.edges));
		for (register int k = 1; k <= size; ++k) 
		for (register int i = 1; i <= size; ++i) 
		for (register int j = 1; j <= size; ++j) 
		ret.edges[i][j] = min(this->edges[i][k] + a.edges[k][j], ret.edges[i][j]);
		return ret;
	}
} res, dis;
int n, t, s, e;
int length, l1, l2;
int cret[1005];

inline void pow(int val) 
{
	while(val)
	{
		if(val & 1) {
			res = dis * res;
		}
		dis = dis * dis;
		val >>= 1;
	}
}

inline void init()
{
	read(n); read(t); read(s); read(e);
	std::memset(res.edges, 127 / 3, sizeof(res.edges));
	std::memset(dis.edges, 127 / 3, sizeof(dis.edges));
	std::memset(cret, 0, sizeof(cret));
	for (register int i = 0; i < t; ++i)
	{
		read(length); read(l1); read(l2);
		if(cret[l1] == 0) cret[l1] = ++size; // 简单离散化...
		if(cret[l2] == 0) cret[l2] = ++size;
		dis.edges[cret[l1]][cret[l2]] = length;
		dis.edges[cret[l2]][cret[l1]] = length;
	}
}

inline void solve()
{
	init();
	for (int i = 1; i <= size; ++i) {
	    res.edges[i][i] = 0;
	}
	pow(n);
	std::cout << res.edges[cret[s]][cret[e]] << std::endl;
}
}

int main()
{
	solve::solve();
	return 0;
}