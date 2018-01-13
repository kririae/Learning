#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define LL long long
#define N 100005
using namespace std;
/*
数据太强，随机算法过不去怎么办
*/
inline LL read()
{
	char c = getchar();
	LL ret = 0;
	while(c == ' ' || c == '\n') c = getchar();
	while(c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret;
}
struct point {
	long double x, y;
};
point operator -(point &a, point &b)
{
	return (point) {
		a.x - b.x, a.y - b.y
	};
}
inline long double getdis(point &a, point &b)
{
	point c = a - b;
	return (long double)c.x * c.x + (long double)c.y * c.y;
}
inline point rotate(point &a, double b)
{
	long double c = cos(b);
	long double s = sin(b);
	return (point) {
		a.x*c - a.y*s, a.x*s + a.y*c
	};
}
///////////////////////////////////////////库
/*
随机旋转一下，每个点和与自己x值相近的左右5个点求值
*/
long double ans = 1e35;
int T, n, k;
int gt[N], ht[N];
point g[N];//特工
point h[N];//核电站
void bl() //暴力
{
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			long double d = getdis(g[i], h[j]);
			if(d < ans) ans = d;
		}
	}
}
bool cmp1(const int a, const int b)
{
	return g[a].x < g[b].x;
}
bool cmp2(const int a, const int b)
{
	return h[a].x < h[b].x;
}
void sj() //随机
{
	for(int tt = 1; tt <= 40; tt++) {
		int r = rand() / 100000.0;
		for(int i = 1; i <= n; i++) {
			g[i] = rotate(g[i], r);
			h[i] = rotate(h[i], r);
		}
		for(int i = 1; i <= n; i++) {
			gt[i] = ht[i] = i;
		}
		sort(gt + 1, gt + n + 1, cmp1);
		sort(ht + 1, ht + n + 1, cmp2);
		int p1 = 1;
		for(int i = 1; i <= n; i++) {
			if(g[gt[p1]].x < h[ht[i]].x) p1++;
			for(int j = -20; j <= 20; j++) {
				if(p1 + j > 1 && p1 + j <= n) {
					long double d = getdis(g[gt[p1 + j]], h[ht[i]]);
					if(d < ans) ans = d;
				}
			}
		}
		if(ans < 1e-4) break;
	}
}
int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		ans = 1e35;
		for(int i = 1; i <= n; i++) {
			g[i].x = read();
			g[i].y = read();
		}
		for(int j = 1; j <= n; j++) {
			h[j].x = read();
			h[j].y = read();
		}
		if(n <= 3000) {
			bl();
		} else {
			sj();
		}
		printf("%.3f\n", sqrt(ans));
	}
	return 0;
}
