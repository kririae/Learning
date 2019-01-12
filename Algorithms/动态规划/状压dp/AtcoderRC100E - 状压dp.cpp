/*
要做这道题...先简单分析一下
dp稳了，但是难在怎么处理or
就是所谓的i or j <= k...
那么转移的时候就是看哪些新的可以加进来
打个表试试...
没用
这么做吧
int f[maxn], g[maxn];
用两个数组存
分别表示为k的时候，最大的俩
 */
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = (1 << 18) + 5;

int n, a[maxn], f[maxn], g[maxn], tmp[10];
int main()
{
	scanf("%d", &n);
	for (R int i = 0; i < (1 << n); ++i) scanf("%d", &a[i]), f[i] = a[i];
	for (R int j = 0; j < n; ++j)
	{
        for (R int i = 0; i < (1 << n); ++i)
			if((i | (1 << j)) != i) {
				tmp[1] = f[i], tmp[2] = g[i], tmp[3] = f[i | (1 << j)], tmp[4] = g[i | (1 << j)];
				sort(tmp + 1, tmp + 1 + 4);
				f[i | (1 << j)] = tmp[4], g[i | (1 << j)] = tmp[3];
			}
	}
	int ans = 0;
	for (R int i = 1; i < (1 << n); ++i)
		ans = max(ans, f[i] + g[i]), printf("%d\n", ans);
}