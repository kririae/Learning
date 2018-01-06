/*
文老又丢坑了
我不会后缀数组啊
就只有兑现之前吹的NB了
KMP O(n)构造后缀数组
好吧我发现不行
*/
#include<cstdio>
#include<cstring>
#define N 500005
using namespace std;
//-------后缀数组------
char st[N];
int sa[N * 2];
int n;
int px[N], tong1[N], tong2[N], buf[N];
void build() {
	int m = 26; //桶的大小

	for(int i = 1; i <= n; i++) px[st[i] - 'a' + 1] = 1;

	for(int i = 1; i <= m; i++) px[i] += px[i - 1];

	for(int i = 1; i <= n; i++) sa[i] = px[st[i] - 'a' + 1];

	for(int k = 0; (1 << k) <= n && m != n; k++) {
		for(int i = 0; i <= m; i++) px[i] = 0;

		for(int i = 1; i <= n; i++) px[sa[i + (1 << k)]]++;

		for(int i = 1; i <= m; i++) px[i] += px[i - 1];

		for(int i = n; i >= 1; i--) tong1[px[sa[i + (1 << k)]]--] = i;

		for(int i = 0; i <= m; i++) px[i] = 0;

		for(int i = 1; i <= n; i++) px[sa[tong1[i]]]++;

		for(int i = 1; i <= m; i++) px[i] += px[i - 1];

		for(int i = n; i >= 1; i--) tong2[px[sa[tong1[i]]]--] = tong1[i];

		m = 0;

		for(int i = 1; i <= n; i++) {
			if(sa[tong2[i]] != sa[tong2[i - 1]] || sa[tong2[i] + (1 << k)] != sa[tong2[i - 1] + (1 << k)]) buf[tong2[i]] = ++m;
			else buf[tong2[i]] = m;
		}

		for(int i = 1; i <= n; i++) sa[i] = buf[i];
	}
}
//------------------------------------------
//-------构造height数组确定LCP--------------
int h[N], hei[N]; //按照排名顺序的height
int rvsa[N];//revise_sa
void buildh() {
	for(int i = 1; i <= n; i++) rvsa[sa[i]] = i;

	int least = 0;

	for(int i = 1; i <= n; i++) {
		while(rvsa[sa[i] + 1] != 0 && st[i + least] == st[rvsa[sa[i] + 1] + least]) least++;

		h[i] = least;
		least--;

		if(least < 0) least = 0;
	}

	for(int i = 1; i <= n; i++) hei[i] = h[rvsa[i]];
}
//-----------------------------------
int k;
void solve1() { //t=0
	int last = 0, p = 1;

	while(p <= n && last < k)
		last += n - rvsa[p] + 1 - hei[p - 1], p++;

	p--;

	if(last < k) printf("-1");
	else {
		int ansend = n - (last - k);
		int ansstart = rvsa[p];

		for(int j = ansstart; j <= ansend; j++) printf("%c", st[j]);
	}
}
void solve2() { //t==1

}
//------------------------------------
int t;
int main() {
	scanf("%s", st + 1);
	n = strlen(st + 1);
	build();
	scanf("%d%d", &t, &k);
	buildh();

	if(t == 0) solve1();
	else solve2();

	return 0;
}
