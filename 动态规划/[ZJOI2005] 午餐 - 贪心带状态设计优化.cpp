// by kririae
#include <bits/stdc++.h>

using namespace std;

namespace ZJOI2005
{
/*
实现思路
贪心 + dp
# 贪心
## 贪心算法：
按照$b[i]$排序
## 贪心证明：
对于排序后的序列$S$中的某一个人$S_i$
他吃饭的总时间$t[i] = \sum_{j = 1}^{i}{a[j]} + b[i]$
所以当前队伍的集合时间是$max{t[i]}$
假如说有一个更优算法,在处理$S_i$的时候首先处理$S_{i + 1}$
假如说最大值在$t[i]$和$t[i + 1]$中取得
设$s[i] = \sum{j = 1}^{i}{a[i]}$
很明显$s[i + 1] > s[i]$
那么之前$t[i + 1] = max{s[i] + b[i], s[i + 1] + b[i + 1]}$
变为了$t[i + 1] = max{s[i] + b[i + 1], s[i + 1] + b[i]}$
显然第二者 > 第一者，所以贪心算法（交换前的算法）最优。
# DP
状态设计$f[i][j]$表示前$i$个人安排在第一个队列，打饭总时间为$j$所花费的最小时间。
显然，决策有两个，把当前这个人放在第一个队列里和第二个队列里。
$$f[i][j] = min{max{f[i - 1][j - a[i]], j + b[i]}, max{f[i - 1][j], s[i] - j + b[i]}}$$
简单解释一下，第$f[i - 1][j - a[i]]$表示这个是放在第一个队列里的，同理，$f[i - 1][j]$表示这个放在第二个队列里
$j + b[i]$表示转移后的总时间，放在第二个队列里的话，有一个类似“守恒”的思想。
$s[i] - j$表示在第二个队列里打饭的总时间，$s[i] - j + b[i]$的意义就是总时间啦。
 */

const int maxn = 203;

struct Person
{
	int a, b;
	Person() {}
	Person(int ai, int bi) : a(ai), b(bi) {} 

	bool operator < (Person val) const 
	{ return b == val.b ? a < val.a : b > val.b; }
};

int n, s[maxn], f[maxn][maxn * maxn];
Person g[maxn];

inline void solve()
{
	memset(f, 0x3f, sizeof(f));
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> g[i].a >> g[i].b;
	
	sort(g + 1, g + 1 + n);
	
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + g[i].a;
		
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = s[i]; j >= 0; --j)
		{
			if(j - g[i].a >= 0) f[i][j] = min(f[i][j], max(f[i - 1][j - g[i].a], j + g[i].b));
			f[i][j] = min(f[i][j], max(f[i - 1][j], s[i] - j + g[i].b));
		}

	int ans = 1e9;
	for (int i = 0; i <= s[n]; ++i)
		ans = min(ans, f[n][i]);
	cout << ans << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ZJOI2005::solve();
	return 0;
}