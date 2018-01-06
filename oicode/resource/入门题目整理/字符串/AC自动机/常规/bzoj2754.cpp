/*
喵星球上的点名
那次弃疗后这次来补上
使用map代替字符数组
所以失配时要耐心沿着失配边走
不能直接失配与数组结合了

查了查原来用的数组版的叫
fail图（ac自动机的优化版）
而要跑while的才是ac自动机

不好写
直接暴力出奇迹
WA 了
*/
#include<cstdio>
#include<map>
#include<iostream>
#include<queue>
#define N 1000005
using namespace std;
int miaobuf, miao_word[N];
int dianbuf, dian_word[N];
struct name_miao {
	int st1, en1;
	int st2, en2;
	int ans;
} name[20005];
int n, m, root, cnt;
//-------------------------
//-------------------------
struct node {
	int p, times, f, fa; //times-出现为子串结尾的次数(name的结尾) f-fail 优化常数
	vector<int> name;
	int checks;//被点到的次数
	map<int, int> mp;
} a[N];
//-------------------------
//-------------------------
int ans_a[50005];//被点到的次数
void insert(int &k, int st, int en, const int &na) {
	if(k == 0) k = ++cnt, a[k].p = st;

	if(st == en) a[k].times++, a[k].name.push_back(na);
	else {
		map<int, int>::iterator itr = a[k].mp.find(dian_word[st + 1]);

		if(itr == a[k].mp.end()) {
			int p = 0;
			insert(p, st + 1, en, na);
			a[k].mp[dian_word[st + 1]] = p;
		} else {
			int p = itr->second;
			insert(p, st + 1, en, na);
		}
	}
}
inline int get(int k, int p) {
	map<int, int>::iterator itr = a[k].mp.find(p);

	if(itr == a[k].mp.end()) return 1;

	return itr->second;
}
int ifdian[N];//避免一只猫一次点名叫多次
int add(int k, int vi) { //暴力
	ifdian[k] = vi;
	int ret = a[k].times;
	int p = a[k].f;

	while(p != 0 && ifdian[p] != vi) p = a[p].f;

	if(p != 0) {
		a[p].checks--;
		ret -= a[p].times;
	}

	int q = a[k].f;

	while(q != p) {
		ifdian[q] = vi, q = a[q].f;
	}

	return ret;
}
int check(int st, int en, int vision) { //miao_word
	int p = root, ret = 0;

	for(int i = st; i <= en; i++) {
		while(p != 0 && get(p, miao_word[i]) == 1) p = a[p].f;

		if(p == 0) p = root;
		else p = get(p, miao_word[i]);

		if(ifdian[p] != vision && a[p].times != 0) {
			ret += add(p, vision);
			a[p].checks++;
		}
	}

	return ret;
}
int BFSx[N], bcnt;
void getfail() {
	queue<int> p;
	a[root].f = 0;

	for(map<int, int>::iterator itr = a[root].mp.begin(); itr != a[root].mp.end(); itr++) {
		a[itr->second].f = root;
		p.push(itr->second);
		a[itr->second].fa = root;
	}

	while(!p.empty()) {
		int u = p.front();
		p.pop();
		BFSx[++bcnt] = u;
		int j = a[u].fa;

		if(j != root) { //特判根节点周围一圈
			j = a[j].f;
			int tt = get(j, dian_word[a[u].p]);

			while(tt == 1 && j != 1) {
				j = a[j].f;
				tt = get(j, dian_word[a[u].p]);
			}

			a[u].f = tt;
		}

		if(a[a[u].f].times != 0) a[u].times += a[a[u].f].times;

		for(map<int, int>::iterator itr = a[u].mp.begin(); itr != a[u].mp.end(); itr++) { //BFS
			a[itr->second].fa = u;
			p.push(itr->second);
		}
	}
}
void getall() {
	for(int i = bcnt; i >= 1; i--) {
		int p = BFSx[i];

		for(int i = 0, len = a[p].name.size(); i < len; i++) {
			ans_a[a[p].name[i]] = a[p].checks;
		}

		a[a[p].f].checks += a[p].checks;
	}
}
//-------------------------
int init() {
	scanf("%d%d", &n, &m);
	int p = 0;

	for(int i = 1, t; i <= n; i++) {
		scanf("%d", &t);

		for(int j = p; j < p + t; j++) {
			scanf("%d", &miao_word[j]);
		}

		name[i].st1 = p;
		name[i].en1 = p + t - 1;
		p += t;
		scanf("%d", &t);

		for(int j = p; j < p + t; j++) {
			scanf("%d", &miao_word[j]);
		}

		name[i].st2 = p;
		name[i].en2 = p + t - 1;
		p += t;
	}

	p = 0;

	for(int i = 1, t; i <= m; i++) {
		scanf("%d", &t);

		for(int j = p; j < p + t; j++) {
			scanf("%d", &dian_word[j]);
		}

		insert(root, p - 1, p + t - 1, i);
		p = p + t;
	}

	getfail();

	for(int i = 1; i <= n; i++) {
		name[i].ans = check(name[i].st1, name[i].en1, i);
		name[i].ans += check(name[i].st2, name[i].en2, i);
	}

	getall();

	for(int i = 1; i <= m; i++) {
		printf("%d\n", ans_a[i]);
	}

	for(int i = 1; i < n; i++) {
		printf("%d ", name[i].ans);
	}

	printf("%d", name[n].ans);
}
//-------用map实现---------
int main() {
	root = 1, cnt = 1;
	init();
	return 0;
}
