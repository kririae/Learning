// by kririae
#include <iostream>
#include <cstring>

using namespace std;

namespace Coins
{
const int maxn = 105;
const int maxm = 1e5 + 5;
/*
男人八题之一。
这题搞细节，贪心优化dp
我们发现N很小，所以优化的时候时间复杂度一定会带上N（大雾
如果仔细看英文会发现，本题关注的是可行性而不是最优解
蛇皮操作开始了，我们需要一个g[maxn]数组
g[j]表示用到放第i种硬币的时候，f[j]为1最少用多少枚i硬币。
 */

int n, m, c[maxn], a[maxn], f[maxm], g[maxm];

inline void solve()
{
	while(cin >> n >> m && n && m)
	{
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
			cin >> c[i];

		int ans = 0;
		f[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			memset(g, 0, sizeof(g));
			for (int j = a[i]; j <= m; ++j)
				// 如果f[j]没有被到达过，并且可以由f[j - a[i]]转移过来，并且当前硬币还可以用。
				// 喂喂喂这是dp套贪心套dp啊！
				if(!f[j] && f[j - a[i]] && g[j - a[i]] < c[i])	
					f[j] = 1, g[j] = g[j - a[i]] + 1, ++ans;
		}

		cout << ans << endl;
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	Coins::solve();
}