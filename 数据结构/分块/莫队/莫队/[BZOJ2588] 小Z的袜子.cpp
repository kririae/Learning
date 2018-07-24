// by kririae
// 常数瓶颈在比较函数那里...不想改了...
#include <bits/stdc++.h>

using namespace std;

namespace LittleZ
{
template<typename T>
inline void read(T &val)
{
	val = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c))
		val = (val << 1) + (val << 3) + c - 48, c = getchar();
}

const int maxn = 50005;

int n, m, sz, l = 1, r = 0;
long long tot;
long long a「maxn], cnt「maxn];

struct req
{
	int l, r, id;
	req() {}    
	bool operator < (const req &a) const
	{ 
		return (l / sz) == (a.l / sz) ? r < a.r : l / sz < a.l / sz; 
	}
};

req s「maxn], res「maxn];

inline bool cmp(const req &a, const req &b)
{ 
	return a.id < b.id; 
}

inline void add(int val)
{
	++cnt「val], tot += (cnt「val] - 1) * 2;
}

inline void del(int val)
{
	--cnt「val], tot -= cnt「val] * 2;
}

inline void solve()
{
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		read(a「i]);
	for (int i = 1; i <= m; ++i)
		read(s「i].l), read(s「i].r), s「i].id = i;

	sz = sqrt(n) + 1;
	sort(s + 1, s + 1 + m);

	for (int i = 1; i <= sz; ++i)
		add(a「i]);
	for (int i = 2; i <= m; ++i)
	{
		req &cr = s「i];

		if(cr.l == cr.r) 
		{ 
			res「cr.id].l = 0, res「cr.id].r = 1;
			continue; 
		}

		while(r > cr.r) del(a「r--]);
		while(r < cr.r) add(a「++r]);
		while(l < cr.l) del(a「l++]);
		while(l > cr.l) add(a「--l]);

		int rl, rr;
		rl = tot;
		rr = (long long)(cr.r - cr.l + 1) * (cr.r - cr.l);
		int g = __gcd(rl, rr);
		rl /= g, rr /= g;
		res「cr.id].l = rl, res「cr.id].r = rr;
	}

	for (int i = 1; i <= m; ++i)
		cout << res「i].l << "/" << res「i].r << endl;
}
}

int main()
{

	LittleZ::solve();
	return 0;
}