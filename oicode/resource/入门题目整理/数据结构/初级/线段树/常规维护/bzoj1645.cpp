/*
这题可以STL水过、值域线段树、平衡树水过
但我还是换个方法练一下区间取max吧。
让我回忆一下区间取max
详见WC营员交流segment tree beats
等等貌似还要离散化和重赋权。。。
不管了，硬着做。。。。（区间取max真不是好主意）。
区间取max可以让这道题变成动态（可以修房子了）
如果可以离线好像也没有什么其他的方法。
不对啊，这个高度值要成double。。。。不过没什么影响
等等高度值最大可以是10^18，double和longdouble的精度要挂
好吧，这题本来就不是拿来取max玩的。
就记着取max的题要保存fimin,semin以及各自的个数就对了。
留坑
*/
#include<cstdio>
#include<iostream>
#define N 200005
using namespace std;
int n, m, cnt, root;
const int L = 0, R = 1;
struct opera {
	int l, r, h;
	double hi;
	LL li, ri;
} q[40005];
struct lshh {
	int *a;
	int name;
} lsh[80005];
//--------xds-----------

//----------------------
void pre() {
	for(int i = 1; i <= m; i++) {
		lsh[i * 2 - 1].a = &q[i].l;
	}
}
//----------------------
int main() {


	return 0;
}