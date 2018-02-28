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