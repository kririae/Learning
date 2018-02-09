/*
其实这道题m
长度可以很长
只要把AC自动机建完
然后根据AC自动机建立矩阵
加个快速幂

AC自动机忘得差不多了
就只有脑补了

附组数据：
2 2
ACA
C

51
*/
#include<cstdio>
#include<iostream>
#include<queue>
#define N 6015
#define M 26
using namespace std;
int read(int p, int *b)
{
	char c = getchar();
	while(c == '\n' || c == '\r') c = getchar();
	while(c >= 'A' && c <= 'Z') b[p++] = c - 'A' + 1, c = getchar();
	return p;
}
//----------AC自动机-----
int buf0, word[N], cnt;
struct node {
	int st;//字符串位置
	int end;//是否是一个字符串的结尾
	int ne[28];//1~26字符 0-fail
} a[N];
void insert(int &k, int st, int en)
{
	if(st > en) return;
	if(k == 0) {
		k = ++cnt;
		a[k].st = st;
	}
	if(st == en) {
		a[k].end = 1;
		return;
	} else insert(a[k].ne[word[st + 1]], st + 1, en);
}
void pre_fail(int root)
{
	queue<int> p;
	for(int i = 0; i <= M; i++) {
		if(a[root].ne[i] == 0) a[root].ne[i] = root;
		else {
			a[a[root].ne[i]].ne[0] = root;
			p.push(a[root].ne[i]);
		}
	}
	while(!p.empty()) {
		int u = p.front();
		p.pop();
		if(a[a[u].ne[0]].end == 1) a[u].end = 1; //用于串中匹配
		for(int i = 1; i <= M; i++) {
			if(a[u].ne[i] == 0) a[u].ne[i] = a[a[u].ne[0]].ne[i];
			else {
				a[a[u].ne[i]].ne[0] = a[a[u].ne[0]].ne[i];
				p.push(a[u].ne[i]);
			}
		}
	}
}
//-----------------------
int n, m, root;
const int P = 10007;
int dp[105][N][2];
int main()
{
	int t = 0;
	root = 1;
	cnt = 1;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		int p = read(t, word);
		insert(root, t - 1, p - 1);
		t = p;
	}
	pre_fail(root);
	dp[0][1][0] = 1;
	for(int i = 0; i <= m; i++) {
		for(int j = 1; j <= cnt; j++) {
			if(a[j].end == 1) {
				dp[i][j][1] += dp[i][j][0];
				dp[i][j][0] = 0;
			}
			dp[i][j][1] %= P;
			dp[i][j][0] %= P;
		}
		for(int j = 1; j <= cnt; j++) {
			for(int k = 1; k <= M; k++) {
				dp[i + 1][a[j].ne[k]][1] += dp[i][j][1];
				dp[i + 1][a[j].ne[k]][0] += dp[i][j][0];
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= cnt; i++) {
		ans += dp[m][i][1];
	}
	ans %= P;
	printf("%d\n", ans);
	return 0;
}
