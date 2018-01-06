#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 205
/*-------------------------------------------------------------------
WARNING! WARNING! THERE IS NO SPECIAL JUDGE!
THERE IS NO SPECIAL JUDGE!
REPEAT AGAIN
THERE IS NO SPECIAL JUDGE!
ans先加上所有的实验收入
如果一个实验不做 亏x
如果一个实验做 亏y买设备
所以最小割模型很明显
亏最少就对了
---------------------------------------------------------------------*/
using namespace std;
const int INF = 99999999;
struct edge {
	int from, to, flow; //flow-可用流量  返向弧flow=0
	edge(int from_, int to_, int flow_) {
		from = from_;
		to = to_;
		flow = flow_;
	}
};
vector<edge> e;
int e_len = 0;
vector<int> node[N];
void addedge(int from, int to, int flow) {
	e.push_back(edge(from, to, flow));
	node[from].push_back(e_len++);
	e.push_back(edge(to, from, 0));
	node[to].push_back(e_len++);
}
//-----------------------------边模板-----------------------------------
int S, T;
int dis[N];//分层图
bool BFS() { //分层
	memset(dis, 0, sizeof(dis));
	queue<int> x;
	dis[S] = 1;
	x.push(S);

	while(!x.empty()) {
		int u = x.front();
		x.pop();

		for(int i = 0, len = node[u].size(); i < len; i++) {
			edge& ed = e[node[u][i]];

			if(dis[ed.to] != 0 || ed.flow == 0) continue;

			dis[ed.to] = dis[u] + 1;
			x.push(ed.to);
		}
	}

	if(dis[T] == 0) return false;

	return true;
}

int cur[N];
int DFS(int u, int a) { //多路增广  a-可行流
	if(u == T || a == 0) return a;

	int flow = 0;

	for(int i = cur[u], len = node[u].size(); i < len; i++) {
		edge& ed = e[node[u][i]];

		if(dis[ed.to] != dis[u] + 1 || ed.flow == 0) continue;

		int f = DFS(ed.to, min(a, ed.flow));

		if(f) {
			a -= f;
			flow += f;
			ed.flow -= f;
			e[node[u][i] ^ 1].flow += f;

			if(a == 0) return flow;
		}
	}

	return flow;
}

int Dinic() {
	int maxflow = 0;

	while(BFS()) {
		memset(cur, 0, sizeof(cur));
		maxflow += DFS(S, INF);
	}

	return maxflow;
}
//---------------------------Dinic模板---------------------------------
int n, m; //m-实验数
int YQ(int x) {
	return x + m;
}
//---------------------------编码函数----------------------------------
int money[N];
vector<int> sy[N];//实验
int did[N];

inline void read(int a) {
	char c = '1';
	int b = 0;
	bool flag = false;

	while(c != '\n') {
		c = getchar();

		if('0' <= c && c <= '9') {
			b = b * 10 + c - '0';
		} else if(c == ' ' || c == '\n') {
			if(!flag) {
				flag = true;
				money[a] = b;
			} else {
				sy[a].push_back(b);
				addedge(a, YQ(b), INF);
			}

			b = 0;
		}

	}
}

int main() {
	scanf("%d%d", &m, &n);

	while(getchar() != '\n');

	for(int i = 1; i <= m; i++) {
		read(i);
	}

	for(int i = 1; i <= n; i++) {
		scanf("%d", &money[YQ(i)]);
	}

	S = 0;
	T = m + n + 1;
	int ans = 0;

	for(int i = 1; i <= m; i++) {
		addedge(S, i, money[i]);
		ans += money[i];
	}

	for(int i = 1; i <= n; i++) {
		addedge(YQ(i), T, money[YQ(i)]); //ans-=money[YQ(i)];
	}

	int cost = Dinic();

	for(int i = 0, len = node[T].size(); i < len; i++) {
		edge& ed = e[node[T][i] ^ 1];

		if(ed.flow == 0) {
			did[ed.from - m] = 1;
		}
	}

	for(int i = 1; i <= m; i++) {
		bool flag = true;

		for(int j = 0, len = sy[i].size(); j < len; j++) {
			if(did[sy[i][j]] == 0) {
				flag = false;
				break;
			}
		}

		if(flag) {
			printf("%d ", i);
		}
	}

	printf("\n");

	for(int i = 1; i <= n; i++) {
		if(did[i]) {
			printf("%d ", i);
		}
	}

	printf("\n%d", ans - cost);
	return 0;
}
