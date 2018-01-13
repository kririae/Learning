/*
不会莫比乌斯 容斥推式子
*/
#include<bits/stdc++.h>
#define N 10000005
using namespace std;
int n, m, ans;
const unsigned int mod = 1e9 + 7;
int miu[N], vis[N], sum[N];
int prime[N];
int pcnt;
void pre()
{
	miu[1] = 0;
	for(int i = 2; i < N; i++) {
		if(vis[i] == 0) miu[prime[++pcnt] = i] = 1;
		for(int j = 1, t; prime[j]*i < N && j <= pcnt; j++) {
			miu[t = prime[j] * i] = -miu[i];
			vis[t] = 1;
			if(i % prime[j] == 0) {
				miu[prime[j]*i] = 0;
				break;
			}
		}
	}
	for(int i = 2; i < N; i++) sum[i] = (sum[i - 1] + miu[i] * i) % mod;
}
void work()
{
	ans = 0;
	if(n > m) swap(n, m);
	int ne, n1, n2, t1, t2;
	for(int i = 1; i <= n; i = ne + 1) {
		ne = (n1 = n / (t1 = n / i)) < (n2 = m / (t2 = m / i)) ? n1 : n2;
		if(sum[ne] - sum[i - 1] == 0) continue;
		ans = (ans + (long long)t1 % mod * (( (long long)t1 * t1 % mod + (long long)t1 ) % mod * (long long)((long long)t2 * t2 % mod + t2) % mod) % mod * (long long)(sum[ne] - sum[i - 1] + mod) % mod * 250000002 % mod ) % mod;
	}
	cout << ans << endl;
}
int main()
{
	pre();
	int T = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		work();
	}
	return 0;
}
