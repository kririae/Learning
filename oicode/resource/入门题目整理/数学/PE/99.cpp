#include<bits/stdc++.h>
#define LL long long
#define eps 1e-8
/*
如何巧妙使用log
*/
using namespace std;
LL ans;
double a[1002];
int main()
{
	int n = 1000;
	for(int i = 1, a1, x; i <= n; i++) {
		scanf("%d,%d", &a1, &x);
		a[i] = x * log(a1);
	}
	ans = 1;
	for(int i = 1; i <= n; i++) {
		if(a[i] > a[ans] - eps) ans = i;
	}
	printf("%d", ans);
	return 0;
}
