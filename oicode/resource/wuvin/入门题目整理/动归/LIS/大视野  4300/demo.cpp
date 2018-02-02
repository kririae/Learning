#include<cstdio>
#include<iostream>
using namespace std;
/*
此题与最长上升子序列有异曲同工之妙
依旧动归
nlogn
dp数组为第j位有1的最长长度 (1<=j<=30)
*/
int dp[32];
int n;
int a[100005];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		int p = a[i];
		int t = 0;
		for(int j = 1; j <= 31; j++, p >>= 1) {
			if(p & 1) {
				t = max(t, dp[j] + 1);
			}
		}
		p = a[i];
		for(int j = 1; j <= 31; j++, p >>= 1) {
			if(p & 1) {
				dp[j] = t;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= 31; i++) {
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}
