/*
 * by kririae
 * 20180203
 * qwq...
 * 我知道题解下面怨声一片的原因了...
 * status: WA
 */
#pragma GCC optimize(2)
#include <bits/stdc++.h>

using std::set;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

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
	for (c = read(), iosig = false; !isdigit(c); c = read()) {
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}

constexpr int maxn = 1e5 + 5;
constexpr long long inf = (long long)~(1 << 31);

struct node {
	int p, pp, pidx, ppidx;
	node() {}
	// node (int a, int b, int c, int d): p(a), pp(b), pidx(c), pp(d) {}
};

int n, h[maxn], as; // all step 总共可以走2^as次
long long ans = inf;
long long ansa = ans, ansb = ans;
node next[maxn]; // 表示第一个小于它的和第二个
set<pair<int, int> > st; // 表示一个数字本身，和它的索引
int a[maxn][35], b[maxn][35], f[maxn][25];

int times, ina, inb;
/*
 * 用三个数组来储存倍增数列
 * a[i][j]表示a从i开始走2^j次行驶的距离
 * b[i][j]表示b从i开始走2^j次行驶的距离
 */
auto abs = [](int a) -> int { return a < 0 ? -a : a; };
template<typename T>
inline T max(T a, T b) { return a > b ? a : b; };
template<typename T>
inline T min(T a, T b) { return a > b ? a : b; };

inline void init()
{
	read(n);
	as = log(n) / log(2) + 1;
	for (register int i = 1; i <= n; ++i) 
		read(h[i]);
	// 初始化走到的位置，用一个pair储存，pair第一个是高度，第二个是数组位置
	for (int i = n; i >= 1; --i) {
		st.insert(pair<int, int>(h[i], i));
		auto ptr = st.find(pair<int, int>(h[i], i));
		// 防止RE
		// int pre = inf, nxt = inf;
		int aa, bb, cc, dd;
		int aaidx, bbidx, ccidx, ddidx;
		aa = bb = cc = dd = inf;
		aaidx = bbidx = ccidx = ddidx = inf;
		if(ptr != st.begin()) {
			bb = (--ptr) -> first, bbidx = (--ptr) -> second;
			// if((--ptr) != st.begin()) 
			// 	aa = (--(--ptr)) -> first, aaidx = (--(--ptr)) -> second;
		}
		if(ptr != st.end()) {
			cc = (++ptr) -> first, ccidx = (++ptr) -> second;
			// if((++ptr) != st.end()) 
			// 	dd = (++(++ptr)) -> first, ddidx = (++(++ptr)) -> second;
		}
		// 上面的aa bb cc dd分别算出了该数周围四个数字的大小...但是可能有bug...一会儿再来调...
		// 分别为前一个 前两个 后一个 后二个...
		// 下一步是初始化最短的
		if(abs(h[i] - bb) <= abs(cc - h[i])) 
			next[i].p = abs(h[i] - bb), next[i].pidx = bbidx, next[i].pp = abs(cc - h[i]), next[i].ppidx = ccidx;
		else next[i].p = abs(cc - h[i]), next[i].pidx = ccidx, next[i].pp = abs(h[i] - bb), next[i].ppidx = bbidx;
	} // next.first 是到下一个的距离 next.second是到下一个的数组位置
	for (int i = 1; i <= n; ++i) {
		cout << next[i].p << " " << next[i].pidx << next[i].pp << " " << next[i].ppidx << endl;
	}
	for (int i = 1; i <= n; ++i) {
		a[i][0] = next[i].pp;
		b[i][0] = next[i].p;	
		f[i][0] = next[next[i].ppidx].pidx; // TODO
	}

	// 初始化倍增 TODO
	for (int i = 1; i <= as; ++i) {
		for (int j = 1; j <= n; ++j) {
			f[j][i] = f[f[j][i - 1]][i - 1];
			a[j][i] = a[j][i - 1] + a[f[j][i - 1]][i - 1];
			b[j][i] = b[j][i - 1] + b[f[j][i - 1]][i - 1];
		}
	}
}

inline pair<long long, long long> query(int now, int x) {
	long long resa = 0, resb = 0;
	for (int i = as; ~i; --i) {
		if(f[now][i] && a[now][i] + b[now][i] <= x) {
			resa += a[now][i], resb += b[now][i];
			x -= (a[now][i] + b[now][i]); now = f[now][i]; // 跳转到该去的位置...
		}
	}
	if(!next[now].ppidx) return pair<long long, long long>(0, 0);
	int dis = abs(h[next[now].ppidx] - h[now]);
	if(x >= dis) resa += dis;
	return pair<long long, long long>(resa, resb);
}
inline void solve()
{
	init();
	pair<long long, long long> steps;
	for (int i = 0; i <= n; ++i) { // 枚举全部情况...然后solute...
		steps = query(i, n);
		if(steps.first == 0 && steps.second == 0) continue;
		if(steps.second && (!ans || ansa * steps.first > ansb * steps.second)) {
            ansa = steps.first, ansb = steps.second, ans = i;
        }
	}
	cout << ans << endl;

	read(times);
	while(times--) {
		read(ina); read(inb);
		pair<long long, long long> tpr = query(ina, inb);
		cout << tpr.first << " " << tpr.second << endl;
	}
}
}

int main()
{
	solve::solve();
	return 0;
}
