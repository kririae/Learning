inline void tarjan(R int x)
{
	dfn[x] = low[x] = ++cnt;
	s.push(x), vis[x] = 1;
	for (R int i = 0; i < edges[x].size(); ++i)
	{
		R int to = edges[x][i];
		if(!dfn[to])
			tarjan(to), low[x] = min(low[x], low[to]);
		else if(vis[to]) low[x] = min(low[x], dfn[to]);
	}
	if(dfn[x] == low[x])
	{
		int curr;
		do {
			curr = s.top(), s.pop(), vis[curr] = 0;
			// todo
		} while(curr != x);
	}
}