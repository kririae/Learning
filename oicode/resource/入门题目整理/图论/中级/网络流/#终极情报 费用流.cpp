#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
using namespace std;
const long double eps = 1e-10;
const int INF = 1000;
int n, k;
int S, T;
//费用流
struct edge {
	int from, to, flow, cap;
	double cost;
	edge(int f, int t, int fl, double co, int capture) {
		from = f;
		to = t;
		flow = fl;
		cap = capture;
		cost = co;
	}
};
vector<edge> e;
int len = 0;
vector<int> nodes[305];

void addedge(int from, int to, int flow, int cap, double cost) {
	e.push_back(edge(from, to, flow, cost, cap));
	nodes[from].push_back(len++);
	e.push_back(edge(to, from, -flow, 1 / cost, 0));
	nodes[to].push_back(len++);
}

int from[305];
long double distan[305];
int a[305];
bool inq[305];
long double pow(long double x, int aa) {
	long double ret = 1;

	for(int i = 1; i <= aa; i++) ret *= x;

	return ret;
}
long double abs(long double aa) {
	if(aa < 0) return -aa;

	return aa;
}



long double feiyong(int start, int end, int &flow) {
	memset(from, 0, sizeof(from));

	for(int i = 1; i <= n; i++) distan[i] = 0;

	distan[301] = 0;
	distan[1] = 1;
	memset(a, 0, sizeof(a));
	//spfa
	queue<int> x;
	x.push(start);
	distan[start] = 1;
	inq[start] = true;
	a[start] = flow;

	while(!x.empty()) {
		int u = x.front();
		x.pop();
		inq[u] = false;

		if(distan[u] < eps) continue;

		for(int i = 0, len = nodes[u].size(); i < len; i++) {
			edge& ed = e[nodes[u][i]];

			if(ed.cap <= ed.flow || inq[ed.to]) continue;

			if(distan[ed.to] + eps < distan[u]*ed.cost) {
				distan[ed.to] = distan[u] * ed.cost;
				x.push(ed.to);
				inq[ed.to] = true;
				from[ed.to] = nodes[u][i];
				a[ed.to] = min(a[u], ed.cap - ed.flow);
			}
		}
	}

	if(a[end] == 0 || distan[end] < eps) return -1;

	int p = end;

	while(p != start) {
		e[from[p]].flow += a[end];
		e[from[p] ^ 1].flow -= a[end];
		p = e[from[p]].from;
	}

	flow -= a[end];
	return pow(distan[end], a[end]);
}

double as[305];//可靠性
int am[305];//传递数据量
int connect[305];
void init() {
	S = 0;
	T = 301;
	scanf("%d%d", &n, &k);

	for(int i = 1; i <= n; i++) {
		scanf("%lf", &as[i]);
	}

	for(int i = 1; i <= n; i++) {
		scanf("%d", &am[i]);
		addedge(S, i, 0, am[i], as[i]);
	}

	for(int i = 1; i <= n; i++) {
		scanf("%d", &connect[i]);

		if(connect[i] == 1)
			addedge(i, T, 0, INF, 1);
	}

	int f, t, m;
	double s;

	while(scanf("%d%d", &f, &t)) {
		if(f == -1) break;

		scanf("%lf%d", &s, &m);
		addedge(f, t, 0, m, s);
		addedge(t, f, 0, m, s);
	}
}
long double ans = 1;
int ll;
int main() {
	init();//S T

	ll = k; //需传递流量

	while(a != 0) {
		ans *= feiyong(S, T, ll);

		if(ans < eps) break;
	}

	if(ans < 0) {
		printf("0");
	} else if(abs(1 - ans) < eps) {
		printf("1");
	} else {
		printf("%.5llg", ans);
	}

	return 0;
}
