// by kririae
// SCOI2010
#define ls t「k].son「0]
#define rs t「k].son「1]
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char read()
{
	static const int IN_LEN = 1000000;
	static char buf「IN_LEN], *s, *t;
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
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c); c = read()) 
		x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}
}

namespace SCOI2010
{
const int maxn = 100005;

struct Node
{
	int l, r, son「2];
	int l1, r1, m1, l0, r0, m0, sum;
	int s, rev;
	// 左边开始有多少个1，右边开始有多少个1，中间有多少个1, 总共有多少个1
	// 变为0，变为1，全部翻转
	Node(): s(-1) {}
};

Node t「maxn << 2];
int root, cnt;
int n, m, a「maxn], op, x, y;

inline int len(const Node &val)
{
	return val.r - val.l + 1;
}

template<typename T>
inline void swap(T &a, T &b)
{
	T c;
	c = a, a = b, b = c;
}

inline void merge(Node &k, Node a, Node b)
{
	k.m1 = max(a.r1 + b.r1, max(a.m1, b.m1));
	
	if(a.l1 == len(a))
		k.l1 = a.l1 + b.l1;
	else k.l1 = a.l1;
	
	if(b.r1 == len(b))
		k.r1 = b.r1 + a.r1;
	else k.r1 = b.r1;
	
	k.m0 = max(a.r0 + b.r0, max(a.m0, b.m0));

	if(a.l0 == len(a))
		k.l0 = a.l0 + b.l0;
	else k.l0 = a.l0;
	
	if(b.r0 == len(b))
		k.r0 = b.r0 + a.r0;
	else k.r0 = b.r0;
}

inline void pushup(int k)
{
	t「k].sum = t「ls].sum + t「rs].sum;
	merge(t「k], t「ls], t「rs]);
}

inline void pushdown(int k)
{
	if (t「k].s == 0)
	{
		t「ls].sum = t「rs].sum = 0;
		t「ls].rev = t「rs].rev = 0;
		t「ls].s = t「rs].s = t「k].s;
		t「ls].sum = 0;

		t「ls].l0 = t「ls].r0 = t「ls].m0 = len(t「ls]);
		t「rs].l0 = t「rs].r0 = t「rs].m0 = len(t「rs]),

		t「ls].l1 = t「ls].r1 = t「ls].m1 = t「rs].l1 = t「rs].r1 = t「rs].m1 = 0;
		t「k].s = -1;
	}

	if (t「k].s == 1)
	{
		t「ls].sum = len(t「ls]), t「rs].sum = len(t「rs]);
		t「ls].rev = t「rs].rev = 0;
		t「ls].s = t「rs].s = t「k].s;

		t「ls].l1 = t「ls].r1 = t「ls].m1 = len(t「ls]);
		t「rs].l1 = t「rs].r1 = t「rs].m1 = len(t「rs]),

		t「ls].l0 = t「ls].r0 = t「ls].m0 = t「rs].l0 = t「rs].r0 = t「rs].m0 = 0;
		t「k].s = -1;
	}

	if (t「k].rev)
	{
		t「ls].rev ^= 1, t「rs].rev ^= 1;
		t「ls].sum = len(t「ls]) - t「ls].sum, t「rs].sum = len(t「rs]) - t「rs].sum;

		swap(t「ls].l1, t「ls].l0), swap(t「ls].r1, t「ls].r0), swap(t「ls].m1, t「ls].m0);
		swap(t「rs].l1, t「rs].l0), swap(t「rs].r1, t「rs].r0), swap(t「rs].m1, t「rs].m0);
		t「k].rev = 0;
	}
}

inline void buildTree(int &k, int l, int r, int *x)
{
	k = ++cnt;
	t「k].l = l, t「k].r = r;

	if (l == r)
	{
		t「k].l1 = t「k].r1 = t「k].m1 = t「k].sum = x「l];
		t「k].l0 = t「k].r0 = t「k].m0 = (x「l] ^ 1), t「k].rev = 0;
		return;
	}

	int mid = (l + r) >> 1;
	buildTree(ls, l, mid, x);
	buildTree(rs, mid + 1, r, x);
	
	pushup(k);
}

