#include<bits/stdc++.h>
#define LL long long
/*
枚举分母
注意答案输出分子
*/
using namespace std;
int ans1 = 1, ans2 = 8;
double maxn = 0;
int gcd(int mn, int mx) {
	if(mn == 0) return 0;

	if(mx % mn == 0) return mn;

	return gcd(mx % mn, mn);
}
int main() {
	int n = 1000000;

	for(int i = n; i >= 1; i--) {
		if(i == 7) continue;

		int b = 3 * i / 7;

		if(gcd(b, i) != 1) continue;

		if(((LL)b * (LL)ans2 >= (LL)i * (LL)ans1)) ans1 = b, ans2 = i, printf("%d/%d\n", ans1, ans2);
	}

	printf("%d %d", ans1, ans2);
	return 0;
}
