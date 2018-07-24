// by kririae
// 并查集？
#define R register
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char gc()
{
		static const int LEN = 1e7;
		static char buf「LEN];
		static int s = 0, t = 0;
		s == t ? s = 0, t = fread(buf, 1, LEN, stdin) : 0;
		return s == t ? -1 : buf「s++];
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

namespace BZOJ1050
{
const int maxn = 505;
const int maxm = 5005;

struct Edge
{
	int from, to, val;
	bool operator < (const Edge &a) const { return val < a.val; }
} edges「maxm];

int n, m, S, T, flag, fa「maxn];

inline int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

inline int find(int val)
{
	return val == fa「val] ? val : fa「val] = find(fa「val]);
}

inline int kruskal(int s)
{
	for (int i = 1; i <= n; ++i) fa「i] = i;
	for (int i = s; i <= m; ++i)
	{
		Edge &e = edges「i];
		int a = find(e.from), b = find(e.to);
		if(a != b) fa「a] = b;
		if(find(S) == find(T)) return e.val;
	}
	return -1;
}

inline void solve()
{
	using namespace IO;
	read(n), read(m);
	for (R int i = 1; i <= m; ++i) 
		read(edges「i].from), read(edges「i].to), read(edges「i].val);
	read(S), read(T);
	sort(edges + 1, edges + 1 + m);

	double ans = 1e9; 
	int ans1, ans2;
	for (int i = 1; i < m; ++i)
	{
		if(edges「i].val == edges「i - 1].val) continue;
		int ret = kruskal(i);
		if(ret == -1) continue;
		flag = 1;
		int tmp1 = edges「i].val, tmp2 = ret;
		if((double)tmp2 / tmp1 < ans)
			ans = (double)tmp2 / tmp1, ans1 = tmp1, ans2 = tmp2;
	}
	int g = gcd(ans1, ans2);
	if(!flag) cout << "IMPOSSIBLE" << endl;
	else if(ans1 / g == 1) cout << ans2 / g << endl;
	else cout << ans2 / g << "/" << ans1 / g << endl;
}
}

int main()
{
	BZOJ1050::solve();
	return 0;
}