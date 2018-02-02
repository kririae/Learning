#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
struct edge {
	int from, to, val;
	edge(int from_, int to_, int val_)
	{
		from = from_;
		to = to_;
		val = val_;
	}
};
vector<edge> e;
int elen = 0;
vector<int> node[1004];
void addedge(int from, int to, int val)
{
	e.push_back(edge(from, to, val));
	node[from].push_back(elen++);
}

int distan[1004];
bool SPFA(int S, int T)
{
	memset(distan, -1, sizeof(distan));
	distan[S] = 0;
	queue<int> x;
	x.push(S);
	while(!x.empty()) {
		int u = x.front();
		x.pop();
		for(int i = 0, len = node[u].size(); i < len; i++) {
			edge& ed = e[node[u][i]];
			if(distan[ed.to] == -1 || distan[ed.to] > distan[ed.from] + ed.val) {
				distan[ed.to] = distan[u] + ed.val;
				x.push(ed.to);
			}
		}
	}
	return distan[T] != -1;
}

struct state {
	int f, g;
	int place;
	state(int place_, int g_)
	{
		place = place_;
		g = g_;
		f = g + distan[place];
	}
	bool operator < (const state &b)const
	{
		return f > b.f;
	}
};

void Astar(int S, int T, int k)
{
	priority_queue<state> pq;
	pq.push(state(S, 0));
	while(k > 0 && !pq.empty()) {
		int u = pq.top().place;
		int g = pq.top().g;
		pq.pop();
		if(u == T) {
			printf("%d\n", g);
			k--;
			if(k == 0) break;
			continue;
		}
		for(int i = 0, len = node[u].size(); i < len; i++) {
			edge& ed = e[node[u][i]];
			pq.push(state(ed.to, g + ed.val));
		}
	}
	if(k != 0) {
		for(int i = k; i > 0; i--)
			printf("-1\n");
	}
}

int n, m, k;
void init()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int f, t, d, i = 1; i <= m; i++) {
		scanf("%d%d%d", &f, &t, &d);
		addedge(f, t, d);
	}
	SPFA(1, n);
}
int main()
{
	init();
	Astar(n, 1, k);
	return 0;
}
