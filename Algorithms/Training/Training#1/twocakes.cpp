// by kririae
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char gc()
{
	static const int LEN = 1e7;
	static char buf[LEN];
	static int s = 0, t = 0;
	s == t ? s = 0, t = fread(buf, 1, LEN, stdin) : 0;
	return s == t ? -1 : buf[s++];
}

template<class T>
inline void read(T &val)
{
	int m, c;
	for (m = 1, c = gc(); !isdigit(c); c = gc())
		m = c == '-' ? -1 : 1;
	if(c == -1) return;
	for (val = 0; isdigit(c); c = gc())
		val = (val << 3) + (val << 1) + (c - '0');
	val = m == -1 ? -val : val;
}
}

namespace Twocakes
{
const int maxn = 1e6 + 5;

int n, a[maxn], b[maxn], c[maxn], f[maxn];
vector<int> d[maxn << 1];

inline int find(int dis, int val)
{
	int l = 0, r = d[dis].size() - 1, ans = 1e9, mid = 0;
	while(l <= r) 
		if(d[dis][mid = ((l + r) >> 1)] <= val) l = (ans = mid) + 1;
		else r = mid - 1;
	return ans == 1e9 ? 0 : d[dis][ans];
}

inline int dp(int i, int j)
{
	if(!i || !j) return i + j;
	if(a[i] == b[j]) return f[i] ? f[i] : f[i] = min(dp(i - 1, j), dp(i, j - 1)) + 1;
	int k = find(i - j + n, i);
	// f[i][j] = f[i - k - 1][j - k - 1] + t;
	return k ? dp(k, j - i + k) + (i - k) : max(i, j);
}

inline void solve()
{
	using namespace IO;
	read(n);
	for (R int i = 1; i <= n; ++i) read(a[i]);
	for (R int i = 1; i <= n; ++i) read(b[i]), c[b[i]] = i;
	// i - c[a[i]] -> 相同数字的距离
	for (R int i = 1; i <= n; ++i) d[i - c[a[i]] + n].push_back(i);
	printf("%d\n", dp(n, n));
}
}

int main()
{
	Twocakes::solve();
	return 0;
}