inline void modify0(int k, int l, int r)
{
	if (t「k].l == l && t「k].r == r)
	{
		t「k].rev = 0, t「k].s = 0, t「k].sum = 0;
		t「k].l0 = t「k].r0 = t「k].m0 = len(t「k]);
		t「k].l1 = t「k].r1 = t「k].m1 = 0;
		return;
	}

	pushdown(k);

	int mid = (t「k].l + t「k].r) >> 1;
	if (r <= mid) modify0(ls, l, r);
	else if (l > mid) modify0(rs, l, r);
	else modify0(ls, l, mid), modify0(rs, mid + 1, r);

	pushup(k);
}

inline void modify1(int k, int l, int r)
{
	if (t「k].l == l && t「k].r == r)
	{
		t「k].rev = 0, t「k].s = 1, t「k].sum = len(t「k]);
		t「k].l0 = t「k].r0 = t「k].m0 = 0;
		t「k].l1 = t「k].r1 = t「k].m1 = len(t「k]);
		return;
	}

	pushdown(k);

	int mid = (t「k].l + t「k].r) >> 1;
	if (r <= mid) modify1(ls, l, r);
	else if (l > mid) modify1(rs, l, r);
	else modify1(ls, l, mid), modify1(rs, mid + 1, r);

	pushup(k);
}

inline void rev(int k, int l, int r)
{
	if (t「k].l == l && t「k].r == r)
	{
		t「k].rev ^= 1, t「k].sum = len(t「k]) - t「k].sum;
		swap(t「k].l1, t「ls].l0), swap(t「k].r1, t「k].r0), swap(t「k].m1, t「k].m0);
		return;
	}

	pushdown(k);

	int mid = (t「k].l + t「k].r) >> 1;
	if (r <= mid) rev(ls, l, r);
	else if (l > mid) rev(rs, l, r);
	else rev(ls, l, mid), rev(rs, mid + 1, r);

	pushup(k);
}

inline int sum(int k, int l, int r)
{
	if (t「k].l == l && t「k].r == r)
		return t「k].sum;

	pushdown(k);

	int mid = (t「k].l + t「k].r) >> 1;
	if (r <= mid) return sum(ls, l, r);
	else if (l > mid) return sum(rs, l, r);
	else return sum(ls, l, mid) + sum(rs, mid + 1, r);
}

inline Node con(int k, int l, int r)
{
	if (t「k].l == l && t「k].r == r)
		return t「k];

	pushdown(k); // 查询操作有很多骚操作...
	
	Node p1, p2, ret;
	int mid = (t「k].l + t「k].r) >> 1; 
	if (r <= mid) return con(ls, l, r);
	else if (l > mid) return con(rs, l, r);
	else p1 = con(ls, l, mid), p2 = con(rs, mid + 1, r);
	
	ret.l = p1.l, ret.r = p2.r;
	merge(ret, p1, p2);
	return ret;
}

inline void solve()
{
	freopen("seq.txt", "r", stdin); 
	freopen("kri.txt", "w", stdout);
	using namespace IO;
	// read(n); read(m);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		// read(a「i]);
		cin >> a「i];

	buildTree(root, 1, n, a);
	
	for (int i = 1; i <= m; ++i)
	{
		cin >> op >> x >> y;
		++x, ++y;
		switch(op) {
		case 0:
			modify0(root, x, y);
			break;
		case 1:
			modify1(root, x, y);
			break;
		case 2:
			rev(root, x, y);
			break;
		case 3:
			cout << sum(root, x, y) << endl;
			break;
		case 4:
			cout << con(root, x, y).m1 << endl;
			break;
		}
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	SCOI2010::solve();
	return 0;
}