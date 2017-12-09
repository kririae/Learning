#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct edge {
	int to, val;
	edge(int a, int b): to(a), val(b) {}
};

const int maxn = 1e6;
int t, n, m, k, p, d;
// temp
int ai, bi, ci;
vector<edge> graph[maxn];
queue<int> q;
int dis[maxn], countt[maxn];
bool vis[maxn];

inline ll read() {
	ll res = 0;
	char c;
	while(!isspace(c = getchar()) && isdigit(c)) 
		res = res * 10 + (c - '0');
	return res;
}

inline int spfaf(int s, int e) {
	for (int i = 0; i <= n + 5; ++i) dis[i] = 1e9;
	q.push(s);
	vis[s] = true, dis[s] = 0;
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		vis[curr] =false;
		for (int i = 0; i < graph[curr].size(); ++i) {
			if (dis[graph[curr][i].to] > dis[curr] + graph[curr][i].val) {
				dis[graph[curr][i].to] = dis[curr] + graph[curr][i].val;
				if (!vis[graph[curr][i].to]) {
					vis[graph[curr][i].to] = true;
					q.push(graph[curr][i].to);
				}
			}
		}
	}
	return dis[e];
}

inline void spfa(int s, int e) {
	for (int i = 0; i <= n + 5; ++i) {
		dis[i] = 1e9;
		vis[i] = false;
	}
	q.push(s); vis[s] = true;
	dis[s] = 0;
	while (!q.empty()) {
	    int curr = q.front(); q.pop();
		vis[curr] =false;
		for (int i = 0; i < graph[curr].size(); ++i) {
			if(dis[graph[curr][i].to] > dis[curr] + graph[curr][i].val) {
				dis[graph[curr][i].to] = dis[curr] + graph[curr][i].val;
				if(dis[graph[curr][i].to] <= d + k) {
					++countt[graph[curr][i].to];
					countt[graph[curr][i].to] %= p;
				}
				if(!vis[graph[curr][i].to]) {
					vis[graph[curr][i].to] = true;
					q.push(graph[curr][i].to);
				}
			}
		}
	}
}

int main() {
	freopen("in.in", "r", stdin);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
	while (--t) {
		cin >> n >> m >> k >> p;
		// n = read(), m = read(), k = read(), p = read();
		for (int i = 0; i < m; ++i) {
			// ai = read(), bi = read(), ci = read();
			cin >> ai >> bi >> ci;
			graph[ai].push_back(edge(bi, ci));
			graph[bi].push_back(edge(ai, ci));
		}
		
		d = spfaf(1, n);
	    spfa(1, n);
	    cout << countt[n] << endl;	    
	    cout << endl << endl;
	}
	fclose(stdout);
	return 0;
}