title: 「学习笔记」数据结构专题
author: kririae
tags:
  - 数据结构
  - 线段树
  - 主席树
categories:
  - oi
date: 2018-04-14 06:01:00
---
# 线段树专题

---

<!--more-->

因为之前线段树基础不牢的原因...吃了不少亏。故重新开始线段树的学习。

## 线段树总结

线段树难点在“维护的信息”和“维护啥信息”。
在不熟练的时候，主要问题在于“我的标签该怎么传下去?”
首先pushdown的时候要分清楚到底是先pushdown哪个标签，下一个标签过去了会不会把之前pushdown的标签覆盖了，pushup就是总结，但是总结也可能很复杂。在modify的时候，找到了最终节点第一步是把标签打到这个节点上，然后对节点原本有的信息进行修改。查询的时候直接返回需要查询的信息就对了，因为之前已经pushdown到这里了   
线段树通常维护“从左右开始的区间信息”，和“中间的信息”，详见SCOI2010的序列修改和动态最大子段和。

## 线段树模板

[poj3468](http://poj.org/problem?id=3468)

### 代码
```cpp
#define ls t[k].son[0]
#define rs t[k].son[1]
#include <iostream>
#include <cstdio>

using namespace std;

namespace SegmentTree
{
const int maxn = 100005;
struct Node
{
	int l, r, son[2];
	long long add, mul;
	long long sum;
	Node() {}
};

Node t[maxn << 2];
int cnt, p;
long long a[maxn];

inline void pushup(int k)
{
	t[k].sum = (t[ls].sum + t[rs].sum);
}

inline void pushdown(int k)
{
	if(t[k].add)
	{
		t[ls].add = (t[ls].add + t[k].add);
		t[rs].add = (t[rs].add + t[k].add);
		t[ls].sum = (t[ls].sum + t[k].add * (t[ls].r - t[ls].l + 1));
		t[rs].sum = (t[rs].sum + t[k].add * (t[rs].r - t[rs].l + 1));
		t[k].add = 0;
	}
}

inline void buildTree(int &k, int l, int r)
{
	k = ++cnt;
	t[k].l = l, t[k].r = r, t[k].sum = 0, t[k].add = 0, t[k].mul = 1;
	if(l == r) { t[k].sum = a[l]; return; }
	int mid = (l + r) >> 1;
	buildTree(ls, l, mid), buildTree(rs, mid + 1, r);
	pushup(k);
}

inline void add(int k, int l, int r, int val)
{
	if(t[k].l == l && t[k].r == r)
	{
		t[k].add = (t[k].add + val);
		t[k].sum = (t[k].sum + val * (r - l + 1));
		return;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	pushdown(k);
	
	if(r <= mid) add(ls, l, r, val);
	else if(l >= mid + 1) add(rs, l, r, val);
	else add(ls, l, mid, val), add(rs, mid + 1, r, val);
	
	pushup(k);
}

inline long long query(int k, int l, int r)
{
	pushdown(k);
	
	if(t[k].l == l && t[k].r == r)
		return t[k].sum; 
	int mid = (t[k].l + t[k].r) >> 1;
	if(r <= mid) return query(ls, l, r);
	else if(l >= mid + 1) return query(rs, l, r);
	else return (query(ls, l, mid) + query(rs, mid + 1, r));
}

int n, m, root;
inline void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	buildTree(root, 1, n);
	for (int i = 1; i <= m; ++i)
	{
		char op;
		long long x, y, z;
		cin >> op;
		if(op == 'C')
		{
			cin >> x >> y >> z;
			add(root, x, y, z);
		}
		
		if(op == 'Q')
		{
			cin >> x >> y;
			cout << query(root, x, y) << endl;
		}
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	SegmentTree::solve();
}
```

## 线段树模板2

[luogu3373](https://www.luogu.org/problemnew/show/P3373)

### 代码
```cpp
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

namespace sgt2
{
const int maxn = 100005;    

struct Node
{
	int l, r, son[2];
	long long sum, add, mul;
};

Node t[maxn << 2];
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
	t[k].sum = t[ls].sum + t[rs].sum;
}

inline void pushdown(int k)
{
	if(t[k].mul != 1)
	{
		mut(t[ls].add, t[k].mul);
		mut(t[rs].add, t[k].mul);
		mut(t[ls].mul, t[k].mul);
		mut(t[rs].mul, t[k].mul);
		mut(t[ls].sum, t[k].mul);
		mut(t[rs].sum, t[k].mul);
		t[k].mul = 1;
	}
	
	if(t[k].add)
	{
		acc(t[ls].add, t[k].add);
		acc(t[rs].add, t[k].add);
		acc(t[rs].sum, t[k].add * (t[rs].r - t[rs].l + 1));
		acc(t[ls].sum, t[k].add * (t[ls].r - t[ls].l + 1));
		t[k].add = 0;
	}
}

inline void buildTree(int &k, int l, int r, int *x)
{
	k = ++cnt;
	t[k].l = l, t[k].r = r, t[k].mul = 1;

	if(l == r)
	{
	    t[k].sum = x[l];
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
    
	if(t[k].l == l && t[k].r == r)
	{
		acc(t[k].add, val);
		acc(t[k].sum, val * (r - l + 1));
		return;
	}

	int mid = (t[k].l + t[k].r) >> 1;
	if(r <= mid) add(ls, l, r, val);
	else if(l >= mid + 1) add(rs, l, r, val);
	else add(ls, l, mid, val), add(rs, mid + 1, r, val);

	pushup(k);
}

inline void mul(int k, int l, int r, long long val)
{
	if(t[k].l == l && t[k].r == r)
	{
		mut(t[k].add, val), mut(t[k].mul, val);
		mut(t[k].sum, val);
		return;
	}

	pushdown(k);

	int mid = (t[k].l + t[k].r) >> 1;
	if(r <= mid) mul(ls, l, r, val);
	else if(l >= mid + 1) mul(rs, l, r, val);
	else mul(ls, l, mid, val), mul(rs, mid + 1, r, val);	

	pushup(k);
}

inline long long query(int k, int l, int r)
{
	if(t[k].l == l && t[k].r == r)
		return t[k].sum;
    
    pushdown(k);
    
	int mid = (t[k].l + t[k].r) >> 1;
	if(r <= mid) return query(ls, l, r) % p;
	else if(l >= mid + 1) return query(rs, l, r) % p;
	else return (query(ls, l, mid) + query(rs, mid + 1, r)) % p;
}

int n, m, a[maxn], root;
int o, x, y, k;

inline void solve()
{
	using namespace IO;
	read(n); read(m); read(p);
    
    for (int i = 1; i <= n; ++i)
        read(a[i]);
        
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
```

## Siano

[BZOJ4293](https://www.lydsy.com/JudgeOnline/problem.php?id=4293)

我们的考题是这样的：
### Chika的烦恼
#### 题目描述
Chika 家经营着一家旅馆，她经常要帮家里的忙，有时候，她需要去清理长
满杂草的后院。具体地，后院里面的每棵草都有其生长速率（每天所能生长的高
度），在某些给定的日期，她需要把高度大于某个值b 的杂草割掉一截，使其高
度剩余b。（b 在每次给定的日期时不一定相同。）
她想请你帮她统计一下，每次她所割掉的草的总量是多少。
假设最开始每棵草的高度是零。
#### 输入格式
第一行为两个整数n, m，代表后院里草总共有n 棵，以及发生的事件的总
数m。
第二行包含n 个整数$a_1$, $a_2$,…, $a_n$, $a_i$ $(1 \leq i \leq n)$代表第$i$棵草的生长速度为每天$a_i$个单位。
接下来$m$行，第$i$行包含两个整数$d_i$, $b_i$,代表在第$d_i$天结束时，Chika 把
所有高度大于$b_i$的草的高度变成了$b_i$.（保证输入的$d_i$是递增的）
#### 输出格式
包含$m$行，每行一个整数，代表割掉的草的总量共有多少个单位。
#### 样例输入
```
4 4
1 2 4 3
1 1
2 2
3 0
4 4
```
#### 样例输出
```
6
6
18
0
```
#### 数据范围
$1 \leq n, m \leq 500000$
$1 \leq a[i] \leq 10^6$
$1 \leq d, b \leq 10^{12}$
#### qwq
第1天，草的高度分别为1,2,4,3，收割后变为1,1,1,1。
第2天，草的高度分别为2,3,5,4，收割后变为2,2,2,2。
第3天，草的高度分别为3,4,6,5，收割后变为0,0,0,0。
第4天，草的高度分别为1,2,4,3，收割后变为1,2,4,3。

---

### 说明
然而并没有AC...并不知道为啥WA???
第一次见到这道题是在电子科大的比赛上
当时并没有注意到这道题是线段树（？）
然而这道题有个性质
对最开始的生长数组排序后，可以用区间维护
自己yy一下，或者说手推一下能够发现。
就按题目中的数据来说吧

### 代码
```cpp
// by kririae
// status: WA???
// BZOJ4293
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
```

## SCOI2010 序列操作

仍然未AC...

### 代码
```cpp
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
	int l1, r1, m1, l0, r0, m0, sum;
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
	t[k].sum = t[ls].sum + t[rs].sum;
	merge(t[k], t[ls], t[rs]);
}

inline void pushdown(int k)
{
	if (t[k].s == 0)
	{
		t[ls].sum = t[rs].sum = 0;
		t[ls].rev = t[rs].rev = 0;
		t[ls].s = t[rs].s = t[k].s;
		t[ls].sum = 0;

		t[ls].l0 = t[ls].r0 = t[ls].m0 = len(t[ls]);
		t[rs].l0 = t[rs].r0 = t[rs].m0 = len(t[rs]),

		t[ls].l1 = t[ls].r1 = t[ls].m1 = t[rs].l1 = t[rs].r1 = t[rs].m1 = 0;
		t[k].s = -1;
	}

	if (t[k].s == 1)
	{
		t[ls].sum = len(t[ls]), t[rs].sum = len(t[rs]);
		t[ls].rev = t[rs].rev = 0;
		t[ls].s = t[rs].s = t[k].s;

		t[ls].l1 = t[ls].r1 = t[ls].m1 = len(t[ls]);
		t[rs].l1 = t[rs].r1 = t[rs].m1 = len(t[rs]),

		t[ls].l0 = t[ls].r0 = t[ls].m0 = t[rs].l0 = t[rs].r0 = t[rs].m0 = 0;
		t[k].s = -1;
	}

	if (t[k].rev)
	{
		t[ls].rev ^= 1, t[rs].rev ^= 1;
		t[ls].sum = len(t[ls]) - t[ls].sum, t[rs].sum = len(t[rs]) - t[rs].sum;

		swap(t[ls].l1, t[ls].l0), swap(t[ls].r1, t[ls].r0), swap(t[ls].m1, t[ls].m0);
		swap(t[rs].l1, t[rs].l0), swap(t[rs].r1, t[rs].r0), swap(t[rs].m1, t[rs].m0);
		t[k].rev = 0;
	}
}

inline void buildTree(int &k, int l, int r, int *x)
{
	k = ++cnt;
	t[k].l = l, t[k].r = r;

	if (l == r)
	{
		t[k].l1 = t[k].r1 = t[k].m1 = t[k].sum = x[l];
		t[k].l0 = t[k].r0 = t[k].m0 = (x[l] ^ 1), t[k].rev = 0;
		return;
	}

	int mid = (l + r) >> 1;
	buildTree(ls, l, mid, x);
	buildTree(rs, mid + 1, r, x);
	
	pushup(k);
}

inline void modify0(int k, int l, int r)
{
	if (t[k].l == l && t[k].r == r)
	{
		t[k].rev = 0, t[k].s = 0, t[k].sum = 0;
		t[k].l0 = t[k].r0 = t[k].m0 = len(t[k]);
		t[k].l1 = t[k].r1 = t[k].m1 = 0;
		return;
	}

	pushdown(k);

	int mid = (t[k].l + t[k].r) >> 1;
	if (r <= mid) modify0(ls, l, r);
	else if (l > mid) modify0(rs, l, r);
	else modify0(ls, l, mid), modify0(rs, mid + 1, r);

	pushup(k);
}

inline void modify1(int k, int l, int r)
{
	if (t[k].l == l && t[k].r == r)
	{
		t[k].rev = 0, t[k].s = 1, t[k].sum = len(t[k]);
		t[k].l0 = t[k].r0 = t[k].m0 = 0;
		t[k].l1 = t[k].r1 = t[k].m1 = len(t[k]);
		return;
	}

	pushdown(k);

	int mid = (t[k].l + t[k].r) >> 1;
	if (r <= mid) modify1(ls, l, r);
	else if (l > mid) modify1(rs, l, r);
	else modify1(ls, l, mid), modify1(rs, mid + 1, r);

	pushup(k);
}

inline void rev(int k, int l, int r)
{
	if (t[k].l == l && t[k].r == r)
	{
		t[k].rev ^= 1, t[k].sum = len(t[k]) - t[k].sum;
		swap(t[k].l1, t[ls].l0), swap(t[k].r1, t[k].r0), swap(t[k].m1, t[k].m0);
		return;
	}

	pushdown(k);

	int mid = (t[k].l + t[k].r) >> 1;
	if (r <= mid) rev(ls, l, r);
	else if (l > mid) rev(rs, l, r);
	else rev(ls, l, mid), rev(rs, mid + 1, r);

	pushup(k);
}

inline int sum(int k, int l, int r)
{
	if (t[k].l == l && t[k].r == r)
		return t[k].sum;

	pushdown(k);

	int mid = (t[k].l + t[k].r) >> 1;
	if (r <= mid) return sum(ls, l, r);
	else if (l > mid) return sum(rs, l, r);
	else return sum(ls, l, mid) + sum(rs, mid + 1, r);
}

inline Node con(int k, int l, int r)
{
	if (t[k].l == l && t[k].r == r)
		return t[k];

	pushdown(k); // 查询操作有很多骚操作...
	
	Node p1, p2, ret;
	int mid = (t[k].l + t[k].r) >> 1; 
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
		// read(a[i]);
		cin >> a[i];

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
```

# 主席树专题
下面是一系列主席树的题目，由于主席树本身的特殊性...很多题目会掺杂奇奇怪怪的其他数据结构...
## 主席树
主席树配合权值线段树是可以出奇迹的。

## [LUOGU3834] 主席树模板
```cpp
// by kririae
#define ls t[k].son[0]
#define rs t[k].son[1]
#define pls t[pre].son[0]
#define prs t[pre].son[1]
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

namespace PT
{
const int maxn = 200005;

struct Node
{
	int son[2];
	long long sum;
};

Node t[maxn * 20];
int root[maxn], cnt;
int n, m, l, r, k, a[maxn], b[maxn];

inline int build(int l, int r)
{
	int k = ++cnt;
	int mid = (l + r) >> 1;
	if(l < r)
		ls = build(l, mid),
		rs = build(mid + 1, r);
	return k;
}

inline int update(int pre, int l, int r, int val)
{
	// pre 左边的树 val 更新val位置（val+1，即val重新出现一次
	int k = ++cnt;
	ls = pls, rs = prs, t[k].sum = t[pre].sum + 1;
	// 复制原来节点的所有信息，并且更新新节点的信息。
	int mid = (l + r) >> 1;
	if(l < r)
	{
		if(val <= mid) ls = update(pls, l, mid, val);
		else rs = update(prs, mid + 1, r, val);
	}
	return k;
}

inline int query(int u, int v, int l, int r, int val)
{
	// u表示在第一棵树里的位置，v表示在第二棵树里的位置
	if(l >= r) return l;
	int k = t[t[v].son[0]].sum - t[t[u].son[0]].sum;
	// 区间[u, v]之间大于l小于r的个数
	int mid = (l + r) >> 1;
	if(k >= val) return query(t[u].son[0], t[v].son[0], l, mid, val);
	else return query(t[u].son[1], t[v].son[1], mid + 1, r, val - k);
}

inline void solve()
{
	using namespace IO;
	read(n), read(m); 
	
	for (int i = 1; i <= n; ++i)
		read(a[i]), b[i] = a[i];

	sort(b + 1, b + 1 + n);
	int sz = unique(b + 1, b + 1 + n) - b - 1;
	root[0] = build(1, sz);

	for (int i = 1; i <= n; ++i)
		root[i] = update(root[i - 1], 1, sz, lower_bound(b + 1, b + 1 + sz, a[i]) - b);

	while(m--)
	{
		read(l), read(r), read(k);
		cout << b[query(root[l - 1], root[r], 1, sz, k)] << endl;
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	PT::solve();
	return 0;
}
```

## [BZOJ2588] Count on a tree
### 代码
```cpp
// by kririae
#define ls t[k].son[0]
#define rs t[k].son[1]
#define pls t[pre].son[0]
#define prs t[pre].son[1]
#define mid ((l + r) >> 1)
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

namespace Count_on_a_tree
{
const int maxn = 200005;

struct Node
{
	int son[2];
	long long sum;
};

Node t[maxn * 20];
int root[maxn], cnt;
int n, m, x, y, sz, lastans, u, v, k;
int a[maxn], b[maxn], dep[maxn], f[maxn][20];
vector<int> edges[maxn];
bitset<maxn> vis;

inline void addedge(int from, int to)
{
	edges[from].push_back(to);
	edges[to].push_back(from);
}

inline int lca(int x, int y)
{
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = log(n) / log(2) + 1; i >= 0; --i)
		if(dep[f[y][i]] >= dep[x]) y = f[y][i];
	if(x == y) return x;
	for (int i = log(n) / log(2) + 1; i >= 0; --i)
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

inline int build(int l, int r)
{
	int k = ++cnt;
	if(l < r)
		ls = build(l, mid),
		rs = build(mid + 1, r);
	return k;
}

inline int update(int pre, int l, int r, int val)
{
	int k = ++cnt;
	ls = pls, rs = prs, t[k].sum = t[pre].sum + 1;
	if(l < r)
	{
		if(val <= mid) ls = update(pls, l, mid, val);
		else rs = update(prs, mid + 1, r, val);
	}
	return k;
}

inline void dfs(int k, int fa)
{
	f[k][0] = fa, dep[k] = dep[f[k][0]] + 1, vis[k] = 1, root[k] = update(root[f[k][0]], 1, sz, lower_bound(b + 1, b + 1 + sz, a[k]) - b);
	for (int i = 0; i < edges[k].size(); ++i) 
		if(!vis[edges[k][i]]) 
			dfs(edges[k][i], k);
}

inline int query(int t1, int t2, int t3, int t4, int l, int r, int val)
{
	cout << l << " " << r << endl;
	if(l >= r) return l;
	int k = t[t[t1].son[0]].sum + t[t[t2].son[0]].sum - t[t[t3].son[0]].sum - t[t[t4].son[0]].sum;
	if(k >= val) return query(t[t1].son[0], t[t2].son[0], t[t3].son[0], t[t4].son[0], l, mid, val);
	else return query(t[t1].son[1], t[t2].son[1], t[t3].son[1], t[t4].son[1], mid + 1, r, val - k);
}

inline void solve()
{
	freopen("1.in", "r", stdin); 
	using namespace IO;
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		read(a[i]), b[i] = a[i];

	sort(b + 1, b + 1 + n);
	sz = unique(b + 1, b + 1 + n) - b - 1;
	root[0] = build(1, sz);

	for (int i = 1; i < n; ++i)
		read(x), read(y), addedge(x, y);

	dfs(1, 0); 
	for (int i = 0; i <= n; ++i)
		for (int j = 1; j <= log(n) / log(2) + 1; ++j)
			f[i][j] = f[f[i][j - 1]][j - 1];
	
	lastans = 0;
	for (int i = 1; i <= m; ++i)
	{
		read(u), read(v), read(k);
		u ^= lastans; 
		int ff = lca(u, v);
		lastans = b[query(root[u], root[v], root[ff], root[f[ff][0]], 1, sz, k)];
		cout << lastans << endl;
	}		
}
}

int main()
{
	Count_on_a_tree::solve();
	return 0;
}
```
# 分块
## [BZOJ2002] 弹飞绵羊
### 代码
自己的那一份跑的贼慢，参考黄学长的发现有一段递推orz
```cpp
// by kririae
#define ll long long
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

namespace TFMY
{
const int maxn = 200005;

int n, m, block, all, op, x, y, ans = 0;
int k[maxn], belong[maxn], l[1005], r[1005], a[maxn], b[maxn];
// a -> 跳出当前块所需要的步数，b表示跳出后跳到哪个位置

inline void solve()
{
	freopen("tfmy.txt", "r", stdin);
	using namespace IO;
	read(n), block = sqrt(n);
	all = n % block ? n / block : n / block + 1;
	for (int i = 1; i <= n; ++i)
		read(k[i]);

	for (int i = 1; i <= all; ++i)
		l[i] = r[i - 1] + 1, r[i] = l[i] + block - 1;
	r[all] = n;

	for (int i = 1; i <= all; ++i)
		for (int j = l[i]; j <= r[i]; ++j)
			belong[j] = i;
	
	// 黄学长的递推qwq（自己写的n根n的...
	for (int i = n; i >= 1; --i) 
		if(i + k[i] <= n) 
		{
			if(belong[i] == belong[i + k[i]]) a[i] = a[i + k[i]] + 1, b[i] = b[i + k[i]];
			else a[i] = 1, b[i] = i + k[i];
		} else a[i] = 1;
		
	read(m);
	for (int qaq = 1; qaq <= m; ++qaq)
	{
		read(op);
		if(op == 1)
		{
			read(x); ans = 0; ++x;
			for (; b[x]; ans += a[x], x = b[x]);
				ans += a[x];
			cout << ans << endl;
		}

		if(op == 2)
		{
			read(x), read(y); ++x, k[x] = y;
			for (int i = r[belong[x]]; i >= l[belong[x]]; --i)
				if(belong[i] == belong[i + k[i]]) a[i] = a[i + k[i]] + 1, b[i] = b[i + k[i]];
				else a[i] = 1, b[i] = i + k[i];
		}
	}
}
}

int main()
{
	TFMY::solve();
	return 0;
}
```

## 莫队
我以前说过，莫队真短（大雾）
### [BZOJ2038x]小Z的袜子
#### 代码
```cpp
// by kririae
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
long long a[maxn], cnt[maxn];

struct Req
{
	long long l, r;
	int id;
	Req() {}	
	bool operator < (const Req &a) const
	{ 
		return (l / sz) == (a.l / sz) ? r < a.r : l / sz < a.l / sz; 
	}
};

Req s[maxn], res[maxn];

template<typename T>
inline T C(T val)
{
	return val * (val - 1);
}

inline void update(int val, int k)
{
	tot -= C(cnt[val]);
	cnt[val] += k;
	tot += C(cnt[val]);
}

inline void solve()
{
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	for (int i = 1; i <= m; ++i)
		read(s[i].l), read(s[i].r), s[i].id = i;
		
	sz = sqrt(n) + 1;
	sort(s + 1, s + 1 + m);
	
	for (int i = 1; i <= m; ++i)
	{
		Req &cr = s[i];
		
		if(cr.l == cr.r) 
		{ 
			res[cr.id].l = 0, res[cr.id].r = 1;
			continue; 
		}
		
		while(r > cr.r) update(a[r--], -1);
		while(r < cr.r) update(a[++r], 1);
		while(l < cr.l) update(a[l++], -1);
		while(l > cr.l) update(a[--l], 1);
		
		long long rl, rr;
		rl = tot;
		rr = (long long)(cr.r - cr.l + 1) * (cr.r - cr.l);
		int g = __gcd(rl, rr);
		rl /= g, rr /= g;
		res[cr.id].l = rl, res[cr.id].r = rr;
	}
	
	for (int i = 1; i <= m; ++i)
		cout << res[i].l << "/" << res[i].r << endl;
}
}

int main()
{
	LittleZ::solve();
	return 0;
}
```
### [BZOJ3339] RMQ
莫队真爽.jpg
#### 代码
```cpp
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
```

### [BZOJ1878] HH的项链
#### 代码
```cpp
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

```

# 树套树
## [ZJOI2013] K大数查询
### 代码
```cpp
// by kririae
#define ls t[k].son[0]
#define rs t[k].son[1]
#define mid ((l + r) >> 1)
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

namespace kth
{
const int maxn = 50005;

int n, m, tot;
int op[maxn], a[maxn], b[maxn], c[maxn];
int s[maxn], sz;

struct Node
{
	int son[2], add;
	long long sum;

	Node() {}
};

int cnt, root[maxn << 2];
Node t[maxn * 400];

inline void pushup(int k)
{
	t[k].sum = t[ls].sum + t[rs].sum;
}

inline void pushdown(int &k, int l, int r)
{
	if(!t[k].sum) return;
	if(!ls) ls = ++cnt;
	if(!rs) rs = ++cnt;
	t[ls].add += t[k].add, t[rs].add += t[k].add;
	t[ls].sum += (r - mid) * t[k].sum, t[rs].sum += (mid - l + 1) * t[k].sum;
	t[k].add = 0;
}

inline void update2(int &k, int l, int r, int a, int b)
{
	if(!k) k = ++cnt;
	pushdown(k, l, r);

	if(l == a && r == b)
	{
		t[k].sum += (r - l + 1), ++t[k].add;
		return;
	}

	if(b <= mid) update2(ls, l, mid, a, b);
	else if(a > mid) update2(rs, mid + 1, r, a, b);
	else update2(ls, l, mid, a, mid), update2(rs, mid + 1, r, mid + 1, b);
	pushup(k);
}

inline void update1(int a, int b, int c)
{
	int l = 1, r = sz, k = 1;
	while(l < r)
	{
		update2(root[k], 1, n, a, b);
		if(c <= mid) k <<= 1, r = mid;
		else k = (k << 1) | 1, l = mid + 1;
	}
	// if l == r
	update2(root[k], 1, n, a, b);
}

inline int query2(int k, int l, int r, int a, int b)
{
	if(!k) return 0;
	pushdown(k, l, r);
	if(l == a && r == b)
		return t[k].sum;
	if(b <= mid) return query2(ls, l, mid, a, b);
	else if(a > mid) return query2(rs, mid + 1, r, a, b);
	else return query2(ls, l, mid, a, mid) + query2(rs, mid + 1, r, mid + 1, b);
}

inline int query1(int a, int b, int c)
{
	int l = 1, r = sz, k = 1;
	while(l < r)
	{
		int k = query2(root[k << 1], 1, n, a, b);
		if(c <= k) k <<= 1, r = mid;
		else k = (k << 1) | 1, l = mid + 1, c -= k;
	}
	return l;
}

inline void solve()
{
	using namespace IO;
	read(n), read(m);
	for (int i = 1; i <= m; ++i)
	{
		read(op[i]), read(a[i]), read(b[i]), read(c[i]);
		if(op[i] == 1) s[++tot] = c[i];
	}

	sort(s + 1, s + 1 + tot);
	sz = unique(s + 1, s + 1 + tot) - s - 1; // 离散化所有的c

	for (int i = 1; i <= m; ++i)
	{
		if(op[i] == 1) update1(a[i], b[i], sz - (lower_bound(s + 1, s + 1 + sz, c[i]) - s) + 1);
		if(op[i] == 2) cout << s[sz - query1(a[i], b[i], lower_bound(s + 1, s + 1 + sz, c[i]) - s) + 1] << endl;
	}
}
}

int main()
{
	kth::solve();
	return 0;
}
```