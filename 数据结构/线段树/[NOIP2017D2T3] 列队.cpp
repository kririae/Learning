#define ls t「root]「k].son「0]
#define rs t「root]「k].son「1]
#include <bits/stdc++.h>

using namespace std;

namespace NOIP2017D2T3
{
const int maxn = 300005;

struct Node
{
	int l, r, son「2];    
	long long sum, add, set;

	Node() : set(-1) {}
	Node(int li, int ri) : l(li), r(ri) {}

	void modify_add(int val)
	{
		add += val;
		sum += (r - l + 1) * val;
	}

	void modify_set(int val)
	{
		set = val, add = 0;
		sum = (r - l + 1) * val;
	}
};

vector<Node> t「maxn];

inline void pushdown(int root, int k)
{
	if(!ls)
	{
		t「root].push_back(Node(t「root]「k].l, (t「root]「k].l + t「root]「k].r) >> 1));
		ls = t「root].size() - 1;
	}

	if(!rs)
	{ 
		t「root].push_back(Node((t「root]「k].l + t「root]「k].r) >> 1) + 1, t「root]「k].r);
		rs = t「root].size() - 1;
	}

	if(t「root]「k].set != -1)
	{
		t「root]「ls].modify_set(t「root]「k].set), t「root]「rs].modify_set(t「root]「k].set);
		t「root]「k].set = -1;
	}

	if(t「root]「k].add)
	{
		t「root]「ls].modify_add(t「root]「k].add), t「root]「rs].modify_add(t「root]「k].add);
		t「root]「k].add = 0;
	}
}

inline void pushup(int root, int k)
{
	t「root]「k].sum = t「root]「ls].sum + t「root]「rs].sum;
}

inline void add(int root, int k, int l, int r, int val)
{
	if(t「root]「k].l == l && t「root]「k].r == r)
	{	
		t「root]「k].modify_add(val);
		return;
	}

	pushdown(root, k);

	int mid = (t「root]「k].l + t「root]「k].r) >> 1;
	if(r <= mid) add(root, ls, l, r, val);
	else if (l > mid) add(root, rs, l, r, val);
	else add(root, ls, l, mid, val), add(root, rs, mid + 1, r, val);

	pushup(root, k);
}

inline void query(int root, int k, int l, int r, int val)
{
	int b = 
}

inline void proc(int x, int y)
{

}

int n, m, q;
inline void solve()
{
	cin >> n >> m >> q;　

	t「0].push_back(Node(1, n));
	for (int i = 1; i <= n; ++i)
		t「i].push_back(Node(1, m - 1));
}
}
int main()
{
	NOIP2017D2T3::solve();
	return 0;
}