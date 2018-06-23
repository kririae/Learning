/*
虽然是简单dp，但是分析过程并不是很简单
首先思考，如何成本最小化
当前已经排好序的就不用动了，只动没有排好序的，这样成本最小化了
什么是排序好的呢？连续的一段+1的
然后我们把两段排好的组合起来，能够组合的情况，只有右段的最小值 = 左的最大值 + 1
于是我们就把问题转化成了
求一段，最长，连续上升，的子序列。
这个问题递推就好，注意是按照“数”来进行递推
 */
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, ans, a[maxn], f[maxn];

int main()
{
	scanf("%d", &n);
	for (R int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (R int i = 1; i <= n; ++i)
		f[a[i]] = f[a[i] - 1] + 1, ans = max(ans, f[a[i]]);
	printf("%d", n - ans);
	return 0;
}