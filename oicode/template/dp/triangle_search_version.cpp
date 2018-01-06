#pragma GCC optimize(3)
/*
 * by kriaeth 2017/11/8/20:16
 * dpA search_version
 */
#include <bits/stdc++.h>
using namespace std;
int triangle[100][100] = {0}, n;
int ans_or = 0, ans_red = 0, ans_memo = 0;
int f_or[100][100] = {0}, f_red[100][100] = {0}, f_memo[100][100] = {0};
inline void ordinary_search(int x, int y, int value) {
	// dfs 正常搜索
	value += triangle[x][y];

	if (x > n || y > n)
		return;

	if (value > ans_or)
		ans_or = value;

	ordinary_search(x + 1, y, value);
	ordinary_search(x + 1, y + 1, value);
}
inline void redundancy_search(int x, int y, int value) {
	// 冗余搜索 俗称剪枝
	value += triangle[x][y];

	if (value <= f_red[x][y])
		return;

	f_red[x][y] = value;

	if (x == n) {
		if (value > ans_red)
			ans_red = value;

		return;
	}

	redundancy_search(x + 1, y, value);
	redundancy_search(x + 1, y + 1, value);
}
inline void memory_search(int x, int y, int value) {
	// 记忆化搜索
	value += triangle[x][y];

	if (value <= f_memo[x][y])
		return;

	f_memo[x][y] = value;

	if (x == n) {
		if (value > ans_memo)
			ans_memo = value;

		return;
	}

	memory_search(x + 1, y, value);
	memory_search(x + 1, y + 1, value);
}
int main() {
	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 1; ++j)
			cin >> triangle[i][j];

	ordinary_search(1, 1, 0);
	redundancy_search(1, 1, 0);
	memory_search(1, 1, 0);
	cout << "ordinary: " << ans_or << endl;
	cout << "redundancy: " << ans_red << endl;
	cout << "memo:" << ans_memo << endl;
	return 0;
}
