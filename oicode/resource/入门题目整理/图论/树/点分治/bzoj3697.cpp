/*
突然发现原来我的点分治一直搞错了
没有按照中心划分、可以被卡掉
但当时数据太弱
感觉点分治一点都不好写
*/
#include<cstdio>
#include<vector>
#define N 100005
using namespace std;
int n, m, ans;
//-----------------
struct nodes {
	int color, size;
	vector<int> x;
} node[N];
//-----------------
int vis[N], root, hf; //用于重心划分
int DFS(int u, int fr) //求重心
{
	node[u].size = 0;
	for(int i = 0, len = node[u].x.size(); i < len; i++) {
		if(node[u].x[i] != fr && vis[node[u].x[i]] != 1) {
			node[i].size += DFS(node[u].x[i], u);
		}
	}
	if(node[u].size >= hf && u == -1) root = u;
	return node[u].size;
}
//-----------------
struct msg {
	int anc, dis, reset; //所属子树、到根值和、是否有休息点
} source[N];
int gxy[N * 2]; //N==0 -N~0~N其实理论上开一个N就够了，因为是重心
inline void make_mark(int fr, int to, int f)
{
	for(int i = fr; i <= to; i++) {
		gxy[source[i].dis] += f;
	}
}
int calc(int fr, int to)
{
	make_mark(fr, to, 1);
	for(int i = fr; i <= to; i++) {

	}
}
int DFS2(int u, int anc, int fr) //顺带解决子树大小问题  这个休息点标记有点难处理啊，投子
{

}
void solve(int u)
{
	//--------------先处理
	int buf = 1;
	for(int i = 0, len = node[u].x.size(); i < len; i++) {
		if(vis[node[u].x[i]] != 1) { //收集信息处理
			DFS2(node[u].x[i], node[u].x[i], u); //预处理子树size信息
			int t = node[node[u].x[i]].size;
			ans -= calc(buf, buf + t - 1); //减去子树内重复
			buf += t; //滑动区间
		}
	}
	source[buf].dis = 0;
	source[buf].reset = 0;
	ans += calc(1, buf); //全区间处理
	//--------------再处理子树
	vis[u] = 1;
	for(int i = 0, len = node[u].x.size(); i < len; i++) {
		if(vis[node[u].x[i]] != 1) {
			root = -1;
			hf = node[node[u].x[i]].size / 2;
			DFS(node[u].x[i], u);
			solve(root);
		}
	}
	//--------------
}
//-----------------
void init()
{

}
//-----------------
int main()
{
	init();
	root = -1;
	hf = n / 2;
	DFS(1, 0);
	solve(root);
	printf("%d\n", ans);
	return 0;
}
