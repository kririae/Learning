/*
 * by kririae
 * 20180203
 * qwq...
 * 我知道题解下面怨声一片的原因了...
 * status: WA
 */
#pragma GCC optimize(2)
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::set;
using std::vector;

namespace solve
{
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
	for (c = read(), iosig = false; !isdigit(c); c = read())
	{
		if (c == -1)
			return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c); c = read())
		x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}

constexpr int maxn = 1e5 + 5;
constexpr long long inf = (long long)~(1 << 31);

struct node
{
	int p, pp, pidx, ppidx;
	node() {}
	// node (int a, int b, int c, int d): p(a), pp(b), pidx(c), pp(d) {}
};

int n, h[maxn], as; // all step 总共可以走2^as次
long long ans = inf;
long long ansa = ans, ansb = ans;
node next[maxn];		// 表示第一个小于它的和第二个
set<pair<int, int>> st; // 表示一个数字本身，和它的索引
int a[maxn][35], b[maxn][35], f[maxn][25];

int times, ina, inb;
/*
 * 用三个数组来储存倍增数列
 * a[i][j]表示a从i开始走2^j次行驶的距离
 * b[i][j]表示b从i开始走2^j次行驶的距离
 */
auto abs = [](int a) -> int { return a < 0 ? -a : a; };
template <typename T>
inline T max(T a, T b) { return a > b ? a : b; };
template <typename T>
inline T min(T a, T b) { return a > b ? a : b; };

inline void init()
{
	read(n);
	as = log(n) / log(2) + 1;
	for (register int i = 1; i <= n; ++i)
		read(h[i]);
	// 初始化走到的位置，用一个pair储存，pair第一个是高度，第二个是数组位置
	for (int i = n; i >= 1; --i)
	{
		st.insert(pair<int, int>(h[i], i));
		auto ptr = st.find(pair<int, int>(h[i], i));
		int nextt, pre;
		int next_index, pre_index;
		nextt = pre = 0;
		next_index = pre_index = 0;
		if (ptr != st.begin())
		{
			nextt = (--ptr)->first, ++ptr, next_index = (--ptr)->second, ++ptr;
		}
		if (ptr != st.end())
		{
			pre = (++ptr)->first, --ptr, pre_index = (++ptr)->second, --ptr;
		}
		// 上面的aa nextt pre dd分别算出了该数周围四个数字的大小...但是可能有bug...一会儿再来调...
		// 分别为前一个 前两个 后一个 后二个...
		// 下一步是初始化最短的
		if (abs(h[i] - nextt) <= abs(pre - h[i]))
			next[i].p = abs(h[i] - nextt), next[i].pidx = next_index, next[i].pp = abs(pre - h[i]), next[i].ppidx = pre_index;
		else
			next[i].p = abs(pre - h[i]), next[i].pidx = pre_index, next[i].pp = abs(h[i] - nextt), next[i].ppidx = next_index;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << next[i].p << " " << next[i].pidx << next[i].pp << " " << next[i].ppidx << endl;
	}
}

inline void solve()
{
	init();
}
}

int main()
{
	solve::solve();
	return 0;
}
