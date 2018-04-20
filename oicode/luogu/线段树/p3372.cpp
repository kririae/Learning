// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;

const int maxn = 500005;

struct node
{
	long long val;
	long long add;
	int l, r;
	int son[2];
};

int cnt = 0;
node t[maxn << 2];
int ini[maxn];

inline void pushup(int k)
{
	t[k].val = t[ls].val + t[t[k].son[1]].val;
}

inline void pushdown(int k)
{
	if (t[k].add == 0)
		return;
	t[ls].add += t[k].add;
	t[rs].add += t[k].add;
	t[ls].val += (t[ls].r - t[ls].l + 1) * t[k].add;
	t[t[k].son[1]].val += (t[t[k].son[1]].r - t[t[k].son[1]].l + 1) * t[k].add;
	t[k].add = 0;
}

inline void buildtree(int &k, int l, int r)
{
	k = ++cnt;
	t[k].l = l, t[k].r = r;
	if (l == r)
		t[k].val = ini[l];
	else
	{
		int mid = (l + r) / 2;
		buildtree(ls, l, mid);
		buildtree(t[k].son[1], mid + 1, r);
		pushup(k);
	}
}

inline void range_add(int k, int ql, int qr, int val)
{
	if (t[k].l == ql && t[k].r == qr)
	{
		t[k].add += val;
		t[k].val += val * (qr - ql + 1);
	}
	else
	{
		pushdown(k);
		int mid = (t[k].l + t[k].r) / 2;
		if (qr <= mid)
			range_add(ls, ql, qr, val);
		else
		{
			if (ql >= mid + 1)
				range_add(t[k].son[1], ql, qr, val);
			else
			{
				range_add(ls, ql, mid, val);
				range_add(t[k].son[1], mid + 1, qr, val);
			}
		}
		pushup(k);
	}
	// pushup(k);
}

inline long long range_query(int k, int ql, int qr)
{
	if (t[k].l > qr || t[k].r < ql)
		return 0;
	pushdown(k);
	if (t[k].l >= ql && t[k].r <= qr)
	{
		return t[k].val;
	}

	int mid = (t[k].l + t[k].r) / 2;
	if (qr <= mid)
		return range_query(ls, ql, qr);
	else
	{
		if (ql >= mid + 1)
			return range_query(t[k].son[1], ql, qr);
		else
		{
			return range_query(ls, ql, mid) +
				   range_query(t[k].son[1], mid + 1, qr);
		}
	}
}

int n, m;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> ini[i];
	}
	int root = 0;
	buildtree(root, 1, n);
	int opt;
	int a, b, c;
	for (int i = 0; i < m; ++i)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> a >> b >> c;
			range_add(root, a, b, c);
		}
		if (opt == 2)
		{
			cin >> a >> b;
			cout << range_query(root, a, b) << endl;
		}
	}
}
/*
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> ini[i];
    }
    int root = 0;
    buildtree(root, 1, n);
    cout << range_query(root, 1, 5) << endl;
    range_add(root, 1, 5, 1);
    cout << range_query(root, 1, 5) << endl;
    range_add(root, 1, 2, 1);
    cout << range_query(root, 1, 5) << endl;
    range_add(root, 2, 3, 1);
    cout << range_query(root, 1, 5) << endl;
}
*/
/*
5 5
1 2 3 4 5
*/