#include <bits/stdc++.h>
using namespace std;
struct edge {
	int to, val;
	edge(int a, int b) {to = a, val = b;}
};
const int maxn = 1e4 + 5;
int n, s, dis[maxn][maxn], maxd;
int maxs, maxe;
int linee[maxn];

inline int read() {
	char c; int res;
	while(!isspace(c = getchar()) && isdigit(c)) 
		res = res * 10 + c - '0';
	return res;
}

inline void init() {
    cin >> n >> s;
    for (int i = 0; i <= n + 5; ++i) 
    for (int j = 0; j <= n + 5; ++j) 
        dis[i][j] = 1e9;
    // n = read(); s = read();
	for (register int i = 0; i < n; ++i) {
		register int a, b, c;
		cin >> a >> b >> c;
		// a = read(), b = read(), c = read();
		dis[a][b] = dis[b][a] = c;
	} 
}

inline void floyd() {
    for (register int k = 1; k <= n; ++k) 
    for (register int i = 1; i <= n; ++i) 
    for (register int j = 1; j <= n; ++j) 
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

inline int solveD() {
	int maxn = 0;
	for (register int i = 1; i <= n; ++i) {
		for (register int j = 1; j <= n; ++j) {
			if (dis[i][j] != 1e9 && dis[i][j] > maxn) 
				maxn = dis[i][j], maxs = i, maxe = j;
		}
	}
}

inline void solve() {
	// 下面这一点是在题解里看到的清奇思路...很强...
	int flag = 0;
	for (register int i = 1; i <= n; ++i) {
		if (dis[maxs][i] + dis[maxe][i] == dis[maxs][maxe]) {
			linee[++flag] = i;
		}
	}
	int ans = 1e9;
	for (register int i = 1; i <= flag; ++i) {
		for (register int j = 1; j <= flag; ++j) {
			if(dis[linee[i]][linee[j]] <= s) {
			    int maxn = 0;
				for (register int k = 1; k <= n; ++k) {
					maxn = max(maxn, dis[linee[i]][k] + dis[linee[j]][k] - dis[linee[i]][linee[j]]);
				}
				ans = min(ans, maxn);
			}
		}
	}
	cout << ans / 2 << endl;
}

int main() {
    init();
    floyd();
    maxd = solveD();
    solve();
	return 0;
}