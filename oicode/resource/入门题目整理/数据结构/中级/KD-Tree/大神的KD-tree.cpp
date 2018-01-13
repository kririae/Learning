#include<cstdio>
#include<algorithm>
#include<cmath>
#define MAXN 100005
#define INF 1e100
#define sqr(x) ((x)*(x))
using namespace std;
struct Point {
	double d[2];
	double mn[2], mx[2];
	int l, r;
} p[MAXN], t[MAXN];
int n, root, id;
double ret, ans;
Point T;
bool cmpx(Point A, Point B)
{
	return A.d[0] < B.d[0];
}
bool cmpy(Point A, Point B)
{
	return A.d[1] < B.d[1];
}
double dis(Point A, Point B)
{
	return sqrt(sqr(A.d[0] - B.d[0]) + sqr(A.d[1] - B.d[1]));
}
void pushup(int rt)
{
	for (int i = 0; i < 2; i++) {
		t[rt].mn[i] = t[rt].mx[i] = t[rt].d[i];
		if (t[rt].l) {
			t[rt].mn[i] = min(t[rt].mn[i], t[t[rt].l].mn[i]);
			t[rt].mx[i] = max(t[rt].mx[i], t[t[rt].l].mx[i]);
		}
		if (t[rt].r) {
			t[rt].mn[i] = min(t[rt].mn[i], t[t[rt].r].mn[i]);
			t[rt].mx[i] = max(t[rt].mx[i], t[t[rt].r].mx[i]);
		}
	}
}
int build(int l, int r, int pt)
{
	int m = (l + r) >> 1;
	if (pt == 0) nth_element(p + l, p + m, p + r + 1, cmpx);
	else nth_element(p + l, p + m, p + r + 1, cmpy);
	t[m] = p[m];
	for (int i = 0; i < 2; i++)
		t[m].mn[i] = t[m].mx[i] = t[m].d[i];
	if (l < m)t[m].l = build(l, m - 1, pt ^ 1);
	if (r > m)t[m].r = build(m + 1, r, pt ^ 1);
	pushup(m);
	return m;
}
double judge(int rt)
{
	double tmp = 0;
	tmp += sqr(max(max(t[rt].mn[0] - T.d[0], T.d[0] - t[rt].mx[0]), 0.0));
	tmp += sqr(max(max(t[rt].mn[1] - T.d[1], T.d[1] - t[rt].mx[1]), 0.0));
	return sqrt(tmp);
}
void query(int rt)
{
	double tmp = dis(t[rt], T), dl = INF, dr = INF;
	if (rt != id)ret = min(ret, tmp);
	if (t[rt].l)dl = judge(t[rt].l);
	if (t[rt].r)dr = judge(t[rt].r);
	if (dl < dr) {
		if (dl < ret)query(t[rt].l);
		if (dr < ret)query(t[rt].r);
	} else {
		if (dr < ret)query(t[rt].r);
		if (dl < ret)query(t[rt].l);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &p[i].d[0], &p[i].d[1]);
	root = build(1, n, 0);
	ans = INF;
	for (int i = 1; i <= n; i++) {
		ret = INF;
		id = i;
		T.d[0] = p[i].d[0];
		T.d[1] = p[i].d[1];
		query(root);
		ans = min(ans, ret);
	}
	printf("%.4lf\n", ans);
}
