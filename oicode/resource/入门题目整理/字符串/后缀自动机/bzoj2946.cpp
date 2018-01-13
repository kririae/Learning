/*
做题全靠par树
要交C++14
O（n） T了
//bzoj上2946
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 2005
#include<cstring>
using namespace std;
struct suffix_automatic {
	int ne[27];
	int par, len;
	int chu;//chu状压
} sam[N * 5 * 2];
int cnt, root, last;
inline void add(const int ch, const int fr)
{
	int w = last;
	int nw = ++cnt;
	last = nw;
	sam[nw].len = sam[w].len + 1;
	sam[nw].chu = fr;
	while(w && sam[w].ne[ch] == 0) sam[w].ne[ch] = nw, w = sam[w].par;
	if(!w) {
		sam[nw].par = root;
		return;
	}
	int k = sam[w].ne[ch];
	if(sam[k].len == sam[w].len + 1) {
		sam[nw].par = k;
		return;
	}
	int lca = ++cnt;
	sam[lca] = sam[k];
	sam[lca].len = sam[w].len + 1;
	sam[k].par = sam[nw].par = lca;
	while(sam[w].ne[ch] == k) sam[w].ne[ch] = lca, w = sam[w].par;
}
char s[11][N + 20];
int len[11];
int m = 1, n;
int all;
int tp[N * 5 * 2];
int px[N * 5 * 2];
int main()
{
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) scanf("%s", s[i] + 1), n += len[i] = strlen(s[i] + 1);
	for(int i = 1; i <= m; i++) all |= 1 << i;
	last = root = ++cnt;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= len[i]; j++) {
			add(s[i][j] - 'a', 1 << i);
		}
	}
	for(int i = 1; i <= cnt; i++) px[sam[i].len]++;
	for(int i = 1; i <= n; i++) px[i] += px[i - 1];
	for(int i = 1; i <= cnt; i++) tp[px[sam[i].len]--] = i;
	for(int i = cnt; i >= 1; i--) {
		int k = tp[i];
		if(sam[k].chu == all) {
			printf("%d\n", sam[k].len);
			return 0;
		} else sam[sam[k].par].chu |= sam[k].chu;
	}
	puts("0");
	return 0;
}
