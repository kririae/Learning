// failed
#include <bits/stdc++.h>
using namespace std;
double value[2005][2005], dis[2005];
bool white[2005];
int main()
{
	memset(value, 0, sizeof(value));
	memset(dis, 0, sizeof(dis));
	int n, m;
	cin >> n >> m;

	for (int x, y, i = 1; i <= m; ++i) {
		double z;
		cin >> x >> y >> z;
		value[x][y] = value[y][x] = (100 - z) / 100;
	}

	int a, b;
	cin >> a >> b;

	for(int i = 1; i <= n; ++i) dis[i] = value[a][i];

	dis[1] = 0, white[1] = true;

	for(int i = 1; i <= n; ++i) {
		int minn = 0, minindex = 0;

		for(int j = 1; j <= n - 1; ++j) {
			if(!white[j] && dis[j] >= minn) {
				minindex = j;
				minn = dis[j];
			}
		}

		white[minindex] = true;

		if(minindex == b || minindex == 0) break;

		for(int j = 1; j <= n; ++j) {
			if(!white[j] && dis[minindex] * value[minindex][j] > dis[j]) dis[j] = dis[minindex] * value[minindex][j];
		}
	}

	printf("%.8lf", 100 / dis[b]);
	return 0;
}
