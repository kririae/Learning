#include <bits/stdc++.h>
using namespace std;
struct node {
	int value;
	int deepth;
	node(int v, int deep)
	{
		value = v, deepth = deep;
	}
};

vector<int> graph[100000];
queue<node> q;
bool vis[100000];
int main()
{
	int n, m;
	cin >> n >> m;

	for(int x, y, i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int fis, result = 0;
	cin >> fis;
	q.push(node(fis, 1));
	vis[fis] = true;

	while(!q.empty()) {
		node ind = q.front();

		if(ind.deepth > result) result = ind.deepth;

		int k = graph[ind].size();

		for(int i = 0; i < k; ++i) {
			if(!vis[graph[ind][i]]) {
				vis[graph[ind][i]] = true;
				q.push(node(graph[ind][i], ind.deepth + 1));
			}
		}

		q.pop();
	}

	cout << result << endl;
	return 0;
}