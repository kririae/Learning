#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

struct SegmentTree {
	int l, r;
	int sum;
	int mark;
	int lson, rson;
};

SegmentTree node[maxn << 2];
int cnt = 0;

inline void pushup(int k) {
	node[k].sum = node[ node[k].lson ].sum + node[ node[k].rson ].sum;
}
inline void build(int &k, int l, int r) {
	k = ++cnt;
	node[k].l = l, node[k].r = r;
	if(l == r) {
		node[k].sum = ini[l];
	}	
	else {
		int mid = (node[k].l + node[k].r) >> 1;
		build(node[k].lson, l, mid);
		build(node[k].rson, mid + 1, r);
		pushup(k);
	}
}
int main() {
	return ;
}
