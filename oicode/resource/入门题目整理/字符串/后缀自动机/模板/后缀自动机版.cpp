/*
CLJ第一题
字符串的最小表示
题目ZOJ1729
用来写写版
*/
#include<cstdio>
#include<iostream>
using namespace std;
char s[200005];
int n;
struct SAM {
	int par, len; //par是（S的逆序的后缀树上的）父亲 final-是否是终态
	int ne[30];
} sam[400005];
int cnt, root, last;
void build()
{
	root = ++cnt;
	last = root;
	sam[root] = sam[0];
	for(int i = 1; i <= n; i++) {
		//添加一个字符串
		//用wk代替pq,不然谁分得清p,q,nq,np,woc
		int w = last;
		int nw = ++cnt;
		sam[nw] = sam[0];
		sam[nw].len = sam[w].len + 1;
		int ch = s[i] - 'a'; //新建节点
		while(w && sam[w].ne[ch] == 0) sam[w].ne[ch] = nw, w = sam[w].par; //更新
		if(w == 0) { //开始给nw找父亲
			sam[nw].par = root; //只有祖先没得选
		} else {
			int k = sam[w].ne[ch];
			if(sam[k].len == sam[w].len + 1) { //situation 1
				sam[nw].par = k;
			} else {
				int lca = ++cnt; //新建两个串的lca
				sam[lca] = sam[k];
				sam[lca].len = sam[w].len + 1;
				sam[k].par = sam[nw].par = lca;
				while(w && sam[w].ne[ch] == k) sam[w].ne[ch] = lca, w = sam[w].par; //为什么
			}
		}
		last = nw; //完了？
	}
}
void work()
{
	//每次往最小的走，嗯可以逆序压位
	int si = 0, p = root;
	for(int i = 1, go; i <= n / 2; i++) {
		for(int j = 0; j < 26; j++) {
			if(sam[p].ne[j]) {
				go = j;
				break;
			}
		}
		p = sam[p].ne[go];
	}
	printf("%d\n", sam[p].len - n / 2);
	cnt = 0;
}
void outit() //输出后缀自动机的样子 和par树//graph好像可以手动编译
{
	for(int i = 1; i <= cnt; i++) {
		for(int j = 0; j <= 25; j++) {
			if(sam[i].ne[j] != 0) {
				printf("%d %d %c\n", i, sam[i].ne[j], j + 'a');
			}
		}
	}
	printf("par\n")
	for(int i = 1; i <= cnt; i++) {
		printf("%d %d\n", i, sam[i].par);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		for(int i = 1; i <= n; i++) s[n + i] = s[i];
		n += n;
		build();
		work();
		//outit();
	}
	return 0;
}
