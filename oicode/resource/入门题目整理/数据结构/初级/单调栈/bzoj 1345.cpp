#include<cstdio>
#define N 1000005
using namespace std;
inline int read() {
	char c = getchar();
	int ret = 0;

	while(c < '0' || c > '9') c = getchar();

	while(c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();

	return ret;
}
int n, cnt;
int st[N];
long long ans;
inline void add(int x) {
	while(st[cnt - 1] <= x) {
		cnt--;
		ans += st[cnt - 1] < x ? st[cnt - 1] : x;
	}

	st[cnt++] = x;
}
int main() {
	n = read();
	ans = 0;
	st[cnt++] = 1e9 + 10;

	for(int i = 1; i <= n; i++) {
		int a = read();
		add(a);
	}

	while(cnt > 2) cnt--, ans += st[cnt - 1];

	printf("%lld", ans);
	return 0;
}
