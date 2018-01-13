#include<bits/stdc++.h>
/*其实可以O(n)*/
using namespace std;
long long a[2000];
int main()
{
	for(int i = 1; i <= 1000; i++) {
		char c = getchar();
		while(c < '0' || c > '9') c = getchar();
		a[i] = c - '0';
	}
	long long ans = 0;
	for(int i = 1; i <= 988; i++) {
		long long sum = 1;
		for(int j = i; j <= i + 12; j++) {
			sum *= a[j];
		}
		ans = max(ans, sum);
	}
	printf("%I64d\n", ans);
	return 0;
}
