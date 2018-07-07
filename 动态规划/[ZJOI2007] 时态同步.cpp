// 屈服于题解
/*
一开始的构思就没有问题
但是
这tmd是无向图
第二点，这tmd的为啥我调不出来
题解真香
题目思路还是很简单的
题解这位把最大值放到了边权里，我虽然不想这么写，但是题解这么写.jpg
完蛋了，我代码能力太差了
 */
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

namespace BZOJ1060
{
const int maxn = 500005;

int n, s, a, b, c, t, maxv, f[maxn];
vector<pair<int, int> > son[maxn];
ll ans;

inline int dp(int k, int fa)
{
	for (R int i = 0; i < son[k].size(); ++i)
	    if(son[k][i].first != fa) dp(son[k][i].first, k);
	for (R int i = 0; i < son[k].size(); ++i)
	    if(son[k][i].first != fa) f[k] = max(f[k], son[k][i].second);
	for (R int i = 0; i < son[k].size(); ++i)
	    if(son[k][i].first != fa) ans += f[k] - son[k][i].second;
	for (R int i = 0; i < son[fa].size(); ++i)
	    if(son[fa][i].first == k) son[fa][i].second += f[k];
}

inline void solve()
{
    scanf("%d%d", &n, &s);
    for (R int i = 1; i < n; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        son[a].push_back(make_pair(b, c));
        son[b].push_back(make_pair(a, c));
	}
	dp(s, 0);
	cout << ans << endl;
}
}

int main()
{
    return BZOJ1060::solve(), 0;
} 