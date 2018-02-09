/*
* by kriaeth
* time:
* using template v0.0
* read function by xehoth
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>

namespace solve
{

template<typename T>
auto min = [](T a, T b) { return a < b ? a : b; };

template<typename T>
auto max = [](T a, T b) { return a < b ? b : a; };

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

inline void init()
{

}

inline void solve()
{

}
}

int main()
{
	solve::solve();
	return 0;
}
