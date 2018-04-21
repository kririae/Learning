// by kririae
// SCOI2010
#define ls t[k].son[0]
#define rs t[k].son[1]
#include <bits/stdc++.h>

using namespace std;

namespace IO
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
	int l, r, son[2];
	int ll1, rl1, ml1, ll0, rl0, ml0, sum;
	int s, rev;
	// 左边开始有多少个1，右边开始有多少个1，中间有多少个1, 总共有多少个1
	// 变为0，变为1，全部翻转
	Node(): s(-1) {}
};

Node t[maxn << 2];
int root, cnt;
int n, m, a[maxn], op, x, y;

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

// inline void merge(Node &k, Node a, Node b)
// {
// 	k.ml1 = max(b.ml1, max(a.rl1 + b.ll1, a.ml1));

// 	if(a.ll1 == len(a))
// 		k.ll1 = a.ll1 + b.ll1;
// 	else k.ll1 = a.ll1;
	
// 	if(b.rl1 == len(b))
// 		k.rl1 = b.rl1 + a.rl1;
// 	else k.rl1 = b.rl1;
	
// 	k.ml0 = max(b.ml0, max(a.rl0 + b.ll0, a.ml0));

// 	if(a.ll0 == len(a))
// 		k.ll0 = a.ll0 + b.ll0;
// 	else k.ll0 = a.ll0;
	
// 	if(b.rl0 == len(b))
// 		k.rl0 = b.rl0 + a.rl0;
// 	else k.rl0 = b.rl0;
// }

inline void merge(Node &k, Node a, Node b)
{
	k.ml1 = max(b.rl1, max(a.rl1 + b.ll1, a.ll1));

	if(a.ll1 == len(a))
		k.ll1 = a.ll1 + b.ll1;
	else k.ll1 = a.ll1;
	
	if(b.rl1 == len(b))
		k.rl1 = b.rl1 + a.rl1;
	else k.rl1 = b.rl1;
	
	k.ml0 = max(b.rl0, max(a.rl0 + b.ll0, a.ll0));

	if(a.ll0 == len(a))
		k.ll0 = a.ll0 + b.ll0;
	else k.ll0 = a.ll0;
	
	if(b.rl0 == len(b))
		k.rl0 = b.rl0 + a.rl0;
	else k.rl0 = b.rl0;
}

inline void pushup(int k)
{
	t[k].sum = t[ls].sum + t[rs].sum;
	merge(t[k], t[ls], t[rs]);
}

inline void pushdown(int k)
{
	if(t[k].s == 0)
	{
		t[ls].sum = t[rs].sum = 0;
		t[ls].rev = t[rs].rev = 0;
		t[ls].s = t[rs].s = t[k].s;
		t[ls].sum = 0;

		t[ls].ll0 = t[ls].rl0 = t[ls].ml0 = len(t[ls]);
		t[rs].ll0 = t[rs].rl0 = t[rs].ml0 = len(t[rs]),

		t[ls].ll1 = t[ls].rl1 = t[ls].ml1 = t[rs].ll1 = t[rs].rl1 = t[rs].ml1 = 0;
		t[k].s = -1;
	}

	if(t[k].s == 1)
	{
		t[ls].sum = len(t[ls]), t[rs].sum = len(t[rs]);
		t[ls].rev = t[rs].rev = 0;
		t[ls].s = t[rs].s = t[k].s;

		t[ls].ll1 = t[ls].rl1 = t[ls].ml1 = len(t[ls]);
		t[rs].ll1 = t[rs].rl1 = t[rs].ml1 = len(t[rs]),

		t[ls].ll0 = t[ls].rl0 = t[ls].ml0 = t[rs].ll0 = t[rs].rl0 = t[rs].ml0 = 0;
		t[k].s = -1;
	}

	if(t[k].rev)
	{
		t[ls].rev ^= 1, t[rs].rev ^= 1;
		t[ls].sum = len(t[ls]) - t[ls].sum, t[rs].sum = len(t[rs]) - t[rs].sum;

		swap(t[ls].ll1, t[ls].ll0), swap(t[ls].rl1, t[ls].rl0), swap(t[ls].ml1, t[ls].ml0);
		swap(t[rs].ll1, t[rs].ll0), swap(t[rs].rl1, t[rs].rl0), swap(t[rs].ml1, t[rs].ml0);
		t[k].rev = 0;
	}
}

