#include <bits/stdc++.h>
using namespace std;
int n, m, k, father[200005];
vector<int> result;
struct edge {
	int x, y;
} p[200005];
inline int find(int val) {
	if (father[val] != val)
		father[val] = find(val);

	return father[val];
}
inline void unionn(int val1, int val2) {
	father[find(val1)] = find(val2);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i <= n; ++i)
		father[i] = i;

	for (register int i = 0; i < m; ++i)
		cin >> p[i].x >> p[i].y;

	cin >> k;

	for (int val, i = 0; i < k; ++i) {
		cin >> val;

		for (int i = 0; i < m; ++i) {
			if (p[i].x == val || p[i].y == val) {
				unionn(p[i].x, p[i].y);
			}
		}

		// 查找联通数量
		for (int i = 0; i <= n; ++i)
			int tempo = find(i);

		// 化为两层的树形结构
		int count = 1;
		int flag = father[0];

		for (int i = 1; i <= n; ++i) {
			if (father[i] != flag) {
				flag = father[i];
				++count;
			}
		}

		result.push_back(count);
	}

	for (int i = result.size() - 1; i >= 0; --i) {
		cout << result[i] << endl;
	}

	return 0;
}

#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
inline void read(int &x) {
	x = 0;
	char c = getchar();

	while(!isdigit(c)) c = getchar();

	while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
}
#define MAXN 400006
int fa[MAXN], cnt;
inline int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline void uni(int x, int y) {
	int xx = find(x), yy = find(y);

	if(xx == yy) return;

	--cnt;
	fa[xx] = yy;
}
int n, m;
typedef pair<int, int> pii;
pii rel[MAXN >> 1];
int del[MAXN], ans[MAXN];
bool vis[MAXN];
vector<int> v[MAXN];
inline void add_set(int x, int y) {
	//cout<<x<<" "<<y<<endl;
	if(!vis[x] && !vis[y]) {
		//cout<<x<<" "<<y<<endl;
		uni(x, y);
		return;
	}

	v[x].push_back(y), v[y].push_back(x);
}
int main() {
	read(n), read(m);

	for(int i = 0; i < n; ++i) fa[i] = i;

	cnt = n;

	for(int i = 1; i <= m; ++i) read(rel[i].first), read(rel[i].second);

	int K;
	read(K);
	cnt -= K;

	for(int i = 1; i <= K; ++i) read(del[i]), vis[del[i]] = 1;

	//for(int i = 0; i < n; ++i) cout<<vis[i]<<" ";
	//cout<<endl;
	for(int i = 1; i <= m; ++i) add_set(rel[i].first, rel[i].second);

	ans[K + 1] = cnt;

	for(int i = K; i >= 1; --i) {
		vis[del[i]] = 0;
		++cnt;

		for(int j = 0; j < v[del[i]].size(); ++j)
			if(!vis[v[del[i]][j]])
				uni(del[i], v[del[i]][j]);

		ans[i] = cnt;
	}

	for(int i = 1; i <= K + 1; ++i) cout << ans[i] << endl;

	return 0;
}