/*
分治+bcj
考虑贡献，由于一个边出现的时间段只会是连续的
因此只会被分成logn个时间区间，所以复杂度logn
如果在时间线上建立一个线段树可以支持加入一条边
单点查询是否是二分图，或者查询在某个时间段内是否是二分图
分治不好写，还是线段树好写，但是空间有点吓人，如果要初始化
bcj数组，那么会达到n^2
由于分治不能与全局有关所以只能照着改回去
（线段树）：我怎么办？
线段树套可持久化bcj，真是呵呵了，复杂度就成两个log了
建立nlogn^2
单点查询logn
修改。。。。看来还要再套一个，达到三个logn
//-------------------------------------
建立n^2
单点logn
单修logn
修改。。由于修改就必须加tag，由于tag信息必须可以简单合并，
但这是bcj
//---------------
算了还是去考虑lct的做法吧
//------------------------------
我想到了
线段树的节点只储存边，那么每次查询用一个bcj
顺着改下去，查完了在改回来
那么时间区间为1-N，有M个插曲，Q个查询
建立nlogn
插入mlogn
（数据随机的话）查询Qlogn(loglogn)
如果不随机就
*/
#include<cstdio>
#include<iostream>
#define N 100005
using namespace std;
struct event {
	int *pl;
	int val;
};
struct interval {
	int f, t, start, end;
};
int ans[N];
int tttbuf;
interval qj[N * 2];
int buf[20][N * 2], bufcnt[20];
//--------------------------------
#define swapwkl(x,y) tttbuf=x,x=y,y=tttbuf
event ev_stack[N * 6];
int evcnt;
int bcj[N], size[N], dis[N];
int ff(int x)
{
	while(bcj[x] != x) x = bcj[x];
	return x;
}
inline int getdis(int x)
{
	int ret = 0;
	while(bcj[x] != x) ret += dis[x], x = bcj[x];
	return ret;
}
bool connect(int f, int t)
{
	int vf = ff(f), vt = ff(t);
	if(vf == vt) {
		if(!((getdis(f) + getdis(t)) & 1)) return false;
	} else {
		if(size[vf] > size[vt]) swapwkl(vf, vt);
		ev_stack[++evcnt] = (event) {
			&bcj[vf], bcj[vf]
		};
		ev_stack[++evcnt] = (event) {
			&size[vt], size[vt]
		};
		ev_stack[++evcnt] = (event) {
			&dis[vf], dis[vf]
		};
		bcj[vf] = vt;
		size[vt] += size[vf];
		dis[vf] = getdis(t) + getdis(f) + 1;
	}
	return true;
}
inline void backto(int times)
{
	for(; evcnt > times; evcnt--)*ev_stack[evcnt].pl = ev_stack[evcnt].val;
}
//--------------------------------
void cdq(int fr, int to, int deep)
{
	int newcnt = 0;
	for(int i = 1; i <= bufcnt[deep]; i++) {
		interval &it = qj[buf[deep][i]];
		if(it.start <= fr && it.end >= to) {
			if(!connect(it.f, it.t)) {
				for(int j = fr; j <= to; j++) ans[j] = 1;
				return;
			}
		} else buf[deep][++newcnt] = buf[deep][i];
	}
	if(fr == to || newcnt == 0) return;
	int t1 = evcnt, mid = (fr + to) >> 1;
	bufcnt[deep + 1] = 0;
	for(int i = 1; i <= newcnt; i++) {
		if(qj[buf[deep][i]].start <= mid) buf[deep + 1][++bufcnt[deep + 1]] = buf[deep][i];
	}
	cdq(fr, mid, deep + 1);
	backto(t1);
	bufcnt[deep + 1] = 0;
	for(int i = 1; i <= newcnt; i++) {
		if(qj[buf[deep][i]].end > mid) buf[deep + 1][++bufcnt[deep + 1]] = buf[deep][i];
	}
	cdq(mid + 1, to, deep + 1);
	backto(t1);
}
int n, m, T;
int main()
{
	scanf("%d%d%d", &n, &m, &T);
	for(int i = 1; i <= n; i++) bcj[i] = i, size[i] = 1;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &qj[i].f, &qj[i].t, &qj[i].start, &qj[i].end);
		buf[0][i] = i;
		qj[i].start++;
	}
	bufcnt[0] = m;
	cdq(1, T, 0);
	for(int i = 1; i <= T; i++) {
		if(ans[i] == 1) puts("No");
		else puts("Yes");
	}
	return 0;
}
