#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 100005
#define M 20000005
#define low(x) x&(-x)
/*树套树水一水、有点卡空间*/
using namespace std;
const int L = 0, R = 1;
int n, k, all;
struct flow {
	int a, b, c, size;
	bool operator<(const flow &b2) const
	{
		if(a != b2.a) return a < b2.a;
		if(b != b2.b) return b < b2.b;
		return c < b2.c;
	}
} flower[N];
int ans[N];
void init()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &flower[i].a, &flower[i].b, &flower[i].c);
	}
	sort(flower + 1, flower + n + 1);
	flower[0].a = -1;
	for(int i = 1, p = 0; i <= n; i++) {
		if(flower[i].a == flower[i + 1].a &&
		   flower[i].b == flower[i + 1].b &&
		   flower[i].c == flower[i + 1].c) {
			p++;
		} else {
			flower[i].size = p + 1;
			p = 0;
		}
	}
	all = 0;
	for(int i = 1; i <= n; i++) {
		if(flower[i].size == 0) continue;
		flower[++all] = flower[i];
	}
}
//------------------chair tree------
struct node {
	int son[2], size;
} a[M];
int cnt;
void insert_zx(int &k, int fr, int to, const int &val, const int &size)
{
	int t = ++cnt;
	a[t].size = a[k].size + size;
	a[t].son[L] = a[k].son[L];
	a[t].son[R] = a[k].son[R];
	k = t;
	if(fr == to) return;
	int mid = (fr + to) >> 1;
	if(val <= mid) insert_zx(a[k].son[L], fr, mid, val, size);
	else insert_zx(a[k].son[R], mid + 1, to, val, size);
}
int query_zx(int k, int fr, int to, const int &val)
{
	if(val == to) return a[k].size;
	int mid = (fr + to) >> 1;
	if(val > mid) return query_zx(a[k].son[R], mid + 1, to, val) + a[a[k].son[L]].size;
	else return query_zx(a[k].son[L], fr, mid, val);
}
//----------bits--------------------
int roots[N * 2];
void insert(int place, int val, int size)
{
	for(int i = place; i <= k; i += low(i))
		insert_zx(roots[i], 1, k, val, size);
}
int query(int place, int val)
{
	int ret = 0;
	for(int i = place; i > 0; i -= low(i))
		ret += query_zx(roots[i], 1, k, val);
	return ret;
}
//------------------------------
void work()
{
	for(int i = 1; i <= all; i++) {
		int ret = flower[i].size - 1;
		ret += query(flower[i].b, flower[i].c);
		ans[ret] += flower[i].size;
		insert(flower[i].b, flower[i].c, flower[i].size);
	}
}
//------------------------------
int main()
{
	init();
	work();
	for(int i = 0; i <= n - 1; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
