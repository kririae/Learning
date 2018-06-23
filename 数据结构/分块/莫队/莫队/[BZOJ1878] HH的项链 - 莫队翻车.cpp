#pragma GCC optimize("Ofast")
// by kririae
// 用莫队来做是不是有一点刷水题的意味
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace BZOJ1878
{
const int maxn = 50005;
const int maxm = 200005;

template<typename T>
inline void read(T &val)
{
	val = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) val = (val << 1) + (val << 3) + c - 48, c = getchar();
}

struct Q
{
	int l, r, pos, id;
	bool operator < (const Q &a) const {
		if(pos == a.pos)
		{
			if(pos & 1) return r <= a.r;
			else return r > a.r;
		} else return pos < a.pos;
	}
} q[maxm];

int n, m, sz, ans, l = 1, r = 0, a[maxn], cnt[1000005], res[maxm];

inline void add(int val)
{
	if(cnt[val] == 0) ++ans;
	++cnt[val];
}

inline void del(int val)
{
	--cnt[val];
	if(cnt[val] == 0) --ans;
}

inline void solve()
{
	freopen("1.in", "r", stdin);
	freopen("krr.out", "w", stdout);
	read(n);
	sz = sqrt(n) + 1;
	for (R int i = 1; i <= n; ++i) read(a[i]);
	read(m);
	for (R int i = 1; i <= m; ++i) 
		read(q[i].l), read(q[i].r), q[i].id = i, q[i].pos = (q[i].l - 1) / sz + 1;
	sort(q + 1, q + 1 + m);

	for (R int i = 1; i <= m; ++i)
	{
		Q &curr = q[i];
		while(r > curr.r) del(a[r--]);
		while(r < curr.r) add(a[++r]);
		while(l < curr.l) del(a[l++]);
		while(l > curr.l) add(a[--l]);
		res[curr.id] = ans;
	}

	for (R int i = 1; i <= m; ++i)
		printf("%d\n", res[i]);
}
}

int main()
{
    BZOJ1878::solve();
	return 0;
}
