#include<bits/stdc++.h>
using namespace std;
long long k[100005];
int n;
int main() {
	while(scanf("%d", &n) == 1) {
		for(int i = 1; i <= n; i++) scanf("%d", &k[i]);

		if(n & 1) {
			puts("first player");
		} else {
			sort(k + 1, k + n + 1);
			int p = 0;

			for(int i = 1; i <= n; i += 2) if(k[i] != k[i + 1]) {
					p = 1;
					break;
				}

			if(p) puts("first player");
			else puts("second player");
		}
	}

	return 0;
}
