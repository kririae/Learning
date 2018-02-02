/*
让我善良地来翻译一下吧。
一个长为n的数组a,a[i]=i;每个位置权为0;
每次操作“1 l r x”可以将i位置的权值增加|a[i]-x|,然后a[i]=x;
查询"2 l r"查询区间[l,r]的权和。
题解：
这是一道不错的时间复杂度分析题。
做法1：记录每个区间是否为同一个值，不是就暴力下传操作。
可以证明时间复杂度是（n+m）logn的。
当前局面的权值设为不同的值的个数。
初始权值为n。每次操作权值减少r-l;
因为每次对于1的权值都会有一个logn级的操作，
故(n+m)logn
方法二：一的保守版，记录max，min，sum。
如果x不小于min或大于max暴力下去。
等等分析有误。
11111111
dye(2,4,2);
常数分析有误
注意longlong
这题的颜色标记不能简单下传
*/
#include<cstdio>
#define LL long long
#define N 200005
using namespace std;
const int L = 0, R = 1;
int n, m, root, cnt;
inline int abs(int x)
{
	return x < 0 ? -x : x;
}
//-------------------
int son[N][2], v[N], fr[N], to[N], c[N];
LL sum[N], stag[N]; //v是统一颜色初始为- c[N]-tag 可以打tag的前提是颜色统一
void build(int &k, int fr_, int to_)
{
	k = ++cnt;
	sum[k] = 0;
	v[k] = -k;
	fr[k] = fr_;
	to[k] = to_;
	son[k][L] = son[k][R] = 0;
	if(fr_ == to_) v[k] = fr_;
	else {
		int mid = (fr_ + to_) >> 1;
		build(son[k][L], fr_, mid);
		build(son[k][R], mid + 1, to_);
	}
}
inline void update(int k)
{
	if(son[k][L] == 0) return;
	sum[k] = sum[son[k][L]] + sum[son[k][R]];
	if(v[son[k][L]] == v[son[k][R]]) v[k] = v[son[k][L]];
	else v[k] = -k;
}
inline void dye(int k, int color)
{
	stag[k] += abs(color - v[k]);
	sum[k] += (LL)(to[k] - fr[k] + 1) * (LL)abs(color - v[k]);
	v[k] = color;
	c[k] = color;
}
inline void pushdown(int k)
{
	if(c[k] == 0 || k == 0) return;
	if(son[k][L]) {
		sum[son[k][L]] += stag[k] * (to[son[k][L]] - fr[son[k][L]] + 1);
		sum[son[k][R]] += stag[k] * (to[son[k][R]] - fr[son[k][R]] + 1);
		stag[son[k][L]] += stag[k];
		stag[son[k][R]] += stag[k];
		v[son[k][L]] = v[son[k][R]] = c[k];
		c[son[k][L]] = c[son[k][R]] = c[k];
		c[k] = 0;
		stag[k] = 0;
	}
}
void change(int k, int color, int start, int end)
{
	int mid = (fr[k] + to[k]) >> 1;
	pushdown(k);
	if(start == fr[k] && end == to[k] && v[k] > 0) {
		dye(k, color);
		return;
	} else if(mid < start) change(son[k][R], color, start, end);
	else if(mid >= end) change(son[k][L], color, start, end);
	else change(son[k][L], color, start, mid), change(son[k][R], color, mid + 1, end);
	update(k);
}
LL query(int k, int start, int end)
{
	int mid = (fr[k] + to[k]) >> 1;
	pushdown(k);
	if(start == fr[k] && end == to[k])  return sum[k];
	else if(mid < start)  return query(son[k][R], start, end);
	else if(mid >= end)  return query(son[k][L], start, end);
	else return query(son[k][L], start, mid) + query(son[k][R], mid + 1, end);
}
int main()
{
	scanf("%d%d", &n, &m);
	build(root, 1, n);
	for(int i = 1, ins, l, r, x; i <= m; i++) {
		scanf("%d", &ins);
		if(ins == 1) {
			scanf("%d%d%d", &l, &r, &x);
			change(root, x, l, r);
		} else {
			scanf("%d%d", &l, &r);
			printf("%I64d\n", query(root, l, r));
		}
	}
	return 0;
}
