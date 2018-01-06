// failed?
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
struct edge {
	int from, to, d, p;
};
vector<edge> p;
int n, m, s, t;
int dist[1005], price[1005];
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
			edge curr;
			cin >> curr.from >> curr.to >> curr.d >> curr.p;
			p.push_back(curr);
			int tempo = curr.from;
			curr.from = curr.to;
			curr.to = curr.from;
			p.push_back(curr);
		}

		cin >> s >> t;
		white[s] = true;
		dist[s] = 0;

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				edge &curr = p[j];

				if(dist[curr.from] + curr.d < dist[curr.to]) {
					dist[curr.to] = dist[curr.from] + curr.d;
					price[curr.to] = price[curr.from] + curr.p;
				}

				if(dist[curr.from] + curr.d == dist[curr.to]) {
					price[curr.to] = min(price[curr.from] + curr.p, price[curr.to]);
				}
			}
		}

		cout << dist[t] << " " << price[t] << endl;
	}
}
