#include<cstdio>
#include<iostream>
using namespace std;
/*
回顾一下LCT怎么写，基本忘了

这次我才发现原来我写的lct没有link操作
这下有了link和换根操作，树上父亲就不能保留了
子节点指向父节点
父节点不保存子节点来表示虚边
(son[fa[t]][0]==t||son[fa[t]][1]==t)
树上的虚边是子splay的root上的fa
为什么我要T？
死循环？
woc 调了一晚上就没有发现自己pushdown都写错了，忘了标记下传了
还有 pushdown的顺序别忘了从高到低！
看我A了
*/
#define N 100005
//-------大家好 我是LCT---------------
const int L = 0, R = 1;
int buf;
#define swp(x,y) (buf=x,x=y,y=buf)
#define rt(x) (a[a[(x)].fa].son[L]!=(x)&&a[a[(x)].fa].son[R]!=(x))
struct Splay {
	int fa, son[2];
	//int tfa;
	int rv;
} a[N];
int cnt;
inline void rotate(const int x, int &k) { //因为是spaly 所以要注意fa的更改
	int y = a[x].fa;
	int z = a[y].fa;
	int s = a[y].son[R] == x;
	a[y].son[s] = a[x].son[s ^ 1];
	a[a[y].son[s]].fa = y;
	a[x].son[s ^ 1] = y;
	a[x].fa = z;
	a[y].fa = x;

	if(y == k)  k = x;
	else a[z].son[a[z].son[R] == y] = x;

	//update
}
inline void pushdown(int x) {
	//if(a[x].rv) a[x].rv=0,swp(a[x].son[L],a[x].son[R]);错误示范
	if(a[x].rv) a[x].rv = 0, swp(a[x].son[L], a[x].son[R]), a[a[x].son[L]].rv ^= 1, a[a[x].son[R]].rv ^= 1;
}
inline void splay(const int x, int to) {
	int y, z;

	while(x != to) {
		y = a[x].fa;
		z = a[y].fa;
		//pushdown(x);pushdown(y);pushdown(z);pushdown(a[z].fa); 错误示范
		pushdown(a[z].fa);
		pushdown(z);
		pushdown(y);
		pushdown(x);

		if(y != to) {
			if((a[y].son[R] == x) ^ (a[z].son[R] == y)) rotate(x, to);
			else rotate(y, to);
		}

		rotate(x, to);
	}

	a[0].fa = 0;
	a[0].rv = 0;
}
inline int splay_rt(int x) {
	while(!rt(x)) x = a[x].fa;

	return x;
}
inline int ch_top(int x) {
	x = splay_rt(x);  //链端

	while(a[x].son[L ^ a[x].rv]) x = a[x].son[L ^ a[x].rv];

	splay(x, splay_rt(x));
	return x;
}
inline void chg_right(int x, int b) {
	splay(x, splay_rt(x));
	pushdown(x);
	a[x].son[R] = b;
}
inline void access(int x) {
	chg_right(x, 0);

	for(int t = a[(x = ch_top(x))].fa; t; chg_right(t, x), t = a[(x = ch_top(x))].fa);
}
inline int tree_rt(int x) {
	access(x);
	return ch_top(x);
}
inline void cut(int x, int y) {
	chg_right(x, 0);
	chg_right(y, 0);

	if(a[ch_top(y)].fa == x) a[y].fa = 0;
	else a[x].fa = 0;
}
inline void make_rt(int x) {
	access(x);
	splay(x, splay_rt(x));
	a[x].rv ^= 1;
}
//inline void cut(int x,int y){make_rt(x);access(y);splay(y,splay_rt(y));pushdown(y);a[y].son[L]=a[x].fa=0;}
inline void link(int x, int to) {
	make_rt(x);
	a[x].fa = to;
}
//---------------------- ---------------
int ret;
char ch;
#define rd(x) (read(),x=ret)
inline void read() {
	for(ret = 0, ch = getchar(); ch < '0' || ch > '9'; ch = getchar());

	for(; ch >= '0' && ch <= '9'; ret = ret * 10 + ch - '0', ch = getchar());
}
int n, m;
char ins[20];
int main() {
	scanf("%d%d", &n, &m);
	cnt = n;

	for(int i = 1, x, y; i <= m; i++) {
		scanf("%s", ins);
		rd(x);
		rd(y);

		if(ins[0] == 'Q') {
			int t1, t2;
			t1 = tree_rt(x);
			t2 = tree_rt(y);

			if(t1 == t2) puts("Yes");
			//if(tree_rt(x)==tree_rt(y)) puts("Yes");
			else puts("No");
		} else if(ins[0] == 'C') {
			link(x, y);
		} else if(ins[0] == 'D') {
			cut(x, y);
		}
	}

	return 0;
}
