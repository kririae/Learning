#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define eps 1e-8
#define db int
#define N 2005
/*
AÁË
*/
using namespace std;
const int L = 0;
const int R = 1;
const int Wood = 1;
const int Frog = 2;
struct point {
	db x, y;
	int kind, val;
};
struct seg {
	point a, b;
};
point dec(point a, point b)
{
	point ret;
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	return ret;
}
db cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
int side(point &from, point &to, point &b)
{
	int buf = cross(dec(to, from), dec(b, from));
	if(buf > 0) return R;
	//else if(buf==0) return Mid;
	return L;
}
inline bool equ(db a, db b)
{
	if(abs(a - b) < eps) return true;
	return false;
}
point p[N];
int sor[N];
//////////////////////////////////////Æ½ºâÊ÷
int root, size, p0;
int son[N][2], pri[N], name[N];
db sumval[N];
inline void update(int k)
{
	sumval[k] = sumval[son[k][L]] + sumval[son[k][R]] + p[name[k]].val;
}
inline void turn(int &k, int side_)
{
	int tt = son[k][side_ ^ 1];
	son[k][side_ ^ 1] = son[tt][side_];
	son[tt][side_] = k;
	update(k);
	k = tt;
	update(k);
}
void insert_(int &k, int po)
{
	if(k == 0) { //new
		k = ++size;
		name[k] = po;
		son[k][L] = son[k][R] = 0;
		pri[k] = rand();
		sumval[k] = p[po].val;
		return;
	}
	sumval[k] += p[po].val;
	int si = side(p[p0], p[name[k]], p[po]);
	insert_(son[k][si], po);
	if(pri[k] < pri[son[k][si]]) turn(k, si ^ 1);
}
db query(int k, int po)
{
	if(k == 0) return 0;
	int si = side(p[p0], p[name[k]], p[po]);
	if(si == L) return query(son[k][L], po);
	else return query(son[k][R], po) + sumval[son[k][L]] + p[name[k]].val;
}
///////////////////////////////////////·â×°
void pre(int jizhun)
{
	root = 0;
	size = 0;
	p0 = jizhun;
}
inline void insert(int po)
{
	insert_(root, po);
}
inline db query(int po)
{
	return query(root, po);
}
///////////////////////////////////////
int n, m;
inline bool cmp1(const int &a, const int &b)
{
	if(p[a].y == p[b].y) {
		return p[a].x < p[b].x;
	} else {
		return p[a].y > p[b].y;
	}
}
void init()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		p[i].x = xx;
		p[i].y = yy;
		p[i].kind = Wood;
	}
	for(int i = n + 1; i <= n + m; i++) {
		int xx, yy, va;
		scanf("%d%d%d", &xx, &yy, &va);
		p[i].x = xx;
		p[i].y = yy;
		p[i].val = va;
		p[i].kind = Frog;
	}
	for(int i = 1; i <= n + m; i++) {
		sor[i] = i;
	}
	sort(sor + 1, sor + n + m + 1, cmp1);
}
db tb[1005][1005];
int buf[N];
int main()
{
	init();
	for(int i = 1; i <= n + m; i++) {
		if(p[sor[i]].kind == Frog) continue;
		pre(sor[i]);
		for(int j = i + 1; j <= n + m; j++) {
			if(p[sor[j]].kind == Frog) insert(sor[j]);
			else if(p[sor[j]].kind == Wood) tb[sor[i]][sor[j]] = tb[sor[j]][sor[i]] = query(sor[j]);
		}
	}
	int q = 0;
	scanf("%d", &q);
	for(int qq = 1; qq <= q; qq++) {
		db ans = 0;
		int al = 0;
		scanf("%d", &al);
		for(int i = 1; i <= al; i++) {
			scanf("%d", &buf[i]);
		}
		buf[al + 1] = buf[1];
		for(int i = 1; i <= al; i++) {
			if(p[buf[i]].y > p[buf[i + 1]].y) ans += tb[buf[i]][buf[i + 1]];
			else ans -= tb[buf[i]][buf[i + 1]];
		}
		printf("%d\n", abs(ans));
	}
	return 0;
}
