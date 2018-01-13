#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
bool res[100][100];
void printOut()
{
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cout << res[i][j];
		}

		cout << endl;
	}

	cout << endl;
}
const int go[4][2] = {{-1,  0},
	{ 1,  0},
	{ 0,  1},
	{ 0, -1}
};
void dfs(int x, int y)
{
	res[x][y] = false;

	for(int i = 0; i < 3; ++i)
		if(x + go[i][0] >= 0 && x + go[i][0] <= n - 1 && y + go[i][1] >= 0 && y + go[i][1] <= m - 1)
			if(res[x + go[i][0]][y + go[i][1]]) dfs(x + go[i][0], y + go[i][1]);

	return;
}
int main()
{
	freopen("bfs1329.in", "r", stdin);
	memset(res, false, sizeof(res));
	cin >> n >> m;

	for(int i = 0; i < n; ++i) {
		char c[100];
		scanf("%s", c);

		for(int j = 0; j < m; ++j)
			res[i][j] = (c[j] != '0');
	}

	int summ = 0;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(res[i][j] == true) {
				summ += 1;
				dfs(i, j);
				printOut();
			}

	cout << summ;
	fclose(stdin);
	return 0;
}
