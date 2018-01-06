#include<cstdio>
#include<iostream>
using namespace std;
int fp[1000005];
char pp[1000005];
int m, n, k;
/*
***lrj动态构造法
*/
void build_demo1(char *demo, int *f, int len) { //f整体左移一位
	fill(f + 0, f + len + 1, 0);

	for(int i = 1; i < len; i++) {
		int p = f[i - 1];

		while(p && demo[p] != demo[i]) p = f[p - 1];

		//f[i+1]=(p==0)? 0:p+1;  错误   aaa
		f[i] = (demo[p] == demo[i]) ? p + 1 : 0;
	}
}

int main() {
	int count = 0;

	do {
		scanf("%d", &n);

		if(n == 0) return 0;

		scanf("%s", pp);
		count++;
		printf("Test case #%d\n", count);
		build_demo1(pp, fp, n);

		for(int i = 1; i < n; i++) {
			if(fp[i] % (i - fp[i] + 1) == 0 && fp[i]) {
				printf("%d %d\n", i + 1, (fp[i] / (i - fp[i] + 1)) + 1);
			}
		}
	} while(n != 0);

	return 0;
}
