#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

vector<int> edges[maxn];
int n, dfn[maxn], low[maxn], cnt, ans = maxn, x;
bitset<maxn> vis;
stack<int> s;

inline void tarjan(int x)
{
	// 再打一次~
	low[x] = dfn[x] = ++cnt;
	s.push(x), vis[x] = 1;
	for (R int i = 0; i < edges[x].size(); ++i)
	{
		int to = edges[x][i];
		if(!dfn[to])
		{
			// 如果to在dfs树上
			tarjan(to);
			low[x] = min(low[x], low[to]);
		} else if(vis[to]) {
			// 如果to不在dfs树上，用dfn更新low[x]
			low[x] = min(low[x], dfn[to]);
		}
	}
	if(low[x] == dfn[x]) 
	{
		// 又到了pop的季节
		int cnt = 0;
		for (; ;)
		{
		    int curr = s.top();
		    s.pop(), ++cnt;
		    if(curr == x) break;
		} // 把需要pop的都pop出来
		if(cnt > 1) ans = min(ans, cnt); // 如果不光是这条边的话
	}
}

int main()
{
	scanf("%d", &n);
	for (R int i = 1; i <= n; ++i)
	{	
		scanf("%d", &x);
		edges[i].push_back(x);
	}
	for (R int i = 1; i <= n; ++i)
		if(!dfn[i]) tarjan(i);
	printf("%d", ans);
}