/*
* by kriaeth
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

const int maxn = 1005;
int primlst[50], cnt = 0;
bitset<1000> bs;
vector<int> ano[maxn]; // 储存33之后的所有数字
int f[maxn], g[maxn];
int w;
int val;
inline void init()
{
	int n;
	read(n);
	// 素数筛
	for (int i = 2; i <= n; ++i) {
		if(!bs[i]) primlst[++cnt] = i;
		for (int j = (i << 1); j <= n; j += i) bs[j] = true;
	}
	w = (1 << cnt);
}

inline void solve()
{
	for (register int qwq = 0; qwq < n; ++qwq) {
		read(val); // 读入之后，接下来构建这个数字的mask
		int mask = 0;
		// 构建mask在primlst中的映射
		for (int i = 1; i <= cnt; ++i) {
			for (; !(val % primlst[i]); val /= primlst[i])
				mask |= (1 << (i - 1));
		}
		if(val > 33) ano[val].push_back(mask);
		else for (int i = 0; i < w; ++i) 
			if(!(i & mask)) f[i | mask] = max(f[i | mask], f[i] + 1);
	}
	for (int i = 0; i <= 1000; ++i) {
		int length = ano[i].size();
		if(!length) continue;
		for (int i = 0; i < w; ++i) g[i] = f[i];
		for (int i = 0; i < w; ++i)
			for (int j = 0; j < length; ++j) {
				int val = ano[i][j];
				if(!(i & val)) g[i | val] = max(g[i | val], g[i] + 1);
			}
		memcpy(f, g, sizeof(f));
	}
	cout << f[w - 1] << endl;
}
}

int main()
{
	solve::solve();
	return 0;
}