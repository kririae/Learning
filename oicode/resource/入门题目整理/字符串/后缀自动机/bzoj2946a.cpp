#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 1000000000
#define mod 1000000007
#define pa pair<int,int>
#define ll long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();

	while(ch < '0' || ch > '9') {
		if(ch == '-')f = -1;

		ch = getchar();
	}

	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}

	return x * f;
}
int n;
char ch[2005];
struct sam {
	int cnt, last;
	int fa[4005], a[4005][27], mx[4005], len[4005], ans[4005];
	int v[4005], q[4005];
	sam() {
		last = ++cnt;
	}
	void extend(int c) {
		int p = last, np = last = ++cnt;
		mx[np] = mx[p] + 1;

		while(!a[p][c] && p)a[p][c] = np, p = fa[p];

		if(!p)fa[np] = 1;
		else {
			int q = a[p][c];

			if(mx[p] + 1 == mx[q])fa[np] = q;
			else {
				int nq = ++cnt;
				mx[nq] = mx[p] + 1;
				memcpy(a[nq], a[q], sizeof(a[q]));
				fa[nq] = fa[q];
				fa[np] = fa[q] = nq;

				while(a[p][c] == q)a[p][c] = nq, p = fa[p];
			}
		}
	}
	void pre() {
		for(int i = 1; i <= cnt; i++)ans[i] = mx[i];

		for(int i = 1; i <= cnt; i++)v[mx[i]]++;

		for(int i = 1; i <= cnt; i++)v[i] += v[i - 1];

		for(int i = cnt; i; i--)q[v[mx[i]]--] = i;
	}
	void solve() {
		scanf("%s", ch + 1);
		memset(len, 0, sizeof(len));
		int l = strlen(ch + 1), p = 1, tmp = 0;

		for(int i = 1; i <= l; i++) {
			int c = ch[i] - 'a';

			while(!a[p][c] && p)p = fa[p];

			if(p == 0)p = 1, tmp = 0;
			else tmp = min(tmp, mx[p]) + 1, p = a[p][c];

			len[p] = max(len[p], tmp);
		}

		for(int i = cnt; i; i--)len[fa[q[i]]] = max(len[fa[q[i]]], len[q[i]]);

		for(int i = 1; i <= cnt; i++)ans[i] = min(ans[i], len[i]);
	}
} sam;
int main() {
	n = read();
	scanf("%s", ch + 1);
	int l = strlen(ch + 1);

	for(int i = 1; i <= l; i++)sam.extend(ch[i] - 'a');

	sam.pre();

	for(int i = 1; i < n; i++)sam.solve();

	int ans = 0;

	for(int i = 1; i <= sam.cnt; i++)
		ans = max(ans, sam.ans[i]);

	printf("%d\n", ans);
	return 0;
}
