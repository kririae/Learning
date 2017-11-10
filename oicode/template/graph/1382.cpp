#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const ll maxn = 100005;
typedef long long ll;
struct edge {
    ll to;
    ll value;
    edge(ll a, ll b) {
        to = a, value = b;
    }
}
vector<edge> graph[maxn];
queue<ll> proc;
ll dist[maxn];
void add_edge(ll from, ll to, ll value) {
    graph[from].push_back(edge(to, value));
}
void SPFA() {
    proc.push(1);
    dist[1] = 0;
    while(!proc.empty()) {
        ll current = proc.front();
        proc.pop();
        for(int i = 0; i < graph[current].size(); ++i) {
            if(dist[graph[current][i].to] > dist[current] + graph[current][i].value) {
                dist[graph[current][i].to] = dist[current] + graph[current][i].value;
                proc.push(graph[current][i].to);
            }
        }
    }
}
ll main() {
    ll n, m;
    cin >> n >> m;
    memset(dist, LLONG_MAX, sizeof(dist));
    for(ll ai, bi, ci, i = 1; i <= n; ++i) {
        scanf("%d%d%d", &ai, &bi, &ci);
        add_edge(ai, bi, ci);
    }
    cout << dist[n] << endl;
}