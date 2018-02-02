/*
让我上下黑科技
貌似扩展树状数组可以很愉快地处理标记，还可以轻松下传
首先由于是中序遍历，所以空间严格2n+1
由于支持太多，所以可以当成zkw线段树用
由于每一部分都是相似于树状数组，所欲可以把区间拆成一个前缀和一个后缀之和，前后缀自动拆解
还可以从左到右轻松遍历，一次解决dosth update
*/
#include<cstdio>
#include<iostream>
#define N 200005
#define low(x) (x&(-x))
#define left(x) (x-(low(x)<<1))
#define bro(x) (x^(low(x)<<1))
#define up(x) ((x+bro(x))>>1)
#define down(x) ((x-1)|x)
#define lson(x) (x-(low(x)>>1))
#define rson(x) (x+(low(x)>>1))
#define whe(x) (x&(low(x)<<1))
#define dup(x) (x^((x^(x+1))>>2))
using namespace std;
inline int read()
{
	int ret = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9' ) {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * f;
}
int n, m, n2, h; //h==buf
int maxn[N], a[N];
int st[N], cnt;
/*
貌似我有一种从左至右的扫描方法
以下不是
*/
void add(int &l, int &r, int &c)
{
	cnt = 0;
	l = ((l - 1) << 1) | 1;
	r = ((r - 1) << 1) | 1;
	h = down(r);
	int t = dup(h);
	while(down(t) >= l) {
		if((t - low(t) + 1) >= l) {
			//修改该点
			maxn[t] += c;
			a[t] += c;
			//修改完毕
			t = left(t);
			if(whe(t)) h = down(t), t = dup(h); //原来为左儿子
		} else {
			st[++cnt] = t;
			t = rson(t);
		}
	}
	t = r;
	while(up(t) < n2) t = up(t), st[++cnt] = t;
	while(cnt > 0) {
		//update
		maxn[st[cnt]] = max(maxn[lson(st[cnt])], maxn[rson(st[cnt])]) + a[st[cnt]];
		//finished
		cnt--;
	}
}
inline int query(int &l, int &r)
{

}
int main()
{
	n = read();
	n2 = (n << 1) | 1;
	for(int i = 0; i < n; i++) {
		maxn[(i << 1) | 1] = read();
	}
	for(int i = 1; (1 << i) < n2; i++)
		for(int j = 1 << i; j < n2; j += 1 << (i + 1))
			maxn[j] = max(maxn[lson(j)], maxn[rson(j)]);
	m = read();
	for(int f = 1; f <= m; f++) {
		int k, l, r, c;
		k = read();
		l = read();
		r = read();
		if(k == 1) {
			c = read();
			add(l, r, c);
		} else {
			printf("%d", query(l, r));
		}
	}
	return 0;
}
