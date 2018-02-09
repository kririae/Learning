//# 方便不讨论奇偶
#include<cstdio>
#include<cstring>
#define N 110005
using namespace std;
char s[N];
char T[N * 2];
int hw[N * 2];
int main()
{
	while(scanf("%s", s + 1) == 1) {
		int n;
		n = strlen(s + 1);
		s[0] = '*';
		for(int i = 1; i <= n; i++) {
			T[i * 2] = s[i];
			T[i * 2 - 1] = 'a'; //其实可以不用用'#'，反正对不上
		}
		T[n * 2 + 1] = '#';
		int p = 0, len = n * 2 + 1, po;
		for(int i = 1; i <= len; i++) {
			if(p >= i) {
				int j = (po << 1) - i;
				//if(i+hw[j]-1<=p) {hw[i]=hw[j];continue;}
				if(i + hw[j] - 1 < p) {
					hw[i] = hw[j];    //一定要是>
					continue;
				}
				while(p + 1 <= len && (i << 1) - (p + 1) > 0 && T[p + 1] == T[(i << 1) - (p + 1)]) p++;
				hw[i] = p - i + 1;
				po = i;
			} else {
				p++;
				while(p + 1 <= len && (i << 1) - (p + 1) > 0 && T[p + 1] == T[(i << 1) - (p + 1)]) p++;
				hw[i] = p - i + 1;
				po = i;
			}
		}
		int maxn = 0;
		for(int i = 1; i <= len; i++) if(maxn < hw[i] - 1) maxn = hw[i] - 1;
		printf("%d\n", maxn);
	}
	return 0;
}
