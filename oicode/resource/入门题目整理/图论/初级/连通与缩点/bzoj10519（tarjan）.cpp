#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
/*-------正常图模板-------*/
const int INF = 999999;
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
/*-------------下面是判断连通块-----------------*/
int lt[10005], vis[10005]; //储存各点连通分量的标号,第一次访问的时间戳
int lt_cnt, clk_cnt; //时钟 0
int round[10005], mint[10005]; //mint-可以到达的最低的时间戳
stack<int> x;
int DFS(int u) { //缩点，返回可以到达的时间最小点
	mint[u] = vis[u] = clk_cnt++;
	int ret = vis[u];
	x.push(u);

	for(int i = 0, len = node[u].size(); i < len; i++) {
		edge &ed = e[node[u][i]];

		if(lt[ed.to] != 0) continue; //这点很重要 即该点未完成计算

		if(vis[ed.to] != 0) {
			ret = min(ret, mint[ed.to]); //注意是mint[ed.to]
		} else {
			int t = DFS(ed.to);
			ret = min(ret, t);
		}
	}

	if(ret == vis[u]) {
		int p = 0;
		lt_cnt++;

		do {
			p = x.top();
			x.pop();
			lt[p] = lt_cnt;
		} while(p != u);
	}

	mint[u] = ret;
	return ret;
}
/*------------------------------*/
int n, m;
void init() {
	clk_cnt = lt_cnt = 0;
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
		if(lt[i] == 0)
			DFS(i);
	}

	all = lt_cnt;
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
