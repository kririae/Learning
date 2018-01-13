/*
此题可以线段是套主席树
复杂度Nlognlogm
也可以分块配bitset，查询特别优越，修改也不错
由于bitset跑的太快了，所以分块大小要改一改
分块时忽略掉m的影响取大小sqrt(n)
*/
#include<cstdio>
#include<iostream>
#include<bitset>
#include<cmath>
#define N 100005
using namespace std;
struct block {
	bitset<108> x;
	int tag;//-1
	int st, en;
} b[400];
int a[N], n, m, w, z, q;
inline void build(int i)
{
	b[i].x.reset();
	for(int k = b[i].st; k <= b[i].en; k++) {
		b[i].x[a[k]] = 1;
	}
	b[i].tag = -1;
}
void build_block()
{
	w = sqrt(n);
	z = 1;
	for(int i = 1; i <= n; i += w, z++) {
		b[z].st = i;
		b[z].en = min(i + w - 1, n);
	}
	for(int i = 1; i <= z; i++) {
		build(i);
	}
}
void modify(int l, int r, int c)
{
	int kl = (l - 1) / w + 1, kr = (r - 1) / w + 1;
	if(kl == kr) {
		if(b[kl].tag != -1) {
			for(int i = b[kl].st; i < l; i++) a[i] = b[kl].tag;
			for(int i = r + 1; i <= b[kl].en; i++) a[i] = b[kl].tag;
		}
		for(int i = l; i <= r; i++) a[i] = c;
		build(kl);
	} else {
		if(b[kl].tag != -1) for(int i = b[kl].st; i < l; i++) a[i] = b[kl].tag;
		if(b[kr].tag != -1) for(int i = r + 1; i <= b[kr].en; i++) a[i] = b[kr].tag;
		for(int i = l; i <= b[kl].en; i++) a[i] = c;
		for(int i = b[kr].st; i <= r; i++) a[i] = c;
		build(kl);
		build(kr);
		for(int i = kl + 1; i < kr; i++) b[i].tag = c;
	}
}
int query(int l, int r)
{
	int kl = (l - 1) / w + 1, kr = (r - 1) / w + 1;
	bitset<108> ans;
	if(kl == kr) {
		if(b[kl].tag != -1) {
			return 1;
		}
		for(int i = l; i <= r; i++) ans[a[i]] = 1;
	} else {
		if(b[kl].tag != -1) ans[b[kl].tag] = 1;
		else for(int i = l; i <= b[kl].en; i++) ans[a[i]] = 1;
		if(b[kr].tag != -1) ans[b[kr].tag] = 1;
		else for(int i = b[kr].st; i <= r; i++) ans[a[i]] = 1;
		for(int i = kl + 1; i < kr; i++) if(b[i].tag == -1) ans |= b[i].x;
			else ans[b[i].tag] = 1;
	}
	return ans.count();
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build_block();
	scanf("%d", &q);
	char buf[3];
	int l, r, c;
	for(int i = 1; i <= q; i++) {
		scanf("%s", &buf);
		if(buf[0] == 'M') {
			scanf("%d%d%d", &l, &r, &c);
			modify(l, r, c);
		} else {
			scanf("%d%d", &l, &r);
			printf("%d\n", query(l, r));
		}
	}
	return 0;
}
