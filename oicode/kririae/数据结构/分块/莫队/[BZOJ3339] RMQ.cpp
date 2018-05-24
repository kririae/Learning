// by kririae
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace Mex
{
template<typename T>
inline void read(T &val)
{
	val = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) val = (val << 1) + (val << 3) + c - 48, c = getchar();
}

const int maxn = 200005;

struct Q
{
	int l, r, pos, id;
	bool operator < (const Q &a) const {
		if(pos == a.pos)
		{
			if(pos & 1) return r < a.r;
			else return r > a.r;
		} else return pos < a.pos;
	}
} q[maxn];

int n, m, siz, l = 1, r = 0, ans, a[maxn], res[maxn], cnt[maxn];

inline void add(int val)
{
	++cnt[val]; 
	while(cnt[ans]) ++ans;
}

inline void del(int val)
{
	--cnt[val], ans = cnt[val] == 0 ? min(ans, val) : ans;
}

inline void solve()
{
	read(n), read(m);
	siz = sqrt(n);
	for (R int i = 1; i <= n; ++i) read(a[i]);
	for (R int i = 1; i <= m; ++i)
		read(q[i].l), read(q[i].r), q[i].id = i, q[i].pos = q[i].l / siz;
	sort(q + 1, q + 1 + m);
	
	for (R int i = 1; i <= m; ++i)
	{
		Q curr = q[i];
		while(r > curr.r) del(a[r--]);
		while(r < curr.r) add(a[++r]);
		while(l < curr.l) del(a[l++]);
		while(l > curr.l) add(a[--l]);
		res[curr.id] = ans;
	}
	
	for (int i = 1; i <= m; ++i)
		printf("%d\n", res[i]);
}
}

int main()
{
	Mex::solve();
	return 0;
}