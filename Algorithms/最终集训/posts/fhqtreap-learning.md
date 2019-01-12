title: 「学习笔记」fhqtreap学习
author: kririae
tags:
  - 数据结构
categories:
  - oi
date: 2018-03-10 00:48:00
---
# 非旋treap

fhqtreap学习

<!--more-->

## 左偏树

首先给一份[资料](https://wenku.baidu.com/view/029c886d1eb91a37f1115ce5.html)

按照lr说的，fhqtreap=可并堆+tree，决定学一学（其实学过然后忘了）   
左偏树的节点定义为   
`son[2] dis key`   
`son[2]`就不解释了；   
做以下定义，节点i为外节点，当且仅当i的左右子节点不存在。dis定义为当前节点到自己的子节点树上的最近的外节点经过的边数。空节点的`dis =  -1`，当前节点为外节点时`dis = 0`   

> 一个左偏树满足以下性质  
- 子节点的key小于当前节点的key
- 左子节点的dis大于右子节点的dis。   
- 当前节点的距离等于右子节点的距离+1 -> 如果y节点的距离是0，那么它不存在右节点。在代码实现中，空节点的dis是-1.   
- 一棵左偏树的距离最多$\lfloor\mathrm{log}(n + 1)\rfloor - 1$

合并过程伪代码如下

```qwq
func merge(a, b)
{
	if a == null -> return b
	if b == null -> return a
	if b.key < a.key -> swap(a, b)
	a.right = merge(a.right, b)
	if a.right.dis > a.left.dis
		-> swap(a.left, a.right)
	if a.right == null -> a.dis = 0
	else -> a.dis = a.right.dis + 1
	return a
}
```
这里稍微多解释一下
对于两棵左偏树，要将二者合并
首先在函数中定义边界条件：当一个节点是外节点时，返回有节点的一边。当我们合并到一棵树a和一棵树b的时候，首先比较它们俩的值，如果a上的根节点的值大于等于b上的，我们交换两颗树，维护堆性质。然后继续对交换后的“a”(可能是之前的b)的子树进行操作。递归到底，然后开始回溯。   
接下来的部分是维护左偏树的性质。之前提到过，左偏树的性质是“当前节点的距离=右节点的距离+1当且仅当当前节点不是外节点。”，那么如果出现了左子节点的dist>右子节点的dist，交换左右子树。   
这样就能够维护好一棵左偏树。     
总结一下，在向下递归的时候用swap子树的方式维护堆的性质，因为dist需要递归求解，所以在回溯的时候求dist并且维护左偏树特有的性质。   
wdm理解了半天。   
如果看这段话不能理解或者说懒得看那就不如看资料中的图片或者说手造左偏树然后用一个点的插入模拟一下。   

## fhqtreap
思路很好想，比传说中的难一点   
lr的代码，神...   
我看到过的模板中最好看+最短的一个www  
%%%%%%%%%   
```cpp
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
    int size, val, key;
    int son[2];
    node() {}
};

node t[maxn];
int cnt, root;

inline void pushup(int k)
{
    t[k].size = t[ls].size + t[rs].size + 1;
}

inline void make_heap(int& k, int val)
{
    k = ++cnt, t[k].val = val, t[k].size = 1, t[k].key = rand();
}

inline void merge(int& k, int a, int b)
{
    if (!a || !b) { k = a + b; return; } // 取有值的一个
    if (t[a].key < t[b].key) k = a, merge(rs, rs, b);
    else k = b, merge(ls, a, ls);
    pushup(k);
}

inline void split(int k, int& a, int& b, int key)
{
    if (!k) { a = b = 0; return; }
    if (t[k].val <= key) a = k, split(rs, rs, b, key);
    else b = k, split(ls, a, ls, key);
    pushup(k);
}

inline void insert(int val)
{
    int k; make_heap(k, val);
    // 把新加入的点放到索引k上
    int a, b; a = b = 0;
    split(root, a, b, val); // 以val分割到左子树和右子树
    // 以val split到a, b上
    merge(a, a, k); // 把小的一边和它合并
    merge(root, a, b); // 把a, b合并到root上
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
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    using namespace fhqtreap;
    srand(19260817);
    return 0;
}
```

lr的区间ver
```cpp
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
```

提到过，按照lr说的，非旋treap利用了类似左偏树的思想，在合并的时候有一个条件，b的每一个节点严格大于a的每一个节点。   
其实我感觉这个也不好理解orz
