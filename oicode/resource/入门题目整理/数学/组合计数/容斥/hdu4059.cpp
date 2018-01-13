#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
int n, n2;
LL sum;
const LL mod = 1e9 + 7;
int ys[30];
int cnt;
inline int getval(LL x)
{
	LL k = n2 / x;
	return ((((((k * (k + 1) % mod) * (2 * k + 1) % mod) * (3 * ((k * k) % mod) + 3 * k - 1) % mod) * x % mod) * x % mod) * x % mod) * x % mod;
}
void DFS(int x, int val, int f) //容斥DFS O(2^k) x-当前下标 val-已有乘值  f-当前符号
{
	//end
	if(x > cnt) return;
	if(x == cnt) {
		sum += getval(val) * f - getval(val * ys[x]) * f + mod;
		sum %= mod;
	} else { //not end
		DFS(x + 1, val, f);
		DFS(x + 1, val * ys[x], -f);
	}
}
int main()
{
	int t, t0;
	scanf("%d", &t);
	t0 = t;
	while(t--) {
		scanf("%d", &n);
		sum = 0;
		cnt = 0;
		n2 = n;
		for(int i = 2, k = sqrt(n + 0.1); i <= k; i++) {
			if(n % i == 0) {
				ys[++cnt] = i;
				while(n % i == 0) n /= i;
			}
		}
		if(n != 1) ys[++cnt] = n;
		if(cnt != 0) {
			DFS(1, 1, -1);
			printf("%I64d\n", (mod - (sum * 233333335 % mod)) % mod); //÷30
		} else if(n == 1) {
			puts("1");
		} else {
			printf("%I64d\n", (getval(1) - getval(n2) + mod) * (LL)233333335 % mod);
		}
	}
	return 0;
}
