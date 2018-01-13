#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

int cnt = 0;
int ini[maxn];

struct Message {
	int sum;
};
struct SegmentTree {
	int l, r;
	Message mess;
	int lson, rson;
} node[maxn * 2];

inline void pushup(int k)
{
	node[k].mess.sum = node[ node[k].lson ].mess.sum + node[ node[k].rson ].mess.sum;
}

inline void buildTree(int &k, int l, int r)
{
	k = ++cnt;
	node[k].l = l, node[k].r = r;

	if(l == r) {
		node[k].mess.sum = ini[l];
	} else {
		int mid = (l + r) / 2;
		buildTree(node[k].lson, l, mid);
		buildTree(node[k].rson, mid + 1, r);
		pushup(k);
	}
}

inline void one_point_modify(int k, int pos, int val)
{
	if(node[k].lson == node[k].lson) {
		node[k].mess.sum = val;
		ini[pos] = val;
	} else {
		int mid = (node[k].lson + node[k].rson) / 2;

		if(pos <= mid)
			one_point_modify(node[k].lson, pos, val);
		else
			one_point_modify(node[k].rson, pos, val);

		pushup(k);
	}
}

inline int range_query(int k, int ql, int qr)
{
	if(node[k].lson == ql && node[k].rson == qr) {
		return node[k].mess.sum;
	}

	int mid = (node[k].lson + node[k].rson) / 2;

	if(qr <= mid) {
		return range_query(node[k].lson, ql, qr);
	} else {
		if(ql >= mid + 1) {
			return range_query(node[k].rson, ql, qr);
		} else {
			return range_query(node[k].lson, ql, mid) + range_query(node[k].rson, mid + 1, qr);
		}
	}
}
int n, m, root;
int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> ini[i];
	}

	cin >> m;

	for (int i = 1; i <= m; ++i) {
		int op, l, r;
		cin >> op >> l >> r;

		if(op == 1) {
			one_point_modify(root, l, r);
		} else {
			cout << range_query(root, l, r) << endl;
		}
	}
}