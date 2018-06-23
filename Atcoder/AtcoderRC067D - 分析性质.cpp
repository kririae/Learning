/*
分析
首先发现，我们要走完所有的点
我们拆分成简化版，只有三个点
我们可以从第一个跳到第二个，然后走到第三个，各种方法点点点
但是，如果跳到第三个的话，我们还需要走回第二个，或者跳回第二个
枚举一下方案
我们跳到第三个，然后跳回第二个，跳了两次
我们跳到第二个，然后跳到第三个，依然是跳了两次。
我们走到第二个，然后跳到第三个 / 走到第三个，
我们跳到第二个，然后跳到第三个 / 走到第三个
这样，总和是不变的
于是，为了简化代码复杂度（大雾
我们这样看，对于每一步决策，采取贪心策略，如果能够跳少的话，就跳一跳
如果走少的话，就走一走。
还原到原版，一个道理。
ATC的出题人的脑洞太大了...
很喜欢ATC的风格，可以很大程度地节约做题时间。
 */
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
int n, a[maxn];
ll A, B, ans;

int main()
{
	scanf("%d%d%d", &n, &A, &B);
	for (R int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (R int i = 1; i < n; ++i)
		ans += min(B, (a[i + 1] - a[i]) * A);
	printf("%lld", ans);
}