#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int ti[2005];
int dis[2005][2005];

int main() {
    for (int i = 0; i < 2005; ++i) {
        for (int j = 0; j < 2005; ++j) {
            dis[i][j] = 1e7;
        }
    }
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> ti[i];
	}
	for (int k = 0; k < m; ++k) {
		int i, j, w;
		cin >> i >> j >> w;
		dis[j][i] = dis[i][j] = w;
	}
	for (int i = 0; i < n; ++i) 
		dis[i][i] = 0;
	int k = 0;
	cin >> q;
	for (int qwq = 0; qwq < q; ++qwq) {
		int x, y, t;
		cin >> x >> y >> t;
		while(ti[k] <= t) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
			++k;
		}
		if (dis[x][y] == 1e7 || ti[x] > t || ti[y] > t) {
			cout << -1 << endl;
		}
		else {
			cout << dis[x][y] << endl;
		}
	}
	return 0;
}
