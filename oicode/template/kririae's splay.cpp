#define ls t[k].son[0]
#define rs t[k].son[1]
#include <bits/stdc++.h>

using namespace std;

namespace splay
{
const int maxn = 100005;

struct Node
{
	int val, size, fa, son[2];
	Node() {}
};

int cnt, root;
Node t[maxn];

inline void pri(int k)
{
	if(ls) pri(ls);
	printf("%d %d %d %d\n", t[k].val, t[ls].val, t[rs].val, t[k].fa);
	if(rs) pri(rs);
}

inline void pushup(int k)
{
	t[k].size = t[ls].size + t[rs].size + 1;
}

inline void pushdown(int k)
{
	return;
}

inline int get(int k)
{
	return t[t[k].fa].son[1] == k;
}

inline void modify_son(int k, int val, int side)
{
	t[k].son[side] = val, t[val].fa = k;
}

inline void rotate(int k)
{
	if(k == root || k == 0) return;
	int side = get(k), fa = t[k].fa, gr = t[fa].fa;
	if(fa == root) root = k;
	modify_son(gr, k, get(fa));  
	modify_son(fa, t[k].son[side ^ 1], side);
	modify_son(k, fa, side ^ 1);
	pushup(fa), pushup(k), pushup(gr);
}

inline void splay(int k, int val)
{
	while(t[k].fa != val && t[k].fa)
		rotate(k); 
}

inline void insert(int &k, int val)
{
	if(!cnt) { k = ++cnt, root = k, t[cnt].val = val, t[cnt].size = 1; return; }
	if(!k) { k = ++cnt, t[cnt].val = val, t[cnt].size = 1, splay(cnt, root); return; }
	if(t[k].val > val) insert(ls, val), t[ls].fa = k;
	else insert(rs, val), t[rs].fa = k;
	pushup(k);
}

inline void solve()
{

}	
}

int main()
{
	srand(time(NULL));
	using namespace splay;
	for (int i = 1; i <= 10; ++i)
		insert(root, i);	
	
	pri(root);
}
