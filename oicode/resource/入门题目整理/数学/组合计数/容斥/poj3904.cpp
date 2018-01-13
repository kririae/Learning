/*好题啊
打通了莫比乌斯反演与偏序集上的容斥
此题即可莫比乌斯，又可容斥
复杂度理论上容斥要小一点，不过容斥递归常数肯定大啊
直接枚举GCD的值，然后容斥或者反演
*/
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int val[10005];
int time[10005];
int miu[10005];
int prime[10005];
int cnt;
#define INF 0x3f3f3f3f
int main()
{
	int m = 10000;
	memset(miu, 0x3f, sizeof(miu));
	miu[1] = 1;
	for(int i = 2; i <= m; i++) { //miu不小心筛错了
		if(miu[i] == INF) miu[i] = -1, prime[++cnt] = i;
		for(int j = 1; j <= cnt && prime[j]*i <= m; j++) {
			if(i == prime[j]) miu[i * i] = 0;
			else if(i % prime[j] == 0) {
				miu[i * prime[j]] = 0;
				break;
			} else miu[i * prime[j]] = -miu[i];
		}
	}
	/*
	心得：
	这部分我纠结了很久，想了想，我们要的μ函数与常函数D氏卷积后只有1的系数为1，其余系数都为0
	所以2的系数需要为-1。
	当然可以思考如何配系数使得，卷积后除1以外所有数系数为1，而1为0，又如何做到全部为1.
	*/
	while(scanf("%d", &n) == 1) {
		for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
		for(int i = 1; i <= n; i++) {
			for(int j = sqrt(val[i]); j; j--) {
				if(val[i] % j == 0) {
					time[j]++;
					if(val[i] != j * j) time[val[i] / j]++;
				}
			}
		}
		long long ans = 0;
		for(int i = 1; i <= 10000; i++) {
			if(time[i] >= 4) {
				ans += (long long)time[i] * (time[i] - 1) * (time[i] - 2) * (time[i] - 3) * miu[i] / 24;
			}
		}
		printf("%lld\n", ans);
		memset(time, 0, sizeof(time));
	}
	return 0;
}
