#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 200005
#define INF 210000000000.0
using namespace std;
//这个快速读入有错
inline void read(int &x)
{
	char c = getchar();
	x = 0;
	int f = 1;
	while(c == ' ' || c == '\n') c = getchar();
	while((c >= '0' && c <= '9') || c == '-') {
		if(c == '-') f = -1;
		else x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}
struct arr {
	int x, y;
} a[N], num[N];
int n, i, Test;
inline bool cmpx(const arr &a, const arr &b)
{
	return a.x < b.x;
}
inline bool cmpy(const arr &a, const arr &b)
{
	return a.y < b.y;
}
inline double dis(const arr &a, const arr &b)
{
	return sqrt((a.x - b.x) * 1.*(a.x - b.x) + (a.y - b.y) * 1.*(a.y - b.y));
}
inline double work(int l, int r)
{
	if (l == r) return INF;
	if (l + 1 == r) return INF;
	if (l + 2 == r) return dis(a[l], a[l + 1]) + dis(a[l + 1], a[r]) + dis(a[l], a[r]);
	int mid = (l + r) >> 1;
	double d1 = work(l, mid), d2 = work(mid + 1, r);
	double D = min(d1, d2), ans = D, DD = D / 2.0;
	int cnt = 0;
	for (int i = l; i <= r; i++)
		if (fabs(a[mid].x - a[i].x) <= DD) num[++cnt] = a[i];
	sort(num + 1, num + cnt + 1, cmpy);
	for (int i = 1; i < cnt - 1; i++)
		for (int j = i + 1; j < cnt; j++) {
			if (num[j].y - num[i].y > DD) break;
			for (int k = j + 1; k <= cnt; k++) {
				if (num[k].y - num[i].y > DD) break;
				double temp = dis(num[i], num[j]) + dis(num[i], num[k]) + dis(num[j], num[k]);
				if (temp < ans) ans = temp;
			}
		}
	return ans;
}
int main()
{
	read(n);//读入优化就不贴了。
	for (i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y);
	sort(a + 1, a + n + 1, cmpx);
	printf("%.6lf", work(1, n));
	return 0;
}
