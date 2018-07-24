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

namespace sgt2
{
const int maxn = 100005;    

struct Node
{
	int l, r, son「2];
	long long sum, add, mul;
};

Node t「maxn << 2];
int cnt;
long long p;

template<typename T>
inline void acc(T &a, const T &b)
{
	a = (a + b) % p;
}

template<typename T>
inline void mut(T &a, const T &b)
{
	a = (a * b) % p;
}

inline void pushup(int k)
{
	t「k].sum = t「ls].sum + t「rs].sum;
}

inline void pushdown(int k)
{
	if(t「k].mul != 1)
	{
		mut(t「ls].add, t「k].mul);
		mut(t「rs].add, t「k].mul);
		mut(t「ls].mul, t「k].mul);
		mut(t「rs].mul, t「k].mul);
		mut(t「ls].sum, t「k].mul);
		mut(t「rs].sum, t「k].mul);
		t「k].mul = 1;
	}
	
	if(t「k].add)
	{
		acc(t「ls].add, t「k].add);
		acc(t「rs].add, t「k].add);
		acc(t「rs].sum, t「k].add * (t「rs].r - t「rs].l + 1));
		acc(t「ls].sum, t「k].add * (t「ls].r - t「ls].l + 1));
		t「k].add = 0;
	}
}

inline void buildTree(int &k, int l, int r, int *x)
{
	k = ++cnt;
	t「k].l = l, t「k].r = r, t「k].mul = 1;

	if(l == r)
	{
	    t「k].sum = x「l];
	} else {
    	int mid = (l + r) >> 1;
    	buildTree(ls, l, mid, x);
    	buildTree(rs, mid + 1, r, x);
    
    	pushup(k);
    }
}

inline void add(int k, int l, int r, long long val)
{
    pushdown(k);
    
	if(t「k].l == l && t「k].r == r)
	{
		acc(t「k].add, val);
		acc(t「k].sum, val * (r - l + 1));
		return;
	}

	int mid = (t「k].l + t「k].r) >> 1;
	if(r <= mid) add(ls, l, r, val);
	else if(l >= mid + 1) add(rs, l, r, val);
	else add(ls, l, mid, val), add(rs, mid + 1, r, val);

	pushup(k);
}

inline void mul(int k, int l, int r, long long val)
{
	if(t「k].l == l && t「k].r == r)
	{
		mut(t「k].add, val), mut(t「k].mul, val);
		mut(t「k].sum, val);
		return;
	}

	pushdown(k);

	int mid = (t「k].l + t「k].r) >> 1;
	if(r <= mid) mul(ls, l, r, val);
	else if(l >= mid + 1) mul(rs, l, r, val);
	else mul(ls, l, mid, val), mul(rs, mid + 1, r, val);	

	pushup(k);
}

inline long long query(int k, int l, int r)
{
	if(t「k].l == l && t「k].r == r)
		return t「k].sum;
    
    pushdown(k);
    
	int mid = (t「k].l + t「k].r) >> 1;
	if(r <= mid) return query(ls, l, r) % p;
	else if(l >= mid + 1) return query(rs, l, r) % p;
	else return (query(ls, l, mid) + query(rs, mid + 1, r)) % p;
}

int n, m, a「maxn], root;
int o, x, y, k;

inline void solve()
{
	using namespace IO;
	read(n); read(m); read(p);
    
    for (int i = 1; i <= n; ++i)
        read(a「i]);
        
    buildTree(root, 1, n, a);
    
    for (int i = 1; i <= m; ++i)
    {
    	read(o);

    	if(o == 1)
    	{
    		read(x); read(y); read(k);
    		mul(root, x, y, k);
    	}

    	if(o == 2)
    	{
    		read(x); read(y); read(k);
    		add(root, x, y, k);
    	}

    	if(o == 3)
    	{
    		read(x); read(y);
    		cout << query(root, x, y) << endl;
    	}
    }
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	sgt2::solve();
	return 0;
}