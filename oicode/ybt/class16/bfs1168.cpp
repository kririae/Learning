#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int go[4][2] = {{2, 1},
	{ 1, 2},
	{-1, 2},
	{-2, 1}
};
bool map[402][402];
int mapi[402][402];
int main() {
	int n, m;
	memset(map, false, sizeof(map));
	memset(mapi, 0, sizeof(mapi));
	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> mapi[i][j];

	map[1][1] = true;

	for(int i = 1; i <= m; ++i) {
		for(int j = 2; j <= n; ++j) {
			int maxn = -1;

			for(int k = 0; k <= 3; ++k) {
				int go_x = i + go[k][0];
				int go_y = j + go[k][1];

				if(go_x < 1 || go_y < 1 || go_x > m || go_y > n) continue;

				if(!map[go_x][go_y]) continue;

				if(mapi[go_x][go_y] > maxn) maxn = map[go_x][go_y];
			}

			if(maxn > 0) {
				mapi[i][j] += maxn;
				map[i][j] = true;
			}
		}
	}

	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j)
			cout << mapi[i][j];

		cout << endl;
	}

	cout << mapi[m][n];
}
