#include<bits/stdc++.h>
#define LL long long
/*线筛
比较懒，就带log*/
using namespace std;
int a[2000005];
LL ans = 0;
int main()
{
	int n = 2000000;
	for(int i = 2; i <= n; i++) {
		if(a[i] == 0) ans += i;
		for(int j = 2; i * j <= n && j <= i; j++) {
			a[i * j] = 1;
		}
	}
	cout << ans;
	//printf("%I64d\n",ans);
	return 0;
}
