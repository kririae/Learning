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

const int inf = ~(1 << 31);
// unsigned short map[5005][5005];
int s[5005][5005];
int n, r;
int xi, yi, vi;
inline void init()
{
	read(n); read(r);
}

inline void solve()
{
    init();
	for (int i = 0; i < n; ++i) {
		read(xi); read(yi); read(vi);
		// 这里应该可以用并查集优化速度...
		// 既然不是省选而且数据小..(大了装不下)
		// 就算了吧
		s[xi + 1][yi + 1] += vi;
	}
	
	int res = 0;
	
	for (int i = 1; i <= 5001; ++i) {
		for (int j = 1; j <= 5001; ++j) {
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + s[i][j];
		}
	}

	for (int i = 0; i <= 5000 - r; ++i) {
		for (int j = 0; j <= 5000 - r; ++j) {
			// 枚举左上角的点的位置
			res = max(s[i + r][j + r] - s[i + r][j] - s[i][j + r] + s[i][j], res);
		}
	}
	cout << res << endl;
}
}

int main()
{
	solve::solve();
	return 0;
}