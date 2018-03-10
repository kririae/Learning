// lirewriter ver
// 全无脑merge split 我喜欢
#include <bits/stdc++.h>
#define ls t[k].son[0]
#define rs t[k].son[1]
using namespace std;

namespace fhqtreap
{
const int maxn = 1e5 + 5;

struct node
{
	int size, val, key, rev;
	int son[2];
	node() {}
};

node t[maxn];
int cnt, root;

inline void pushup(int k)
{
	t[k].size = t[ls].size + t[rs].size + 1;
}

inline void pushdown(int k)
{
	if(k && t[k].rev)
	{
		t[ls].rev ^= 1, t[rs].rev ^= 1;
		t[k].rev = 0; swap(ls, rs);
	}
}

inline void make_heap(int& k, int val)
{
	k = ++cnt, t[k].val = val, t[k].size = 1, t[k].key = rand(), t[k].rev = 0;
}

inline void merge(int& k, int a, int b)
{   // 和可并堆一个原理 nlogn
	if (!a || !b) { k = a + b; return; } // 取有值的一个
	pushdown(a); pushdown(b);
	if (t[a].key < t[b].key) k = a, merge(rs, rs, b);
	else k = b, merge(ls, a, ls);
	pushup(k);
}

inline void split(int k, int& a, int& b, int key)
{
	if (!k) { a = b = 0; return; }
	pushdown(k);
	if (key <= t[ls].size) b = k, split(ls, a, ls, key);
	else a = k, split(rs, rs, b, key-  t[ls].size - 1);
	pushup(k);
}

inline void insert(int val)
{
	make_heap(val, val), merge(root, root, val);
}

inline void del(int val)
{
	int k, a, b; k = a = b = 0;
	split(root, a, b, val); // 按照val分割到a, b
	split(a, a, k, val - 1); // 按照val - 1把a子树分割到a, k上
	merge(k, ls, rs); // 删除当前节点
	merge(a, a, k); // 无脑合并
	merge(root, a, b);
}

inline void reverse(int l, int r)
{
	int a, b, c, d;
	split(root, a, b, r);
	split(a, c, d, l - 1);
	t[d].rev ^= 1;
	merge(a, c, d);
	merge(root, a, b);
}

inline int getrank(int val)
{
	int a, b; a = b = 0;
	split(root, a, b, val - 1);
	int ans = t[a].size + 1;
	merge(root, a, b);
	return ans;
}

inline int getkth(int k, int val)
{
	for (;;)
	{
		if (t[ls].size >= val) k = ls;
		else if (t[ls].size + 1 == val) return k;
		else val -= (t[ls].size + 1), k = rs;
	}
}

inline int pre(int val)
{
	int a, b; a = b = 0;
	split(root, a, b, val - 1);
	int ans = getkth(a, t[a].size);
	merge(root, a, b);
	return ans;
}

inline int nxt(int val)
{
	int a, b; a = b = 0;
	split(root, a, b, val);
	int ans = getkth(b, 1);
	merge(root, a, b);
	return ans;
}

inline void print(int k)
{
    if(t[k].rev) pushdown(k);
	if(ls) print(ls);
	cout << t[k].val << " ";
	if(rs) print(rs);
}
}

int n, m;
int l, r;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	using namespace fhqtreap;
	srand(time(NULL));
	root = 0, t[0].key = t[0].val = ~(1 << 31);
	cin >> n >> m;
 	for (int i = 1; i <= n; ++i) insert(i);
	for (int i = 1; i <= m; ++i) 
	{
	    cin >> l >> r;
	    reverse(l, r);
	}
	print(root);
	return 0;
}