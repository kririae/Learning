// by kririae
// status: WA???
// BZOJ4293
#define ls t[k].son[0]
#define rs t[k].son[1]
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
		val = (val << 3) + (val << 1) + c - '0';
 	val = m == -1 ? -val : val;
}
}

namespace Siano
{
const int maxn = 500005;

struct Node
{
	int l, r, son[2];
	long long sum, add, set, max;
	Node(): set(-1) {}
};

Node t[maxn << 2];
int cnt, root;
int n, m;
long long d, b, pre, a[maxn];

inline void pushup(int k)
{
	t[k].sum = t[ls].sum + t[rs].sum;
	t[k].max = max(t[ls].max, t[rs].max);
}

inline void pushdown(int k)
{
	if(t[k].set != -1)
	{
		t[ls].set = t[rs].set = t[k].set;
		t[ls].sum = t[k].set * (t[ls].r - t[ls].l + 1);
		t[rs].sum = t[k].set * (t[rs].r - t[rs].l + 1);
		t[ls].max = t[rs].max = t[k].set;
		t[k].set = -1, t[ls].add = 0, t[rs].add = 0;
	}

	if(t[k].add)
	{
		t[ls].add += t[k].add, t[rs].add += t[k].add;
		t[ls].sum += t[k].add * (a[t[ls].r] - a[t[ls].l - 1]);
		t[rs].sum += t[k].add * (a[t[rs].r] - a[t[rs].l - 1]);
		t[ls].max += t[k].add * (a[t[ls].r] - a[t[ls].r - 1]);
		t[rs].max += t[k].add * (a[t[rs].r] - a[t[rs].r - 1]);
		t[k].add = 0;
	}
}

inline void buildTree(int &k, int l, int r)
{
	k = ++cnt;
	t[k].l = l, t[k].r = r;

	if(l == r) 
	{
		return;
	}

	int mid = (l + r) >> 1;
	buildTree(ls, l, mid);
	buildTree(rs, mid + 1, r);
}

inline long long cut(int k, int l, int r, int val)
{
	if(t[k].l == l && t[k].r == r)
	{
		t[k].set = val, t[k].add = 0, t[k].max = val;
		long long tmp = t[k].sum;
		t[k].sum = val * (r - l + 1);
		return tmp - t[k].sum;
	}
	
	pushdown(k);

	int mid = (t[k].l + t[k].r) >> 1;
	long long ans = 0;
	if(r <= mid) ans = cut(ls, l, r, val);
	else if (l > mid) ans = cut(rs, l, r, val);
	else ans = cut(ls, l, mid, val) + cut(rs, mid + 1, r, val);

	pushup(k);
	return ans;
}

inline int get(int k, int val)
{
	if(t[k].l == t[k].r) return t[k].sum < val ? 0 : t[k].l;

	pushdown(k);

	int mid = (t[k].l + t[k].r) >> 1;
	if(t[ls].max >= val) return get(ls, val);
	else return get(rs, val);
}

inline void add(int val)
{
	t[root].add += val;
	t[root].sum += (a[n] * val);
	t[root].max += ((a[n] - a[n - 1]) * val);
}

inline int solve()
{
	using namespace IO;
	read(n); read(m);

	for (int i = 1; i <= n; ++i)
		read(a[i]);
	
	sort(a + 1, a + 1 + n);

	buildTree(root, 1, n);

	for (int i = 1; i <= n; ++i)
		a[i] += a[i - 1];
	
	for (int i = 1; i <= m; ++i)
	{
		read(d); read(b);
		add(d - pre);
		
		int l = get(root, b);
		cout << (l == 0 ? 0 : cut(root, l, n, b)) << endl;

		pre = d;
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	Siano::solve();
	return 0;
}