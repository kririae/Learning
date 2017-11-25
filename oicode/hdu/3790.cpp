#include <bits/stdc++.h>
using namespace std;
struct edge {
	int to, d, p;
	edge(int t, int d, int p) {
		to = t, d = v, p = p;
	}
	bool operator < (const edge (&a)) const {
		if(this->d == a.d) return this->p < a.p;
		return this->d < a.d;
	}
};
int n, m;
int dist[1005], price[1005];
vector<edge> graph[1005];
bool white[1005];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	while(true) {
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		memset(dist, 1e9, sizeof(dist));
		memset(price, 0, sizeof(price));
		for (int i = 0; i < m; ++i) {
			int a, b, d, p;
			cin >> a >> b >> d >> p;
			graph[a].push_back(edge(b, d, p));
			graph[b].push_back(edge(a, d, p));
		}
		int s, t;
		cin >> s >> t;
		white[s] = true;
		for(int i = 0; i < n; ++i) {
			int mind = 1e9, minp = 1e9;
			int minindex = 0;
			for(int j = 0; j < graph[i].size(); ++j) {
				if(!white[j] && graph[i][j].d < minnum && graph[i][j].p < minp) {
					minindex = j;
				}
			}
			white[minindex] = true;
			for(int j = 0; j < graph[minindex].size(); ++j) {
				if(dist[minindex] + graph[minindex][j].d < dist[j]) {
					dist[j] = dist[minindex] + graph[minindex][j].d;
					price[j] = price[minindex] + graph[minindex][j].p;
				}
			}
		}
		cout << dist[e] << " " price[e] << endl;
	}
}