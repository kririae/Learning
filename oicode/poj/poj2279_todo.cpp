// 线性DP
// POJ2279
// AUTHOR: KRIRIAE
#include <bits/stdc++.h>

/*
这么思考，每安排一个新学生的时候，需要考虑横行当前位之前的和当前纵行之前的。
状态是f[a1][a2][a3][a4][a5] 表示在每一排分别站了a1, a2, a3, a4, a5个人时的方案最大值。
出发点是f[0][0][0][0][0]
要到达f[n1][n2][n3][n4][n5]
*/

using namespace std;

namespace kririae
{
const int maxn = 31;
unsigned long long f[maxn][maxn][maxn][maxn][maxn];
int a[6], n, k;
inline void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) cin >> a[i]
	f[0][0][0][0][0] = 1; // -> f[a[1]][a[2]][a[3]][a[4]][a[5]];
	
	cout << f[a[1]][a[2]][a[3]][a[4]][a[5]] << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	kririae::solve();
	return 0;
}