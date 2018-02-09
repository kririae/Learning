#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;

struct Edge 
{
	char cl[25];
	int length;
	int from, to;
	int reflect;
	
	bool operator < (const Edge (&a)) const
	{
		if(from < a.from) return true;
		if(from == a.from) return to < a.to;
		if(from > a.from) return false;
	}
	
	Edge() {}
	Edge(int f, int t, int l, int r) {
		from = f, to = t, length = l, reflect = r;
	}
};

Edge edges[maxn];
vector<Edge> mmp[26];

inline void addedge(int from, int to, int length, int ref)
{
	mmp[from].push_back(Edge(from, to, length, ref));
}

map<Edge, bool> vis;
set<string> res;
inline int dfs(int s, string a)
{
	// 反正只有26个点 dfs一次应该没啥大问题，，，，吧？
	for (int i = mmp[s].size(); i >= 0; --i) 
	{
		Edge &curr = mmp[s][i];
		bool can_go = false;
		if(!vis[curr]) 
		{ 
			can_go = true;
			string neww(edges[curr.reflect].cl);
			dfs(curr.to, a + neww);
		}	
		if(!can_go) 
		{
			res.insert(a); 
		}
	}
}

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> edges[i].cl;
		edges[i].length = strlen(edges[i].cl);
		edges[i].from = edges[i].cl[0] - 'a';
		edges[i].to = edges[i].cl[edges[i].length - 1] - 'a';
	}
	
	for (int i = 1; i <= n; ++i) 
	{
		Edge &curr = edges[i];
		addedge(curr.from, curr.to, curr.length, i);
	}
	for (int i = 1; i <= n; ++i) 
	{
		dfs(i, string());
	}
	set<string>::iterator a = res.begin();
	cout << *a << endl;
}
