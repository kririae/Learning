#include<cstdio>
#include<cmath>
#include<iostream>
#include<queue>
#define N 200005
using namespace std;
/*对于所有开根操作，直接落实*/
int n, m, nn, cnt;
int one[N], le[N], ri[N], lson[N], rson[N]; //记录一个区间是否全是1，sum区间和
long long sum[N], a[N];
//普通线段树
inline void update(int &k)
{
	sum[k] = sum[lson[k]] + sum[rson[k]];
	one[k] = one[lson[k]] & one[rson[k]];
}
void build(int &k, int l, int r)
{
	k = cnt++;
	le[k] = l;
	ri[k] = r;
	if(l != r) {
		int mid = (l + r) >> 1;
		build(lson[k], l, mid);
		build(rson[k], mid + 1, r);
		update(k);
	} else {
		sum[k] = a[l];
		if(sum[k] == 1) one[k] = 1;
	}
}
void sqr(int k, int from, int to)
{
	if(one[k]) return;
	if(le[k] == ri[k]) {
		sum[k] = (int)sqrt(sum[k]);
		a[from] = sum[k];
		if(sum[k] == 1) one[k] = 1;
	} else {
		int mid = (le[k] + ri[k]) >> 1;
		if(from <= mid) 	sqr(lson[k], from, min(mid, to));
		if(to > mid)	sqr(rson[k], max(mid + 1, from), to);
		update(k);
	}
}
long long getsum(int k, int fr, int to)
{
	if(one[k]) return to - fr + 1;
	if(le[k] == fr && ri[k] == to) return sum[k];
	int mid = (le[k] + ri[k]) >> 1;
	long long ret = 0;
	if(fr <= mid) 	ret += getsum(lson[k], fr, min(mid, to));
	if(to > mid)	ret += getsum(rson[k], max(mid + 1, fr), to);
	return ret;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	int root = 0;
	build(root, 1, n);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		int ins, a1, b;
		scanf("%d%d%d", &ins, &a1, &b);
		if(a1 > b) swap(a1, b);
		if(ins == 0) sqr(0, a1, b);
		else printf("%lld\n", getsum(0, a1, b));
	}
	return 0;
}
