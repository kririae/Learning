/*
英雄所见略同
在我第一个AC自动机时
我说这东西可以加矩阵
果真就有加矩阵的题
上次的递推式可以优化
递推式记录不出现模式串的个数
然后总数减一减就对了

此题实在训练细节
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#define LL unsigned long long
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int H = 30, L = 30;
const LL NY1 = 1033017668; //25 关于2^64的逆元
const LL NY2 = 1277348905;
LL NY;
//------------------------
int read(int p, int *b) {
	char c = getchar();

	while(c == '\n' || c == '\r' || c == ' ') c = getchar();

	while(c >= 'a' && c <= 'z') b[++p] = c - 'a' + 1, c = getchar();

	return p;
}
//------------------------
struct matrix { //可以常数优化不少 全局分配  连续寻址
	LL a[H][L];
	matrix() {
		memset(a, 0, sizeof(a));
	}
	matrix(const matrix &c) {
		for(int i = 0; i < H; i++)
			for(int j = 0; j < L; j++)
				a[i][j] = c.a[i][j];
	}
	void clear() {
		memset(a, 0, sizeof(a));
	}
	matrix operator *(const matrix &b) {
		matrix c;

		/*for(int i=1;i<H;i++)
			for(int j=1;j<L;j++)
				for(int k=1;k<H;k++)
					c.a[i][j]+=a[i][k]*b.a[k][j];
		*/
		for(int i = 1; i < H; i++)
			for(int k = 1; k < H; k++)
				for(int j = 1; j < L; j++)
					c.a[i][j] += a[i][k] * b.a[k][j];

		return c;
	}
};
//------------------------
struct AC_atom {
	int val, p;
	int ne[27];
	int f;
} a[H];
int root, cnt;
void insert(int &k, int st, int en, int *w) {
	if(k == 0) {
		k = ++cnt;
		a[k].p = st;
	}

	if(st == en) a[k].val = 1;
	else insert(a[k].ne[w[st + 1]], st + 1, en, w);
}
void get_fail() {
	queue<int> q;

	for(int i = 1; i <= 26; i++) {
		if(a[root].ne[i] != 0) {
			q.push(a[root].ne[i]);
			a[a[root].ne[i]].f = root;
		} else a[root].ne[i] = root;
	}

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		if(a[a[u].f].val == 1) a[u].val = 1;

		for(int i = 1; i <= 26; i++) {
			if(a[u].ne[i] == 0) {
				a[u].ne[i] = a[a[u].f].ne[i];
			} else {
				a[a[u].ne[i]].f = a[a[u].f].ne[i];
				q.push(a[u].ne[i]);
			}
		}
	}
}
//------------------------
matrix trans, base;
const int PANS = H - 1;
void pre() {
	trans.clear();
	base.clear();

	for(int i = 1; i <= cnt; i++) {
		if(a[i].val == 1) continue;

		for(int j = 1; j <= 26; j++) {
			trans.a[a[i].ne[j]][i]++;
		}

		trans.a[PANS][i]++;
	}

	trans.a[PANS][PANS] = 1;
	base.a[1][1] = 1;
}
//------------------------
matrix cal(matrix ba, LL ti) {
	if(ti == 1) return ba;

	matrix t = cal(ba, ti >> 1);

	if(ti & 1) {
		return (t * t) * ba;
	} else {
		return t * t;
	}
}
LL caln(LL ba, LL ti) {
	if(ti == 1) return ba;

	int t = caln(ba, ti >> 1);

	if(ti & 1) {
		return t * t * ba;
	} else {
		return t * t;
	}
}
//------------------------
int n, m;
int word[H];
void init() {
	NY = NY1 * 10000000000 + NY2;

	while(scanf("%d%d", &n, &m) == 2) {
		for(int i = 0; i < H; i++) memset(a[i].ne, 0, sizeof(a[i].ne)), a[i].f = a[i].val = a[i].p = 0;

		root = 1;
		cnt = 1;

		for(int i = 1; i <= n; i++) {
			int p = 0;
			int t = read(p, word);
			insert(root, p, t, word);
			p = t;
		}

		get_fail();
		pre();
		matrix ans = (trans * cal(trans, m)) * base;
		LL out = (caln(26, (LL)m + (LL)1) - 1) * NY;
		LL jian = ans.a[PANS][1];

		if(out < jian) {
			LL maxn = 0;
			out = (~maxn) - jian + out + 1;
		} else {
			out = out - jian;
		}

		cout << out << endl;
	}
}
int main() {
	init();
	return 0;
}
