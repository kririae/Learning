title: 「题解」网络流24题
author: kririae
tags:
  - 图论
  - 网络流
categories:
  - oi
date: 2018-02-28 08:34:00
---
# [题解]网络流24题

---

开个新坑...网络流24题   

<!--more-->

目前是看着题就做...最后做完会排序

## 飞行员配对方案
裸二分图匹配 但是需要输出方案.
输出方案..道理就是“非超级源点，非超级汇点，flow = 1的边”
```cpp
// by kririae
// 2018/2/28
#include <bits/stdc++.h>
using namespace std;
namespace dinic
{
const int maxn = 2005;
int n, m, s, t, e;

struct Edge
{
    int from, to, cap, flow;
    Edge() {}
    Edge(int fr, int t, int c, int f) : from(fr), to(t), cap(c), flow(f)
    {
    }
};

vector<Edge> edges;
vector<int> G[maxn];
bool vis[maxn];
int d[maxn], cur[maxn];

inline void init()
{
    for (int i = 0; i < maxn; ++i)
        G[i].clear();
    edges.clear();
    memset(d, 0, sizeof(d));
}
inline void addedge(int from, int to, int cap,
                    int flow)
{
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    int size = edges.size();
    G[from].push_back(size - 2);
    G[to].push_back(size - 1);
}

inline bool BFS()
{
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = true;

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        for (int i = 0; i < G[x].size(); ++i)
        {
            Edge &e = edges[G[x][i]];

            if (!vis[e.to] && e.cap > e.flow)
            {
                vis[e.to] = true;
                d[e.to] = d[x] + 1;
                Q.push(e.to);
            }
        }
    }
    return vis[t];
}

inline int dfs(int x, int a)
{
    if (x == t || a == 0)
        return a;

    int flow = 0, f;

    for (int &i = cur[x]; i < G[x].size(); ++i)
    {
        Edge &e = edges[G[x][i]];

        if (d[x] + 1 == d[e.to] &&
            (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
        {
            e.flow += f;
            edges[G[x][i] ^ 1].flow -= f;
            flow += f;
            a -= f;

            if (a == 0)
                break;
        }
    }

    return flow;
}

int maxFlow(int st, int ed)
{
    s = st, t = ed;
    int flow = 0;
    while (BFS())
    {
        memset(cur, 0, sizeof(cur));
        flow += dfs(st, 1e9);
    }

    return flow;
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    using namespace dinic;
    int u, v;
    cin >> m >> n;
    s = n + 1;
    t = n + 2;
    while (cin >> u >> v)
    {
        if (u == -1 && v == -1)
            break;
        addedge(u, v, 1, 0);
    }
    for (int i = 1; i <= m; ++i)
        addedge(s, i, 1, 0);
    for (int i = m + 1; i <= n; ++i)
        addedge(i, t, 1, 0);
    int ans = maxFlow(s, t);
    if (ans == 0)
    {
        cout << "No Solution!" << endl;
        return 0;
    }
    cout << ans << endl;
    for (int i = 0; i < edges.size(); i += 2)
    {
        if (edges[i].flow == 1 &&
            edges[i].from != s &&
            edges[i].to != s &&
            edges[i].from != t &&
            edges[i].to != t)
            cout << edges[i].from << " " << edges[i].to << endl;
    }
}
```

## 软件补丁问题
貌似和网络流没啥关系。   
考虑到万能的SPFA（bfs）能够完成很大一部分的状压dp，见愤怒的小鸟
```cpp
// by kririae
// 2018/2/28
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

int n, m;

struct node
{
	int dis, b1, b2, f1, f2;
	node() {}
};

node t[maxn];
bitset<1 << 20> vis;
int dis[1 << 20];
queue<int> q;

inline int spfa()
{
	for (int i = 0; i < (1 << n); ++i)
		dis[i] = 1e9;
	int s = (1 << n) - 1;
	q.push(s);
	vis[s] = true;
	dis[s] = 0;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		vis[curr] = false;
		for (int i = 0; i < m; ++i)
			// 当且仅当软件包含b1的所有错误 且不包含b2的任何一个错误
			if ((t[i].b1 & curr) == t[i].b1 && (t[i].b2 & curr) == 0) // 是否能够加入边
			{
				int to = curr & (~t[i].f1);
				to |= t[i].f2; // 修复f1中的错误
				if (dis[to] > dis[curr] + t[i].dis)
				{
					dis[to] = dis[curr] + t[i].dis;
					if (!vis[to])
						vis[to] = true, q.push(to);
				}
			}
	}
	return dis[0];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (register int i = 0; i < m; ++i)
	{
		string pro1, pro2;
		int k = 1;
		cin >> t[i].dis >> pro1 >> pro2;
		for (int j = 0; j < n; ++j)
		{
			if (pro1[j] == '+')
				t[i].b1 |= k;
			if (pro1[j] == '-')
				t[i].b2 |= k;
			if (pro2[j] == '-')
				t[i].f1 |= k;
			if (pro2[j] == '+')
				t[i].f2 |= k;
			k <<= 1;
		}
	}
	int res = spfa();
	if (res == 1e9)
		cout << 0 << endl;
	else
		cout << res << endl;
	return 0;
}
```

## 魔术球问题
### 贪心
bzoj3716 也可以用贪心水过   当然我是来学网络流的   
```cpp
#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<int> res[100];

inline bool can_sqrt(int t)
{
	return (int)sqrt(t) == sqrt(t);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 1; ; ++i)
	{
		bool flag = false;

		for (int j = 1; j <= n; ++j)
		{
			if (res[j].size() == 0 ||
				can_sqrt(res[j][res[j].size() - 1] + i))
			{
				res[j].push_back(i);
				flag = true;
				break;
			}
		}

		if (flag) ++cnt;

		else break;
	}

	cout << cnt << endl;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";

		cout << endl;
	}

	return 0;
}
```
### 网络流解法

## 负载平衡问题
### 贪心
...为啥这道题又可以贪心...   
均分纸牌加强版,可以推（我懒）
```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int n, a[maxn], s[maxn], ave, res;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i], ave += a[i];

	ave /= n;

	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i] - ave;

	sort(s + 1, s + n + 1);
	int mid = s[n / 2 + 1];

	for (int i = 1; i <= n; ++i)
		res += abs(s[i] - mid);

	cout << res << endl;
}
```
### 网络流解法