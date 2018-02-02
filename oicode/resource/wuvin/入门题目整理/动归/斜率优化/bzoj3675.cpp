/*好神奇的推式子
sum不是单调增的可以为0*/
#include<cstdio>
#include<iostream>
#define N 100005
#define K 202
#define INF 1e15
#define LL long long
using namespace std;
LL dp[3][N];
LL sum[N];
int que[N];
int head, tail, n, k;
double slope(int a, int b, int tt)
{
	if(sum[a] == sum[b]) return INF;
	return (dp[tt][a] - dp[tt][b] + sum[a] * sum[a] - sum[b] * sum[b]) / (double)(2 * (sum[a] - sum[b]));
}
int main()
{
	scanf("%d%d", &n, &k);
	k++;
	for(int i = 1; i <= n; i++) scanf("%d", &sum[i]);
	for(int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	for(int i = 1; i <= n; i++) dp[1][i] = sum[i] * sum[i];
	for(int j = 2; j <= k; j++) {
		head = tail = 0;
		int jj = j & 1;
		for(int i = 1; i <= n; i++) {
			while(head > tail && (slope(que[tail], que[tail + 1], jj ^ 1) < sum[i])) tail++;
			int t = que[tail];
			dp[jj][i] = dp[jj ^ 1][t] + (sum[i] - sum[t]) * (sum[i] - sum[t]);
			while(head > tail && (slope(que[head], que[head - 1], jj ^ 1) > slope(que[head], i, jj ^ 1))) head--;
			que[++head] = i;
		}
	}
	printf("%lld", (sum[n]*sum[n] - dp[k & 1][n]) / 2);
	return 0;
}