inline void buildTree(int &k, int l, int r, int *x)
{
	k = ++cnt;
	t[k].l = l, t[k].r = r;

	if(l == r)
	{
		t[k].ll1 = t[k].rl1 = t[k].ml1 = t[k].sum = x[l];
		t[k].ll0 = t[k].rl0 = t[k].ml0 = (x[l] ^ 1), t[k].rev = 0;
		return;
	}

	int mid = (l + r) >> 1;
	buildTree(ls, l, mid, x);
	buildTree(rs, mid + 1, r, x);
	
	pushup(k);
}

inline void modify0(int k, int l, int r)
{
	if(t[k].l == l && t[k].r == r)
	{
		t[k].rev = 0, t[k].s = 0, t[k].sum = 0;
		t[k].ll0 = t[k].rl0 = t[k].ml0 = len(t[k]);
		t[k].ll1 = t[k].rl1 = t[k].ml1 = 0;
		return;
	}

	pushdown(k);

	int mid = (t[k].l + t[k].r) >> 1;
	if(r <= mid) modify0(ls, l, r);
	else if (l > mid) modify0(rs, l, r);
	else modify0(ls, l, mid), modify0(rs, mid + 1, r);

	pushup(k);
}

inline void modify1(int k, int l, int r)
{
	if(t[k].l == l && t[k].r == r)
	{
		t[k].rev = 0, t[k].s = 1, t[k].sum = len(t[k]);
		t[k].ll0 = t[k].rl0 = t[k].ml0 = 0;
		t[k].ll1 = t[k].rl1 = t[k].ml1 = len(t[k]);
		return;
	}

	pushdown(k);

	int mid = (t[k].l + t[k].r) >> 1;
	if(r <= mid) modify1(ls, l, r);
	else if (l > mid) modify1(rs, l, r);
	else modify1(ls, l, mid), modify1(rs, mid + 1, r);

	pushup(k);
}

inline void rev(int k, int l, int r)
{
	if(t[k].l == l && t[k].r == r)
	{
		t[k].rev ^= 1, t[k].sum = len(t[k]) - t[k].sum;
		swap(t[k].ll1, t[ls].ll0), swap(t[k].rl1, t[k].rl0), swap(t[k].ml1, t[k].ml0);
		return;
	}

	pushdown(k);

	int mid = (t[k].l + t[k].r) >> 1;
	if(r <= mid) rev(ls, l, r);
	else if (l > mid) rev(rs, l, r);
	else rev(ls, l, mid), rev(rs, mid + 1, r);

	pushup(k);
}

inline int sum(int k, int l, int r)
{
	if(t[k].l == l && t[k].r == r)
		return t[k].sum;

	pushdown(k);

	int mid = (t[k].l + t[k].r) >> 1;
	if(r <= mid) return sum(ls, l, r);
	else if(l > mid) return sum(rs, l, r);
	else return sum(ls, l, mid) + sum(rs, mid + 1, r);
}

inline Node con(int k, int l, int r)
{
	if(t[k].l == l && t[k].r == r)
		return t[k];

	pushdown(k); // 查询操作有很多骚操作...
	
	Node p1, p2, ret;
	int mid = (t[k].l + t[k].r) >> 1; 
	if(r <= mid) return con(ls, l, r);
	else if(l > mid) return con(rs, l, r);
	else p1 = con(ls, l, mid), p2 = con(rs, mid + 1, r);
	
// 	ret.l = p1.l, ret.r = p2.r;
// 	merge(ret, p1, p2);
// 	ret.son[0] = ret.son[1] = 0; // 为了保证不输出0
	
	ret.l = p1.l, ret.r = p2.r;
	if(p1.sum == len(p1)) ret.ll1 = p1.sum + p2.ll1;
	else ret.ll1 = p1.ll1;
	if(p2.sum == len(p2)) ret.rl1 = p2.sum + p1.rl1;
	else ret.rl1 = p2.rl1;
	ret.ml1 = max(p1.rl1 + p2.ll1, max(p1.ml1, p2.ml1));
	return ret;
}

/*
可能会出错的位置：
由于修改了大量的len函数，添加merge函数...可能会出现之前的不兼容的问题
con函数返回时的ls和rs有没有问题？ -> qwq
 */

inline void solve()
{
	using namespace IO;
	// read(n); read(m);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		// read(a[i]);
		cin >> a[i];

	buildTree(root, 1, n, a);
	
	for (int i = 1; i <= m; ++i)
	{
		// read(op); read(x); read(y);
		// for (int j = 1; j <= n; ++j)
		//     cout << sum(root, j, j) << " ";
		// cout << "-> ";

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
			cout << con(root, x, y).ml1 << endl;
			break;
		}
		
		// for (int j = 1; j <= n; ++j)
		//     cout << sum(root, j, j) << " ";
		// cout << "--- " << op << " " << x << " " << y << endl;
		// cout << "------------------------------------------" << endl;
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