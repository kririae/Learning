#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int data[405][405];
bool mmp[405][405];
int n, m;
const int go[4][2] = {{2, 1},
	{ 1, 2},
	{-1, -2},
	{-2, -1}
};
int main() {
	// freopen("bfs1168.in", "r", stdin);
	cin >> n >> m;
	// ini
	memset(mmp, false, sizeof(mmp));

	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> data[i][j];

	mmp[1][1] = true;

	for(int i = 1; i <= m; ++i) {
		for(int j = 2; j <= n; ++j) {
			int maxn = -1;

			for(int k = 0; k < 4; ++k) {
				int x = i + go[k][0];
				int y = j + go[k][1];

				if(x < 1 || y < 1 || x > m || y > n) continue;

				if(!mmp[x][y]) continue;

				if(data[x][y] > maxn) maxn = data[x][y];
			}

			if(maxn >= 0) {
				data[i][j] += maxn;
				mmp[i][j] = true;
			}
		}
	}

	if(mmp[m][n]) cout << data[m][n];
	else cout << 0;

	// fclose(stdin);
}
