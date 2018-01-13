#include<bits/stdc++.h>
#define LL long long
/*积性递推因数个数
if gcd(a,b)==1
f(a*b)=f(a)*f(b)
但好像做不到，比如72
不如暴力
然后暴找*/
using namespace std;
int a[2000005];
int pr[1000005];
int cnt = 0;
LL ans = 0;
int main()
{
	int n = 1000000;
	a[1] = 1;
	for(int i = 2; i <= n; i++) {
		LL p = i * (LL)(i - 1) / 2;
		int t = 0, ys = 1;
		for(int k = 2, f = sqrt(p) + 1; k <= f; k++) {
			t = 0;
			while(p % k == 0) p /= k, t++;
			ys *= t + 1;
			if(ys >= 500) {
				printf("%d\n", (LL)i * (i - 1) / 2);
				return 0;
			}
		}

	}
	cout << ans << endl;
	return 0;
}
