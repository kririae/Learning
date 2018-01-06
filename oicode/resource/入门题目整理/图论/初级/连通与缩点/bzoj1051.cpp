#include<cstdio>
#include<vector>
#include<stack>
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

vector<edge> e2;
int e2_len;//e的转置
vector<int> node2[10005];
void addedge(int from, int to, int len) { //单向
	e.push_back(edge(from, to, len));
	node[from].push_back(e_len++);
	e2.push_back(edge(to, from, len));
	node2[to].push_back(e2_len++);
}
/*-------------拓扑板-----------*/
int tp[10005];
int len_tp = 1;

int vis[10005];
void DFS1(int u) { //访问所有指向自己的点，然后把他们删掉，最后删自己；
	vis[u] = 1;

	for(int i = 0, len = node2[u].size(); i < len; i++) {
		edge& ed = e2[node2[u][i]];

		if(vis[ed.to] == 0) DFS1(ed.to);
	}

	tp[len_tp++] = u;
}
/*-------------下面是判断连通块-----------------*/
int lt[10005];
int cnt_lt = 1;
void DFS2(int u, int num) {
	lt[u] = num;

	for(int i = 0, len = node[u].size(); i < len; i++) {
		edge& ed = e[node[u][i]];

		if(lt[ed.to] == 0) DFS2(ed.to, num);
	}
}
/*------------------------------*/
int n, m;
void init() {
	scanf("%d%d", &n, &m);

	for(int f, t, i = 1; i <= m; i++) {
		scanf("%d%d", &f, &t);
		addedge(f, t, 0);
	}
}

int ele[10005];//标号为连通分量
int du[10005];
int all = 0;
int main() {
	init();

	for(int i = 1; i <= n; i++) { //生成反向拓扑序
		if(vis[i] == 0)
			DFS1(i);
	}

	for(int i = n; i >= 1; i--) {
		if(lt[tp[i]] == 0) {
			DFS2(tp[i], cnt_lt++);
		}
	}

	all = cnt_lt - 1;
	int ans = 0;
	int num = 0;

//还是检查边靠谱
	for(int i = 0, len = e.size(); i < len; i++) {
		edge &ed = e[i];

		if(lt[ed.to] != lt[ed.from]) {
			du[lt[ed.from]]++;
		}
	}

	for(int i = 1; i <= n; i++) ele[lt[i]]++;

	int ans2 = 0;

	for(int i = 1; i <= all; i++) {
		if(du[i] == 0) {
			num++;
			ans = i;
		}
	}

	if(num == 1) {
		printf("%d", ele[ans]);
	} else {
		printf("0");
	}

	return 0;
}
