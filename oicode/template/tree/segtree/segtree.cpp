#include <bits/stdc++.h>
using namespace std;
// following
const int maxn = 1000;
struct segtreeNode {
	int val;
} segTree[maxn];
int arr[maxn];
inline void build(int root, int istart, int iend) {
	if(istart == iend) {
		segTree[root].val = arr[istart];
	} else {
		ind midd = (istart + iend) / 2;
		build((root << 1) + 1, istart, midd);
		build((root << 1) + 2, midd + 1, iend);
		segTree[root].val = min(segTree[(root << 1) + 1].val, segTree[(root << 1) + 2].val);
	}
}
