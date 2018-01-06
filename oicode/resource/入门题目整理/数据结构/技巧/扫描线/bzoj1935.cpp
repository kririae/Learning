#include<cstdio>
#include<algorithm>
#define N 500005
#define low(x) x&(-x)
//不加离散化快一倍
using namespace std;
inline int read() {
	char c = getchar();
	int r = 0;

	while(c < '0' || c > '9') c = getchar();

	while(c >= '0' && c <= '9') r = r * 10 + c - '0', c = getchar();

	return r;
}
//询问包含边界
struct event {
	int x, y;
	int kind;
	int *ans;//1-q 2-insert
} e[N * 5];
struct que {
	int ans[4];
} q[N];
int n, m, cnt, cnt2, cnt3;
int sor[N * 5];
int fil[N * 5];
inline bool cmpx(const int &a, const int &b) {
	if(e[a].x != e[b].x) return e[a].x < e[b].x;

	if(e[a].y != e[b].y) return e[a].y < e[b].y;

	return e[a].kind > e[b].kind;
}
inline bool cmpy(const int &a, const int &b) {
	return e[a].y < e[b].y;
}
//bit
int bit[10000005];
inline void insert(int x) {
	for(int i = x; i <= cnt2; i += low(i)) {
		bit[i]++;
	}
}
inline int query(int x) {
	int ret = 0;

	for(int i = x; i >= 1; i -= low(i)) {
		ret += bit[i];
	}

	return ret;
}
//-----------------
int main() {
	n = read();
	m = read();
	cnt2 = 0;

	for(int i = 1; i <= n; i++) {
		e[i].x = read() + 1;
		e[i].y = read() + 1;
		e[i].kind = 2;
		cnt2 = max(cnt2, e[i].y);
	}

	cnt = n;

	for(int j = 1; j <= m; j++) {
		int l, r, t, b;
		l = read() + 1;
		b = read() + 1;
		r = read() + 1;
		t = read() + 1;
		cnt2 = max(cnt2, t);
		e[++cnt] = (event) {
			l - 1, b - 1, 1, &q[j].ans[0]
		};
		e[++cnt] = (event) {
			r, b - 1, 1, &q[j].ans[1]
		};
		e[++cnt] = (event) {
			r, t, 1, &q[j].ans[2]
		};
		e[++cnt] = (event) {
			l - 1, t, 1, &q[j].ans[3]
		};
	}

	for(int i = 1; i <= cnt; i++) sor[i] = i;

	sort(sor + 1, sor + cnt + 1, cmpx);

	for(int i = 1; i <= cnt; i++) {
		if(e[sor[i]].kind == 1) {
			*(e[sor[i]].ans) = query(e[sor[i]].y);
		} else {
			insert(e[sor[i]].y);
		}
	}

	for(int i = 1; i <= m; i++) {
		printf("%d\n", q[i].ans[2] - q[i].ans[1] - q[i].ans[3] + q[i].ans[0]);
	}

	return 0;
}
