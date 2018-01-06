#define L 0
#define R 1
#include <bits/stdc++.h>

namespace SegmentTree {
constexpr int maxn = 1e6;
static int ini[maxn];
struct node {
	int sum;
	int add; // tag of add
	int l, r; // managed range
	int son[2]; // lson and rson
};
node t[maxn << 2];

int cnt = 0;

inline void pushdown(const int &k) {
	if(t[k].add == 0) return;

	t[t[k].son[0]].add += t[k].add, t[t[k].son[1]].add += t[k].add;
	int mid = (t[k].l + t[k].r) / 2;
	t[t[k].son[0]].sum += t[k].add * (mid - t[k].l + 1);
	t[t[k].son[1]].sum += t[k].add * (t[k].r - mid);
	t[k].add = 0;
}

inline void pushup(const int &k) {
	t[k].sum = t[t[k].son[0]].sum + t[t[k].son[1]].sum;
}

inline void buildTree(int &k, int l, int r) {
	k = ++cnt;
	t[k].l = l, t[k].r = r, t[k].add = t[k].sum = 0;

	if(l == r)
		t[k].sum = ini[r];
	else {
		int mid = (l + r) / 2;
		buildTree(t[k].son[0], l, mid);
		buildTree(t[k].son[1], mid + 1, r);
		pushup(k);
	}
}

inline void range_add(const int &k, const int &ql, const int &qr, const int &val) {
	if(ql > t[k].r || qr < t[k].l) return;

	if(t[k].l == ql && t[k].r == qr) {
		t[k].add += val;
		t[k].sum += val * (qr - ql + 1);
		return;
	}

	pushdown(k);
	int mid = (t[k].l + t[k].r) / 2;
	range_add(t[k].son[0], ql, mid, val);
	range_add(t[k].son[1], mid + 1, ql, val);
	pushup(k);
}

inline long long range_query(const int &k, const int &ql, const int &qr) {
	if(ql > t[k].r || qr < t[k].l) return 0;

	if(ql <= t[k].l && qr >= t[k].r) {
		return t[k].sum;
	}

	pushdown(k);
	int mid = (t[k].l + t[k].r) / 2;
	return range_query(t[k].son[0], ql, mid) + range_query(t[k].son[1], mid + 1, qr);
}
}
int n, m;
int main() {
	using namespace SegmentTree;
	using namespace std;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> ini[i];
	}

	int root = 0;
	buildTree(root, 1, n);
	int opt;
	int a, b, c;

	for (int i = 0; i < m; ++i) {
		cin >> opt;

		if(opt == 1) {
			cin >> a >> b >> c;
			range_add(root, a, b, c);
		}

		if(opt == 2) {
			cin >> a >> b;
			cout << range_query(root, a, b) << endl;
		}
	}
}