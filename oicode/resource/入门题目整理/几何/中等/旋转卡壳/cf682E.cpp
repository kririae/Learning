#include<cstdio>
#include<iostream>
#include<algorithm>
#define DB int
#define LL long long
#define eps 1e-8
using namespace std;
struct point {
	DB x, y;
};
inline LL side(point o, point a, point b) {
	return (LL)(a.x - o.x) * (b.y - o.y) - (LL)(b.x - o.x) * (a.y - o.y);
}
//------------------------------------
inline LL absx(LL x) {
	return x < 0 ? -x : x;
}
int n;
point p[5005];
bool cmp(const point &a, const point &b) {
	if(a.x != b.x) return a.x < b.x;

	return a.y < b.y;
}
point tb[20005];
int tbcnt;
void gettb() {
	sort(p + 1, p + n + 1, cmp);

	for(int i = 1; i <= n; i++) {
		while(tbcnt > 1 && side(tb[tbcnt - 1], tb[tbcnt], p[i]) <= 0) tbcnt--;

		tb[++tbcnt] = p[i];
	}

	int t = tbcnt;

	for(int i = n - 1; i >= 2; i--) {
		while(tbcnt > t && side(tb[tbcnt - 1], tb[tbcnt], p[i]) <= 0) tbcnt--;

		tb[++tbcnt] = p[i];
	}
}
LL s = 0;
point tri[4];
void update(const point &a, const point &b, const point &c) {
	LL t;

	if( (t = absx(side(a, b, c))) > s) {
		s = t;
		tri[1] = a;
		tri[2] = b;
		tri[3] = c;
	}
}
void maxtri() { //ÕýÈ·×ËÊÆ bcbcbca bcbcbca
	int	a = 1, b = 2, c = 3;
	int ta = 1, t_b = 2, tc = 3;

	while(a < tbcnt + 1) {
		int p2 = 1;

		do {
			p2 = 1;

			while(c < 2 * tbcnt && absx(side(tb[a], tb[b], tb[c])) <= absx(side(tb[a], tb[b], tb[c + 1]))) c++, p2 = 0;

			while(b < 2 * tbcnt && absx(side(tb[a], tb[b], tb[c])) <= absx(side(tb[a], tb[b + 1], tb[c]))) b++, p2 = 0;
		} while(!p2);

		update(tb[a], tb[b], tb[c]);

		if(c > tbcnt) c -= tbcnt;

		if(b > tbcnt) b -= tbcnt;

		a++;
	}
}
int main() {
	scanf("%d", &n);
	LL s;
	cin >> s;

	for(int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
	}

	gettb();

	for(int i = 1; i <= tbcnt; i++) tb[i + tbcnt] = tb[i];

	maxtri();
	printf("%I64d %I64d\n", ((LL)tri[1].x + tri[2].x - tri[3].x), ((LL)tri[1].y + tri[2].y - tri[3].y));
	printf("%I64d %I64d\n", ((LL)tri[1].x - tri[2].x + tri[3].x), ((LL)tri[1].y - tri[2].y + tri[3].y));
	printf("%I64d %I64d\n", ((LL) - tri[1].x + tri[2].x + tri[3].x), ((LL) - tri[1].y + tri[2].y + tri[3].y));
	return 0;
}
