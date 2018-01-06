/*≤÷ø‚Ω®…Ë»ıªØ∞Ê*/
#include<cstdio>
#include<iostream>
#define N 1000005
#define LL long long
using namespace std;
LL dp[N];
LL ai;
int que[N];
int head, tail, n;
double slope(int a, int b) {
	return (dp[a] - dp[b] + ((LL)a * a - (LL)b * b + a - b) / 2) / (double)(a - b);
}
int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &ai);

		while(head > tail && (slope(que[tail], que[tail + 1]) < i)) tail++;

		LL j = que[tail];
		dp[i] = (i * (LL)(i - 1)) / 2 + ai + dp[j] + (j * (j + 1)) / 2 - i * j;

		while(head > tail && (slope(que[head], que[head - 1]) >= slope(que[head], i))) head--;

		que[++head] = i;
	}

	printf("%lld", dp[n] - dp[0]);
	return 0;
}
