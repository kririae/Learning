#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define LL long long
#define db long long
#define eps 1e-8
#define N 105
using namespace std;
/*
破题关键：无三点共线
题解，先来个三角剖分
在逐个尝试加点，构成最优凸包
最后答案的凸包一定满足一个性质：
将一个友军点加入到凸包中，会亏损
将一个友军点删除，重求凸包，不会更优。
首先不采用三角剖分时间复杂度为：O（n^4）貌似会挂
采用三角剖分预处理： O（n^2logn+n^3） 无压力过
*///所有数组统一从0开始放
const int L = 0, R = 1;
const int FR = 1, EN = 3; //friend eney
/////////////////几何库////////////////////////
inline int read()
{
	char c = getchar();
	int ret = 0;
	while(c == ' ' || c == '\n') c = getchar();
	while(c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret;
}
struct point {
	db x, y;
	int kind;
};
inline point operator -(point &a, point &b)
{
	return (point) {
		a.x - b.x, a.y - b.y
	};
}
inline bool equ(db &a, db &b)
{
	return a == b;
}
inline db cross(point &a, point &b)
{
	return a.x * b.y - b.x * a.y;
}
//------------变量---------------------------------
int n, pr, t;
point p[N];
/////////////////梯形剖分（更好写）//////////////////////////
//----------变量区域--------------------
int f[N][N];
int cnt, root;
int son[N][2], pri[N];
db key[N], val[N], sum[N]; //key-极角
//--------------Treap------------------------
inline void recount(int k)
{
	sum[k] = sum[son[k][L]] + sum[son[k][R]] + val[k];
}
inline void turn(int &k, int side)
{
	int t = son[k][side ^ 1];
	son[k][side ^ 1] = son[t][side];
	son[t][side] = k;
	recount(k);
	k = t;
	recount(k);
}
void build(int &k, double key_, db val_)
{
	if(k == 0) {
		k = ++cnt;
		son[k][L] = son[k][R] = 0;
		pri[k] = rand();
		key[k] = key_;
		sum[k] = val[k] = val_;
		return;
	}
	sum[k] += val_;
	int si = key_ < key[k] ? 0 : 1;
	build(son[k][si], key_, val_);
	if(pri[son[k][si]] > pri[k] ) turn(k, si ^ 1);
	return;
}
db getmin(int &k, double key_) //获取所有比KEY_更小的节点的val和
{
	if(k == 0) return 0;
	int si = key_ < key[k] ? 0 : 1;
	db ret = key_ < key[k] ? 0 : val[k] + sum[son[k][L]];
	return ret + getmin(son[k][si], key_);
}
void pre()
{
	cnt = 0;
	root = 0;
}
//--------------------下面是梯形剖分（梯形剖分保平安，三角剖分终要完）-------------------------------
inline bool cmp(const point &a, const point &b)
{
	if(a.y == b.y) return a.x < b.x;
	return a.y > b.y;
}
inline double getangle(point &a, point &b)
{
	return atan2(b.y - a.y, b.x - a.x);
}
void cut()
{
	sort(p, p + n, cmp);
	for(int i = 0; i < n; i++) {
		if(p[i].kind == EN) continue;
		pre();
		for(int j = i + 1; j < n; j++) {
			double ang = getangle(p[i], p[j]);
			build(root, ang, p[j].kind - 2);
			if(p[j].kind == FR) f[i][j] = f[j][i] = getmin(root, ang + eps); //包括自己
		}
	}
}
/////////////////////////////////////////////////////////////
int main()
{
	scanf("%d%d", &p, &t);
	n = pr + t;
	for(int i = 0; i < pr; i++) {
		p[i].x = read();
		p[i].y = read();
		p[i].kind = EN;
	}
	for(int i = pr; i < pr + t; i++) {
		p[i].x = read();
		p[i].y = read();
		p[i].kind = FR;
	}
	cut();

	return 0;
}
