title: 「学习笔记」splay
author: kririae
tags: []
categories: []
date: 2017-12-27 04:54:00
---
# splay
年末学的，这里粘一发代码就够了...

---

<!--more-->
```cpp
#include <bits/stdc++.h>

using namespace std;

namespace splay
{
const int maxn = 100005;

class node
{
public:
	int val, size, times;
	int fa, son[2];
	node() {}
	node(int v): val(v) {}
};

node t[maxn];
int root = 0, cnt = 0;

std::ostream& operator<<(std::ostream& os,
						 const node& p)
{
	os << "node->son: [" << p.son[0] << ", " <<
	   p.son[1] << "], node->val: " << p.val <<
	   ", node->size: ";
	os << p.size << ", node->fa.val: " << t[p.fa].val
	   << endl;
	return os;
}

inline void print(int& k)
{
	if (t[k].son[0] != 0) print(t[k].son[0]);

	cout << t[k];

	if (t[k].son[1] != 0) print(t[k].son[1]);
}

inline void clear(int& k)
{
	t[k].times = t[k].fa = t[k].val = t[k].size =
										  t[k].son[0] =
												  t[k].son[1] = 0;
}

inline int get(int& k)
{
	return t[t[k].fa].son[1] == k;
}

inline int find(int& k, int val)
{
	return t[k].val == val ?
		   k : (t[k].val < val ?
				find(t[k].son[0], val) :
				find(t[k].son[1], val));
}

inline void update(int k)
{
	t[k].size = t[k].times;
	t[k].size += (t[t[k].son[0]].size + t[t[k].son[1]].size);
}

inline void rotate(int& k)
{
	int f = t[k].fa, ff = t[f].fa, side = get(k);
	t[f].son[side] = t[k].son[side ^ 1];
	t[t[f].son[side]].fa = f;
	t[f].fa = k, t[k].son[side ^ 1] = f;
	t[k].fa = ff;

	if (ff) t[ff].son[t[ff].son[1] == f] = k;

	update(f), update(k);
}

inline void splay(int& k)
{
	// 在树中找到x并且翻转到根节点
	for (int fa; fa = t[k].fa;
		 rotate(k)) if (t[fa].fa)
			rotate(get(k) == get(fa) ? fa : k);

	root = k;
}

inline void insert(int val)
{
	if (root == 0)
	{
		t[++cnt].son[0] = t[cnt].son[1] = 0;
		t[cnt].times = 1, t[cnt].val = val, t[cnt].size = 1, root = cnt;
		return;
	}

	int curr = root, fa = 0;

	for (;;)
	{
		if (t[curr].val == val)
		{
		    ++t[curr].times;
			update(curr), update(fa);
			splay(curr);
			break;
		}

		fa = curr;
		curr = t[curr].son[t[curr].val < val];

		if (curr == 0)
		{
			t[++cnt].son[0] = t[cnt].son[1] = 0,
											  t[cnt].size = 1;
			t[cnt].val = val; t[cnt].times = 1;
			t[cnt].fa = fa, t[fa].son[t[fa].val < val] = cnt;
			update(fa); splay(cnt);
			break;
		}
	}
}
}

inline int read()
    {
        char c = getchar();
        int ret = 0, f = 1;
        for (; !isdigit(c); f = c == '-' ? -1 : 1, c = getchar());
        for (; isdigit(c); ret = ret * 10 + c - '0', c = getchar());
        return ret * f;
    }
    
int main()
{
	using namespace splay;
}
```
恩？？？为啥没转？？？