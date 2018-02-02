#include<cstdio>
#include<iostream>
#define N 1<<19
using namespace std;
int n, m, nn;
int lef_t[N], righ_t[N], all[N], sum[N]; //左侧开始最大值，右侧开始最大值，全部区间中最大值,区间和
inline void update(int k)
{
	sum[k] = sum[k << 1] + sum[(k << 1) | 1];
	lef_t[k] = max(lef_t[k << 1], sum[k << 1] + lef_t[(k << 1) | 1]);
	righ_t[k] = max(righ_t[(k << 1) | 1], sum[(k << 1) | 1] + righ_t[k << 1]);
	all[k] = max(max(all[k << 1], all[(k << 1) | 1]), righ_t[k << 1] + lef_t[(k << 1) | 1]);
}
int query(int fr, int to)
{
	int le = 0, ri = 0, ret = all[fr + nn];
	for(int l = fr + nn - 1, r = to + nn - 1; (l ^ r) != 1; l >>= 1, r >>= 1) {
		if(l & 1 == 0) {
			ret = max(le + lef_t[l + 1], max(all[l + 1], ret));
			le = max(righ_t[l + 1], max(le, le + sum[l + 1]));
		}
		if(r & 1 == 1) {
			ret = max(ri + sum[r - 1], max(ret, all[r - 1]));
			ri = max(lef_t[r - 1], max(ri, ri + sum[r - 1]));
		}
	}
	return ret;
}
void change(int v, int k)
{
	v = nn + v;
	all[v] = lef_t[v] = righ_t[v] = k;
	while(v != 1) {
		v >>= 1;
		update(v);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(nn = 1; nn < n; nn <<= 1);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &all[nn + i]);
		lef_t[nn + i] = righ_t[nn + i] = all[nn + i];
	}
	for(int i = nn - 1; i > 0; i--) {
		update(i);
	}
	for(int i = 1; i <= m; i++) {
		int k, a, b;
		scanf("%d%d%d", &k, &a, &b);
		if(k == 1) {
			if(a > b) swap(a, b);
			printf("%d\n", query(a, b));
		} else if(k == 2) {
			change(a, b);
		}
	}
	return 0;
}
