#include<cstdio>
#include<iostream>
#include<cstring>
#define N 20005
using namespace std;
int par[N * 2], len[N * 2], rl[N * 2], rr[N * 2];
short ne[N * 2][180];
short yw[N * 2][180];
int sz[N * 2]; //来压位一发挤个rank
//试了下压180三个long long实在不科学，也不好写，干脆数组压位   e..空间炸了 开short
//时间没少多少啊 就只快一倍
//换成G++交就快了
//比黄学长快一半多
//204ms
int cnt, root, last;
int w, nw, lca, k;
int buf;
inline void add(int ch, int val) {
	w = last;
	last = nw = ++cnt;
	len[nw] = len[w] + 1;
	rl[nw] = rr[nw] = val;

	while(w && ne[w][ch] == 0) ne[w][ch] = nw, yw[w][++sz[w]] = ch, w = par[w];

	if(w) {
		k = ne[w][ch];

		if(len[k] != len[w] + 1) {
			lca = ++cnt; //memcpy(ne[lca],ne[k],sizeof(ne[k]));

			for(int i = 1; i <= sz[k]; i++) ne[lca][yw[k][i]] = ne[k][yw[k][i]], yw[lca][i] = yw[k][i];

			sz[lca] = sz[k];
			par[lca] = par[k];
			len[lca] = len[w] + 1;
			rr[lca] = rr[k];
			rl[lca] = rl[k];
			par[k] = par[nw] = lca;

			while(ne[w][ch] == k) ne[w][ch] = lca, w = par[w];
		} else par[nw] = k;
	} else par[nw] = root;
}
char s[N];
int n;
inline int read() {
	static char c;
	static int ret;
	c = getchar();
	ret = 0;

	while(c < '0' || c > '9') c = getchar();

	while(c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();

	return ret;
}
void init() {
	for(int i = 1; i <= n; i++) s[i] = read();

	for(; cnt; cnt--) {
		for(; sz[cnt]; sz[cnt]--) ne[cnt][yw[cnt][sz[cnt]]] = 0, yw[cnt][sz[cnt]] = 0;

		rl[cnt] = rr[cnt] = len[cnt] = par[cnt] = 0;
	}

	cnt = 1;
	last = root = 1;
}
int px[N * 2];
int tp[N * 2];
int ans;
void work() {
	for(int i = 2; i <= n; i++) {
		add(s[i] - s[i - 1] + 90, i);
	}

	for(int i = 1; i <= cnt; i++) px[len[i]]++;

	for(int i = 1; i <= n; i++) px[i] += px[i - 1];

	for(int i = 1; i <= cnt; i++) tp[px[len[i]]--] = i;

	memset(px, 0, sizeof(int) * (n + 2));
	ans = 0;

	for(int i = cnt; i >= 1; i--) {
		k = tp[i];

		if(len[k] <= 3) break;

		ans = max(ans, min(rr[k] - rl[k] - 1, len[k]));
		rr[par[k]] = max(rr[par[k]], rr[k]);
		rl[par[k]] = min(rl[par[k]], rl[k]);
	}

	ans++;

	if(ans < 5) puts("0");
	else printf("%d\n", ans);
}
int main() {
	last = root = ++cnt;

	while(scanf("%d", &n) == 1) {
		if(!n)break;

		init();
		work();
	}

	return 0;
}
