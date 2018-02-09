#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 200005
#include<cstring>
using namespace std;
int ne[N * 10 * 2][28], par[N * 10 * 2], len[N * 10 * 2], chu[N * 10 * 2]; //chu״ѹ
int cnt, root, last;
int w, nw, k, lca;
inline void add(const int ch, const int fr)
{
	w = last;
	last = nw = ++cnt;
	len[nw] = len[w] + 1;
	chu[nw] = fr;
	while(w && ne[w][ch] == 0) ne[w][ch] = nw, w = par[w];
	if(w) {
		k = ne[w][ch];
		if(len[k] != len[w] + 1) {
			lca = ++cnt;
			memcpy(ne[lca], ne[k], sizeof(ne[k]));
			par[lca] = par[k];
			chu[lca] = chu[k];
			len[lca] = len[w] + 1;
			par[k] = par[nw] = lca;
			while(ne[w][ch] == k) ne[w][ch] = lca, w = par[w];
		} else par[nw] = k;
	} else par[nw] = root;
}
char s[11][N * 2 + 20];
int klen[11];
int m = 1, n;
int all;
int tp[N * 10 * 2];
int px[N * 10 * 2];
int main()
{
	while(scanf("%s", s[m] + 1) != EOF) n += klen[m] = strlen(s[m] + 1), m++;
	m--;
	for(int i = 1; i <= m; i++) all |= 1 << i;
	last = root = ++cnt;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= klen[i]; j++) {
			add(s[i][j] - 'a', 1 << i);
		}
	}
	for(int i = 1; i <= cnt; i++) px[len[i]]++;
	for(int i = 1; i <= n; i++) px[i] += px[i - 1];
	for(int i = 1; i <= cnt; i++) tp[px[len[i]]--] = i;
	for(int i = cnt; i >= 1; i--) {
		k = tp[i];
		if(chu[k] == all) {
			printf("%d\n", len[k]);
			return 0;
		} else chu[par[k]] |= chu[k];
	}
	puts("0");
	return 0;
}
