#include<bits/stdc++.h>
#define LL long long
/*逆向思维?不会
模拟+记忆化*/
using namespace std;
int a[152][102];
int ans = 0;
int jyh[50000005];
int L = 50000005;
int main()
{
	int n = 1000000;
	LL m = 1;
	int maxn = 0;
	for(int i = n; i >= 500000; i--) {
		m = i;
		int p = 1;
		while(m != 1) {
			if(m == 9) {
				int wkl = 0;
			}
			if(m < L && jyh[m] != 0) {
				p = p + jyh[m] - 1;
				break;
			}
			if((m & 1) == 0) m >>= 1;
			else m = m * 3 + 1;
			p++;
		}
		if(p > maxn) maxn = p, ans = i;
		m = i;
		int p2 = 0;
		while(m != 1) {
			if(m < L) {
				if(jyh[m] != 0) break;
				else jyh[m] = p - p2;
			}
			if((m & 1) == 0) m >>= 1;
			else m = m * 3 + 1;
			p2++;
		}
	}
	printf("%d", ans);
	return 0;
}
