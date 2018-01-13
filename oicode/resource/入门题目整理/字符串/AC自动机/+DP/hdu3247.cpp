/*
这回是真状压DP了
计算每一个串结尾到另一个串结尾的距离
对于普通边距离为1
fail边不能跑
上spfa
跑n遍
*/
#include<cstdio>
#include<queue>
#include<iostream>
#define N 60005
#define M 2
#define INF 1000000
using namespace std;
int n, m, lim;
int chars[12];
//----------read--------------
int read(int p, int *b)
{
	char c = getchar();
	while(c == '\n' || c == '\r' || c == ' ') c = getchar();
	while(c >= '0' && c <= '1') b[++p] = c - '0' + 1, c = getchar();
	return p;
}
//----------AC atom-----------
struct node {
	int p;
	int have, vir; //状压 是否包含病毒
	int f;//fail
	int ne[M + 1];
} a[N];
int cnt, root, place;
void insert(int &k, int st, int en, int kind, const int *w)
{
	if(k == 0) k = ++cnt, a[k].p = st;
	if(st == en) {
		if(kind != 3)	a[k].have |= kind, place = k;
		else a[k].have = 0, a[k].vir = 1;
	} else insert(a[k].ne[w[st + 1]], st + 1, en, kind, w);
}
void pre()
{
	queue<int> q;
	for(int i = 1; i <= M; i++) {
		if(a[root].ne[i] == 0) a[root].ne[i] = root;
		else a[a[root].ne[i]].f = root, q.push(a[root].ne[i]);
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(a[a[u].f].vir == 1) a[u].vir = 1;
		else a[u].have |= a[a[u].f].have;
		for(int i = 1; i <= M; i++) {
			if(a[u].ne[i] == 0) a[u].ne[i] = a[a[u].f].ne[i];
			else a[a[u].ne[i]].f = a[a[u].f].ne[i], q.push(a[u].ne[i]);
		}
	}
}
//----------spfa--------------
int dis[N];
void SPFA(int start)
{
	for(int i = 1; i <= cnt; i++) dis[i] = INF;
	dis[start] = 0;
	queue<int> q;
	q.push(start);
	for(int i = 0; i < n; i++)
		if(a[start].have & (1 << (i - 1))) dis[chars[i]] = 0, q.push(chars[i]);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(a[u].vir) continue;
		//if(dis[a[u].f]>dis[u]) dis[a[u].f]=dis[u],q.push(a[u].f);
		for(int i = 1; i <= M; i++) {
			if(dis[a[u].ne[i]] > dis[u] + 1) {
				dis[a[u].ne[i]] = dis[u] + 1;
				q.push(a[u].ne[i]);
			}
		}
	}
}
//-----------DP---------------
int map[11][11];//root -> 10
int dp[(1 << 10) + 1][11];
void go_DP()
{
	lim = 1 << n;
	for(int j = 0; j < lim; j++)
		for(int i = 1; i <= n; i++)
			dp[j][i] = INF;
	SPFA(root);
	for(int i = 1; i <= n; i++) {
		dp[1 << (i - 1)][i] = dis[chars[i]];
	}
	for(int i = 1; i <= n; i++) {
		SPFA(chars[i]);
		for(int j = 1; j <= n; j++) {
			map[i][j] = dis[chars[j]];
		}
	}
	for(int j = 0; j < lim; j++) {
		for(int i = 1; i <= n; i++) {
			if(dp[j][i] == INF || (j & (1 << (i - 1))) == 0) continue;
			for(int k = 1; k <= n; k++) {
				dp[j | (1 << (k - 1))][k] = min(dp[j | (1 << (k - 1))][k], dp[j][i] + map[i][k]);
			}
		}
	}
	int ans = INF;
	for(int i = 1; i <= n; i++)
		ans = min(ans, dp[(lim - 1)][i]);
	printf("%d\n", ans);
}
//-----------init-------------
int word[N];
void init()
{
	int p = 0;
	root = cnt = 1;
	for(int i = 1; i <= n; i++) {
		int t = read(p, word);
		insert(root, p, t, (1 << (i - 1)), word);
		chars[i] = place;
		p = t;
	}
	for(int i = 1; i <= m; i++) {
		int t = read(p, word);
		insert(root, p, t, 3, word);
		p = t;
	}
}
//-----------clear------------
void clear()
{
	for(int i = 0; i < 12; i++) chars[i] = 0;
	for(int i = 1; i <= cnt; i++) {
		a[i].f = a[i].have = a[i].p = a[i].vir = 0;
		for(int j = 1; j <= M; j++) {
			a[i].ne[j] = 0;
		}
	}
}
//----------------------------
int main()
{
	while(1) {
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0) break;
		init();
		pre();
		go_DP();
		clear();
	}
	return 0;
}
