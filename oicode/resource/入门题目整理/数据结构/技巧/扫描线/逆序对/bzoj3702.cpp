/*
如果利用他的逆序对划分顺序采用分治+二分
会得到nlogn^2,(某人：不是可以归并吗？ ans:归并n^2)
查询：
二分单次：mlogn
归并单次:n+m
所以二分+归并->单次nlogn/(logn-1)
但是如何做到有序？貌似必须归并。。。
还是考虑树的合并，Treap启发式合并？
如果另一颗过小直接插入。
过大，两颗压扁成链在归并，返回Treap的根节点？
脑洞够大，不过可以try 反正总复杂度nlogn

看了题解，题解表示，类似于左偏树合并线段树
详见hjt论文。这确实很快，做到了均摊logn合并
而且这个貌似更好写（9494）

e..这题有点奇怪，数组要开4000005
3600005会RE(不应该是刚好nlogn吗？)
*/
#include<cstdio>
#include<algorithm>
#define N 4000005
#define LL long long
using namespace std;
int n, cnt;
LL ans;
const int L = 0, R = 1;
//----------xds--------------
int size[N], son[N][2], fr[N], to[N];
inline void build(int &k, int fr_, int to_, int x) { //单链
	k = ++cnt;
	size[k] = 1;
	son[k][L] = son[k][R] = 0;
	fr[k] = fr_;
	to[k] = to_;

	if(fr_ == to_) {
		return;
	} else {
		int mid = (fr_ + to_) >> 1;

		if(x <= mid) build(son[k][L], fr_, mid, x);
		else build(son[k][R], mid + 1, to_, x);
	}
}
LL nxd1, nxd2; //记着清零 2-要交换
int merge(int x, int y) { //返回节点 逆序对个数装在 nxd x在y的左边  合并到x
	if(x == 0) return y;

	if(y == 0) return x;

	nxd1 += (LL)size[son[x][R]] * size[son[y][L]];
	nxd2 += (LL)size[son[x][L]] * size[son[y][R]];
	son[x][L] = merge(son[x][L], son[y][L]);
	son[x][R] = merge(son[x][R], son[y][R]);
	size[x] += size[y];
	return x;
}
//----------xds--------------
int DFS() { //返回root
	int x;
	scanf("%d", &x);

	if(x == 0) {
		int x1 = DFS();
		int x2 = DFS();
		nxd1 = nxd2 = 0;
		int a = merge(x1, x2);
		ans += min(nxd1, nxd2);
		return a;
	} else {
		int t = 0;
		build(t, 1, n, x);
		return t;
	}
}
int main() {
	scanf("%d", &n);
	DFS();
	printf("%lld", ans);
	return 0;
}
