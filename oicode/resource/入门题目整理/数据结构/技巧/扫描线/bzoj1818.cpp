#include<cstdio>
#include<algorithm>
#define N 100005
#define low(x) x&(-x)
using namespace std;
int bitree[N];
struct point {
	int x, y, fl; //fl==1 这个点是开始点 fl==2这个点是结束点 fl==0请忽略
} p[N];
int n;
inline bool cmpy(const point &a, const point &b) {
	if(a.y == b.y) return a.x < b.x;

	return a.y < b.y;
}
inline bool cmpx(const point &a, const point &b) {
	if(a.x == b.x) return a.y < b.y;

	return a.x < b.x;
}
inline void del(int x) {
	for(int i = x; i <= n; i += low(i)) bitree[i]--;
}
long long query(int fr, int to) {
	long long ret = 0;

	for(int i = fr - 1; i > 0; i -= low(i)) ret -= bitree[i];

	for(int i = to; i > 0; i -= low(i)) ret += bitree[i];

	return ret;
}
int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i].x, &p[i].y);
	}

	sort(p + 1, p + n + 1, cmpy); //可以采用hash代替
	int buf = -1e9 - 2, cnt = 1;

	for(int i = 1; i <= n; i++) { //离散化
		if(p[i].y == buf) p[i].y = p[i - 1].y;
		else buf = p[i].y, p[i].y = cnt++;
	}

	p[1].fl = 1;

	for(int i = 2; i <= n; i++) {
		if(p[i].y != p[i - 1].y) {
			if(p[i].y == p[i + 1].y)
				p[i].fl = 1;
		} else if(p[i].y != p[i + 1].y) {
			p[i].fl = 2;
		}
	}

	sort(p + 1, p + n + 1, cmpx);
	p[0].x = -1e9 - 2;
	buf = -1e9 - 2, cnt = 1;

	for(int i = 1; i <= n; i++) { //离散化
		if(p[i].x == buf) p[i].x = p[i - 1].x;
		else buf = p[i].x, p[i].x = cnt++;
	}

	long long ans = 0;

	for(int i = 1; i <= n; i++) {
		if(p[i].x == p[i - 1].x) {
			ans += query(p[i - 1].y + 1, p[i].y - 1);
		}

		if(p[i].fl == 1) for(int i = x; i <= n; i += low(i)) bitree[i]++;
		else if(p[i].fl == 2) for(int i = x; i <= n; i += low(i)) bitree[i]--;
	}

	printf("%lld", ans + n);
	return 0;
}
