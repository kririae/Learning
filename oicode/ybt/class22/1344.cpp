#include <bits/stdc++.h>
using namespace std;
int graph[105][105] = {0};
int value[105][105];
int main()
{
	int n, m, a, b;
	cin >> n >> m;

	for(int x, y, z, i = 1; i <= m; ++i) {
		cin >> x >> y >> z;
		graph[x][y] = graph[y][x] = z;
	}

	cin >> a >> b;

	return 0;
}
