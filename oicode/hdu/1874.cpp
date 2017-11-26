#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n, m;
int mp[maxn][maxn]{0x7fffffff};
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	while(cin >> n >> m) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i == j) mp[i][j] = 0;
				else mp[i][j] = 0x7fffffff;
			}
		}
		for(int i = 0; i < m; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			mp[x][y] = min(mp[x][y], z);
			mp[y][x] = min(mp[y][x], z);
		}
		int s, t;
		cin >> s >> t;
		for(int k = 0; k < n; ++k) {
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < n; ++j) {
					mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
				}
			}
		}
		cout << mp[s][t] << endl;
	}
	return 0;
}
