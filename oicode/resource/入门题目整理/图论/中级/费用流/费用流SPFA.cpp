#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<queue>
#define N 205
using namespace std;
const int INF = 9999999;
const int RD = 0;
const int CD = 1;
struct edge {
	int flow;//usable flow
	int cap;
	int to;
	int from;
	int cost;
	/*edge(){
		flow=cap=to=cost=0;
	}*/
} x[25005];
vector<int> points[N];
int len;
void addedge(int from, int to, int flow, int cost) {
	x[len].cap = x[len].flow = flow;
	x[len].cost = -cost;
	x[len].to = to;
	x[len].from = from;
	points[from].push_back(len);
	len++;
	x[len].cap = flow;
	x[len].cost = cost;
	x[len].flow = 0;
	x[len].to = from;
	x[len].from = to;
	points[to].push_back(len);
	len++;
}
int mincostflow(int start, int end, int &flow) { //返回最小费用  ,int flow=1
	int from[N];
	int distan[N];
	int fl[N];//统一采用一维编码  from里面装边
	fill(from, from + N - 2, -1);
	fill(distan, distan + N - 2, INF);
	//spfa
	fl[start] = flow;
	distan[start] = 0;
	queue<int> u;
	u.push(start);

	while(!u.empty()) {
		int v = u.front();
		u.pop();

		for(int i = 0, len = points[v].size(); i < len; i++) {
			edge& e = x[points[v][i]];

			if(e.flow >= 1) {
				if(e.cost + distan[v] < distan[e.to]) {
					distan[e.to] = e.cost + distan[v];
					from[e.to] = points[v][i];
					fl[e.to] = min(e.flow, fl[v]);
					u.push(e.to);
				}
			}
		}
	}

	if(distan[end] == INF) return -1;

	int p = from[end];
	int ff = fl[end];
	flow -= ff;

	while(p != -1) {
		x[p].flow -= ff;
		x[p ^ 1].flow += ff;
		p = from[x[p].from];
	}

	return distan[end];
}
int feiyong(int start, int end, int &flow) {
	int mincost = 0;
	int p = 1;

	while(flow != 0) {
		mincost += mincostflow(start, end, flow);
	}

	return mincost;
}
int c() {

}

int n, m, T;
int main() {
	scanf("%d", &T);

	while(T--) {

	}

}
