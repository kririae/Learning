// by kririae
#include <bits/stdc++.h>
#define ll long long
#define ls t[k].son[0]
#define rs t[k].son[1]
using namespace std;

const int N = 150005;
struct Node
{
	int l, r, son[2];
	double S, L, MID, R;
} t[N << 2];
int n, m, k, x[N], p[N], a, b, X[N], rt, cnt;
inline void pushup(int k)
{
	t[k].S = t[ls].S + t[rs].S;
	t[k].L = max(t[ls].L, t[ls].S + t[rs].L);
	t[k].R = max(t[rs].R, t[rs].S + t[ls].R);
	t[k].MID = max(t[ls].MID, t[rs].MID);
	t[k].MID = max(t[k].MID, t[ls].R + t[rs].L);
}
inline void build(int &k, int l, int r)
{
	k = ++cnt, t[k].l = l, t[k].r = r;
	if(l == r) 
		return t[k].L = t[k].MID = t[k].R = 
		(x[l + 1] - x[l]) / 2.0 - (p[l] * ::k) / 100.0, void();
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(k);
}
inline double query(int k, int l, int r)
{
	if(t[k].l == l && t[k].r == r)
		return t[k].MID;
	int mid = t[k].l + t[k].r >> 1;
	if(r <= mid) return query(ls, l, r);
	else if(l > mid) return query(rs, l, r);
	else return query(ls, l, mid) + query(rs, mid + 1, r);
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
	for (int i = 1; i < n; ++i) scanf("%d", &p[i]);
	build(rt, 1, n - 1);
	double ans = 0;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		ans += max(0.0, query(rt, a, b - 1));
	} printf("%.2lf", ans);
}