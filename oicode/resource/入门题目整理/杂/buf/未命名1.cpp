#include<cstdio>
using namespace std;
int main()
{
	int sum, n, m, b;
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		sum = 0;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) scanf("%d", &b), sum += b - '0';
		if(sum & 1) puts("yadang");
		else puts("xiawa");
	}
	return 0;
}
