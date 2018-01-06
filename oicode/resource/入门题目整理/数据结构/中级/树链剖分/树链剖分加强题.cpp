/*-----------------------------------------------------*//*
zjoi 2015:幻想乡战略游戏
大视野3924
最好用long long
首先O(n)转为有根树
O(n*n)各互相点LCA
O(n*n)初始化相互距离

每一轮计算一个点O(n)
n个点O（n^2）

总共(n*n*n)
/*-------------------------------------------------------*/
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n, q;
struct edge {
	int from, to, cost;
	edge(int fr, int to_, int cost_) {
		from = fr;
		to = to_;
		cost = cost_;
	}
};
vector<edge> e;
int len;
struct tree_nodes {
	//int father;
	vector<int> to;
	int sol;//the number of solders
	int dis[110];//到个点距离
} map[110];
long long mincost;

void work(int u) {
	queue<int> x;
	x.push(u);

	while(!x.empty()) {
		int v = x.front();
		x.pop();

		for(int i = 0, lens = map[v].to.size(); i < lens; i++) {
			edge& ed = e[map[v].to[i]];

			if(ed.to == u) continue;

			if(map[u].dis[ed.to] == 0) {
				map[u].dis[ed.to] = map[u].dis[ed.from] + ed.cost;
				x.push(ed.to);
			}
		}
	}
}
void init() {
	scanf("%d%d", &n, &q);

	for(int f, t, c, i = 1; i <= n - 1; i++) {
		scanf("%d%d%d", &f, &t, &c);
		e.push_back(edge(f, t, c));
		map[f].to.push_back(len++);
		e.push_back(edge(t, f, c));
		map[t].to.push_back(len++);
	}

	for(int i = 1; i <= n; i++) {
		work(i);
	}
}

void recount() {
	long long fy = 0;
	mincost = 1;
	mincost <<= 60;

	for(int i = 1; i <= n; i++) {
		fy = 0;

		for(int j = 1; j <= n; j++) {
			fy += map[j].sol * map[i].dis[j];
		}

		if(fy < mincost) mincost = fy;
	}
}

int main() {
	init();

	for(int i = 1; i <= q; i++) {
		int pl, army;
		scanf("%d%d", &pl, &army);
		map[pl].sol += army;
		recount();//重新计算各点费用  装在mincost
		printf("%lld\n", mincost);
	}

	return 0;
}



/******************************************************************
表示被坑了
105是10^5
.........
我还有什么可以说的呢？
**********************************************************************/

