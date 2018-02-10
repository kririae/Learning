/*
* by kriaeth
*/
/*
被lyd上的二进制思想洗脑后
有了这么一个脑洞
复杂度O(n\log{n})
基于二进制
对于每一位，从左向右扫描，如果当前位有多个相同的，递归处理。
原理应该很简单qwq
证明也不复杂
对于每一个二进制位来说，其代表的数大于低位所有的代表的数的和
利用这个性质，扫描到某一位，这一个数一定是最大的qwq
*/
#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::endl;

namespace solve
{
template<typename T>
inline T max(T a, T b) {
	return a > b ? a : b;
}

template<typename T>
inline T min(T a, T b) {
	return a < b ? a : b;
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
const int maxn = 1e6;
int n, maxx, la;
unsigned int lst[maxn];
inline void init()
{        
	read(n);
	for (register int i = 1; i <= n; ++i) {
		read(lst[i]);
		maxx = max(maxx, lst[i]);
	}
	la = floor(log(maxx) / log(2)) + 1;
}

inline void solve()
{
	vector<int> res;
	for (int i = la; i >= 0; --i) {
		unsigned int curr = (1 << la);
		queue<int> ln; int cnt = 0;
		for (register int i = 1; i <= n; ++i) {
			if(curr & lst[i]) {
				ln.push(lst[i]); ++cnt;
			}
		}
		while(cnt != 0) {
		}
	}
}
}

int main()
{
	solve::solve();
	return 0;
}
