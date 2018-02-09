#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 200005
#define EPS 5
#define db double
using namespace std;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
struct point {
	int x, y;
};
inline point operator -(const point &a, const point &b)
{
	return (point) {
		a.x - b.x, a.y - b.y
	};
}
inline db getdis(const point &a, const point &b)
{
	point c = a - b;
	return 1.0 * c.x * c.x + 1.0 * c.y * c.y;
}
inline bool cmp(const point &a, const point &b)
{
	return a.x < b.x;
}
inline bool cmp2(const point &a, const point &b)
{
	return a.y > b.y;
}
inline db getc(const point &a, const point &b, const point &c)
{
	return sqrt(getdis(a, b)) + sqrt(getdis(b, c)) + sqrt(getdis(a, c));
}
///////////////////////////////////////////库
int n;
point p[N], buf[N];
//还是让常数大点算了，常数小了不好写
db solve(int l, int r, db limit)
{
	db ret = limit;
	if(r - l < EPS) {
		for(int i = l; i <= r; i++)
			for(int j = i + 1; j <= r; j++)
				for(int k = j + 1; k <= r; k++)
					ret = min(ret, getc(p[i], p[j], p[k]));
		return ret;
	}
	int mid = (l + r) >> 1;
	db d1 = solve(l, mid, ret);
	ret = min(ret, d1);
	d1 = solve(mid + 1, r, ret);
	ret = min(ret, d1);
	db hl = ret / 2.0;
	int cnt = 0;
	for(int i = mid; i >= l; i--) {
		if(p[mid + 1].x - p[i].x < hl) buf[cnt++] = p[i];
		else break;
	}
	for(int i = mid + 1; i <= r; i++) {
		if(p[i].x - p[mid].x < hl) buf[cnt++] = p[i];
		else break;
	}//中间部分
	sort(buf, buf + cnt, cmp2);
	for(int b = 0, i = 0; i < cnt; i++) {
		while((buf[i].y - buf[b].y < hl) && (b < cnt - 1)) b++;
		for(int j = i + 1; j <= b; j++) {
			for(int k = j + 1; k <= b; k++) {
				ret = min(ret, getc(buf[i], buf[j], buf[k]));
			}
		}
	}
	return ret;
}
int main()
{
	n = read(); //scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		p[i].x = read();
		p[i].y = read();
	}
	sort(p, p + n, cmp);
	printf("%.6lf", solve(0, n - 1, 1e11));
	return 0;
}
