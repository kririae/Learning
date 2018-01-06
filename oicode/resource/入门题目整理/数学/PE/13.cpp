#include<bits/stdc++.h>
#define LL long long
/*朴素高精加
有人直接全换成double变为一个小于十的小数
double加。。。
或者用excel*/
using namespace std;
int a[152][102];
LL ans = 0;
int main() {
	int n = 100, m = 50;

	for(int i = 1; i <= n; i++) {
		for(int j = 21; j <= m + 20; j++) {
			char c = getchar();

			while(c < '0' || c > '9') c = getchar();

			a[i][j] = c - '0';
		}
	}

	for(int j = m + 20, sum = 0; j >= 1; j--) {
		for(int i = 1; i <= n; i++) {
			sum += a[i][j];
		}

		a[n + 1][j] = sum % 10;
		sum /= 10;
	}

	for(int i = 1; i <= 70; i++)
		printf("%d", a[n + 1][i]);

	return 0;
}
