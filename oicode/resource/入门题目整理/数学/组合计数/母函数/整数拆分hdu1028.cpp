#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define LL long long
LL dp[100000];
int a, b, c, maxn;
int pos[10000];
void work() {
	memset(dp, 0, sizeof(dp));
	memset(pos, 0, sizeof(pos));
	dp[0] = 1;
	int cnt = 0;
	maxn = a + b * 2 + c * 5;

	for(int i = 0; i <= 10; i++)	if(a >= (1 << i)) pos[++cnt] = (1 << i) * 1, a -= (1 << i);

	for(int i = 0; i <= 10; i++)	if(b >= (1 << i)) pos[++cnt] = (1 << i) * 2, b -= (1 << i);

	for(int i = 0; i <= 10; i++)	if(c >= (1 << i)) pos[++cnt] = (1 << i) * 5, c -= (1 << i);

	pos[++cnt] = a;
	pos[++cnt] = b * 2;
	pos[++cnt] = c * 5;

	for(int i = 1; i <= cnt; i++) {
		for(int j = maxn - pos[i]; j >= 0; j--) dp[pos[i] + j] |= dp[j];
	}

	int ans = 0;

	for(int i = 1; i <= maxn + 1; i++) if(dp[i] == 0) {
			ans = i;
			break;
		}

	printf("%d\n", ans);
}
int main() {
	while(scanf("%d%d%d", &a, &b, &c) == 3 && (a || b || c)) {
		work();
	}

	return 0;
}
