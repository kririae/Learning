/*
蒟蒻的我看了一小时题解没有看懂
(主要还是颓去了)
*/
#include<cstdio>
#include<algorithm>
#define N 500005
#define LL long long
#define eps 1e-8
using namespace std;
int n;
struct point {
	LL x, y;
};
double getangle(point &a, point &b) {
	return (a.y - b.y) / (double)(a.x - b.x);
}
struct aaa {
	LL a, b;
} a[N];
double xl[N];
point que[N];
int top = 0;
int fr[N];
int getqie(double rad) {
	if(top == 1 || rad > xl[top - 1]) return top;

	int l = 0, r = top - 1;

	while(l + 1 < r) {
		int m = (l + r) >> 1;

		if(xl[m] > rad) {
			r = m;
		} else {
			l = m;
		}
	}

	return r;
}
void insert(LL x, LL y, int i) {
	x = -x;
	point pin = (point) {
		x, y
	};

	while(top > 1 && (getangle(pin, que[top - 1]) < getangle(que[top - 1], que[top]) + eps)) top--;

	que[++top] = pin;
	xl[top - 1] = getangle(pin, que[top - 1]);
	fr[top] = i;
}
bool cmpa(const aaa&c, const aaa&d) {
	if(c.a != d.a) return c.a < d.a;

	return c.b < d.b;
}
int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a[i].a, &a[i].b);
	}

	sort(a + 1, a + n + 1, cmpa);
	int cnt = 0;

	for(int i = 1; i <= n; i++) {
		while(cnt > 0 && a[i].b >= a[cnt].b) cnt--;

		a[++cnt] = a[i];
	}

	que[0].x = -1e12 + 4;

	for(int i = 1; i <= cnt; i++) {
		int j = getqie(a[i].a);
		LL ans1 = min(a[i].a * (LL)a[1].b, que[j].y + (-que[j].x) * a[i].a);
		insert(a[i + 1].b, ans1, i);
	}

	printf("%lld", que[top].y);
	return 0;
}
