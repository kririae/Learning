#include<cstring>
#include<iostream>
#include<cstdio>
#define N 200005
using namespace std;
char s[N];
int n;
int len[N * 2], pre[N * 2], ne[N * 2][27];
int cnt;
int rt;
void build(char* s, int nlen, int &root) {
	int last, p, nw, ch;
	last = root = cnt = 1;
	len[root] = 0;

	for(int i = 1; i <= nlen; i++) {
		p = last;
		last = nw = ++cnt;
		len[nw] = len[p] + 1;
		ch = s[i] - 'a';

		while(p && ne[p][ch] == 0) ne[p][ch] = nw, p = pre[p];

		if(p) {
			int k = ne[p][ch];

			if(len[k] != len[p] + 1) {
				int np = ++cnt;
				memcpy(ne[np], ne[k], sizeof(ne[k]));
				len[np] = len[p] + 1;
				pre[np] = pre[k];
				pre[k] = pre[nw] = np;

				while(p && ne[p][ch] == k) ne[p][ch] = np, p = pre[p];
			} else pre[nw] = k;
		} else pre[nw] = root;
	}
}

char s2[N];
int mx[N * 2];
void mark() {
	int le = strlen(s2 + 1);
	int p = rt, p2;
	int lcnt = 0;

	for(int i = 1; i <= le; i++) {
		while(p && ne[p][s2[i] - 'a'] == 0) p = pre[p], lcnt = len[p];

		p = ne[p][s2[i] - 'a'];
		lcnt++;

		if(p == 0) p = rt, lcnt = 0;

		mx[p] = max(mx[p], lcnt);
	}
}

int tp[N * 2], js[N * 2];
long long work() {
	long long ans = 0;
	memset(js, 0, sizeof(js));

	for(int i = 1; i <= cnt; i++) js[len[i]]++;

	for(int i = 1; i <= n; i++) js[i] += js[i - 1];

	for(int i = cnt; i >= 1; i--) tp[js[len[i]]--] = i;

	for(int i = cnt; i >= 1; i--) {
		int t = tp[i];

		if(mx[t] < len[t]) ans += len[t] - max(mx[t], len[pre[t]]);

		mx[pre[t]] = min(len[pre[t]], max(mx[pre[t]], mx[t]));
	}

	return ans;
}
//-----------------
void out() {
	puts("");
	puts("-----------------------");
	puts("pre_tree");

	for(int i = 1; i <= cnt; i++) {
		if(pre[i] != 0) printf("%d %d\n", i, pre[i]);
	}

	puts("SAM");

	for(int i = 1; i <= cnt; i++) {
		for(int j = 0; j < 26; j++) {
			if(ne[i][j] != 0) printf("%d %d %c\n", i, ne[i][j], 'a' + j);
		}
	}

	puts("-------------------------");
	puts("");
}
//------------------
int main() {
	int T, T2;
	scanf("%d", &T);
	T2 = T;
	gets(s);

	while(T--) {
		int m;
		scanf("%d", &m);
		scanf("%s", s + 1);
		n = strlen(s + 1);
		build(s, n, rt);

		for(int i = 1; i <= m; i++) {
			scanf("%s", s2 + 1);
			mark();
		}

		long long ans = work();
		cout << "Case " << T2 - T << ": " << ans << endl;
		memset(len, 0, sizeof(len));
		memset(pre, 0, sizeof(pre));
		memset(mx, 0, sizeof(mx));

		for(int i = 1; i <= cnt; i++) {
			memset(ne[i], 0, sizeof(ne[i]));
		}
	}

	return 0;
}
