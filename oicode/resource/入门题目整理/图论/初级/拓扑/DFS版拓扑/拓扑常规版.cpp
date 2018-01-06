#include<cstdio>
#include<vector>
using namespace std;
const int INF = 999999;
/*-------正常图模板-------*/
struct edge {
	int from, to, dis;
	edge(int fr, int t, int di): from(fr), to(t), dis(di) {}
};
vector<edge> e;
int e_len;
vector<int> node[10005];
void addedge(int from, int to, int len) { //单向
	e.push_back(edge(from, to, len));
	node[from].push_back(e_len++);
}
/*-------------拓扑板-----------*/
int vis[10005];
int rd[10005];
void tp(int u) {
	printf("%d ", u);
	rd[u] = -1;
	vis[u] = 1;

	for(int i = 0, len = node[u].size(); i < len; i++) {
		edge& ed = e[node[u][i]];
		rd[ed.to]--;

		if(rd[ed.to] == 0) tp(ed.to);
	}
}
/*------------------------------*/
int n, m;
void init() {
	scanf("%d", &n);

	for(int i = 1, c; i <= n; i++) {
		do {
			scanf("%d", &c);

			if(c != 0) {
				addedge(i, c, 0);
				rd[c]++;
			} else {
				break;
			}
		} while(1);
	}

	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0 && rd[i] == 0)
			tp(i);
	}
}

int ele[10005];//标号为连通分量
int du[10005];
int all = 0;
int main() {
	init();
	return 0;
}
