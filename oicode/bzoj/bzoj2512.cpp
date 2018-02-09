// luogu-judger-enable-o2
#include <bits/stdc++.h>

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

const int maxn = 1e6 + 5;
int a[maxn];
int b[maxn];
int n;
long long total, ans;
template<typename T>
inline T abs(T val) { return val < 0 ? -val : val; }
inline void solve()
{
	read(n);
	for (int i = 1; i <= n; ++i) 
		read(a[i]), total += a[i];
	int aver = total / n;
	for (int i = 1; i <= n; ++i) 
		b[i] = b[i - 1] - a[i] + aver;
	std::sort(b + 1, b + n + 1);
	int mid = b[n / 2];
	for (int i = 1; i <= n; ++i) {
		ans += abs(b[i] - mid);
	}
	std::cout << ans << std::endl;
}
}

int main()
{
	solve::solve();
	return 0;
}
