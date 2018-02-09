#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<queue>
#define LL long long
#define db long double
#define eps 1e-8
#define N 500005
using namespace std;
const double KK = 1;
inline int read()
{
	char c = getchar();
	int ret = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret;
}
struct point {
	db x, y;
};
struct line {
	point a, b; //p1->p2
	db angle;
	bool operator <(const line &b)const
	{
		return angle < b.angle;
	}
	void cal()
	{
		angle = (b.y - a.y) / (b.x - a.x);
	}
};
inline point operator -(const point &a, const point &b)
{
	return (point) {
		a.x - b.x, a.y - b.y
	};
}
inline point operator +(const point &a, const point &b)
{
	return (point) {
		a.x + b.x, a.y + b.y
	};
}
inline point operator *(const point &a, const db b)
{
	return (point) {
		a.x*b, a.y*b
	};
}
bool operator<(const point &a, const point &b)
{
	return a.x < b.x;
}
inline double getdis(point &a, point &b)
{
	point c = a - b;
	return sqrt(c.x * c.x + c.y * c.y);
}
inline bool equ(db a, db b)
{
	return fabs(a - b) < eps;
}
inline db cross(point a, point b)
{
	return a.x * b.y - b.x * a.y;
}
inline bool onleft(const point &o, const point &a, const point &b)
{
	return cross(a - o, b - o) > -eps;
}
inline point get_inter(const line &a, const line &b) //&
{
	db p1 = cross(a.b - a.a, b.b - a.a);
	db p2 = cross(a.b - a.a, b.a - a.a);
	return (b.b - b.a) * (p2 / (p2 - p1)) + b.a;
}
///////////////////////////////////////////库
//--------------动态维护半平面交-------------
/*
不会维护半平面交怎么办，反演成凸包？
太优越了 算了
要支持动态半平面+点logn查询
貌似反演成凸包更好做
点怎么反演？
此题取一个上帝视角就成了平面可见直线了
如何判断一个点的问题
首先要找到点与该凸包的切线交点
如果点在凸包里，过点的任意一条直线都会和凸包相交
可以根据斜率进行二分。。。
不对，我还是去看题解吧
（看了回来）题解直接把问题中圆反演成了点
点成了半平面。。。。。
orzzzzzzzzzzzzzzzzzzzzz
算了不会做怎么办，就当练习cdq吧，相信两个logn+大常数死不了
*/
//----------------cdq---------------------------
struct things {
	int kind;
	line p;//如果是询问就放在p1
	bool ans;
} problem[N];
//------------------
point tub[N];
int tbcnt;//常数大点就大点吧，反正不卡常
line buf[N];
line bpm[N];
line left = (line)
{
	(point) {-1e12 - eps * 100, 10}, (point) {-1e12, 9}, 0
};
line right = (line)
{
	(point) {1e12 + eps * 100, 10}, (point) {1e12, 9}, 0
};
line bottom = (line)
{
	(point) {-1e12, -1e12}, (point) {1e12, -1e12}, 0
};
void build(int fr, int to) //建立半平面再转成凸包
{
	int bpmcnt = 0;
	int cnt = 0;
	left.cal();
	right.cal();
	bottom.cal();
	tbcnt = 0;
	for(int i = fr; i <= to; i++) {
		if(problem[i].kind == 0) buf[++cnt] = problem[i].p;
	}
	buf[++cnt] = bottom;
	sort(buf + 1, buf + cnt + 1);
	for(int i = 1; i <= cnt; i++) {
		while(bpmcnt > 1 && onleft(bpm[bpmcnt].a, bpm[bpmcnt].b, get_inter(bpm[bpmcnt - 1], buf[i]))) bpmcnt--;
		bpm[++bpmcnt] = buf[i];
	}
	tub[++tbcnt] = get_inter(bpm[1], left);
	for(int i = 1; i < bpmcnt; i++) {
		tub[++tbcnt] = get_inter(bpm[i], bpm[i + 1]);
	}
	tub[++tbcnt] = get_inter(bpm[bpmcnt], right);
}
void query(int fr, int to) //计算单步贡献
{
	for(int i = fr; i <= to; i++) {
		if(problem[i].ans == 0 && problem[i].kind == 1) {
			point* t = lower_bound(tub + 1, tub + tbcnt + 1, problem[i].p.a);
			if(t == tub + tbcnt + 1) {
				problem[i].ans = 1;
				continue;
			} else if(t == tub + 1) {
				if(problem[i].p.a.y < tub[1].y - eps) {
					problem[i].ans = 1;
					continue;
				}
				//TLE

			} else {
				point* fr = t - 1;
				if(!onleft((*fr), *t, problem[i].p.a)) {
					problem[i].ans = 1;
					continue;
				}
			}
		}
	}
}
//-------------------
void solve(int fr, int to) //CDQ分治好像很好理解，不错，不错
{
	if(fr + 10 >= to) { //暴力
		for(int i = fr; i <= to; i++) if(problem[i].kind == 1 && problem[i].ans == 0)
				for(int j = fr; j <= i; j++) if(problem[j].kind == 0)
						if(!onleft(problem[j].p.a, problem[j].p.b, problem[i].p.a)) {
							problem[i].ans = 1;
							break;
						}
	} else {
		int mid = (fr + to) >> 1;
		solve(fr, mid);
		solve(mid + 1, to);
		build(fr, mid);
		query(mid + 1, to);
	}
}
//-----------------------------------------------
int n;
int main()
{
	n = read();
	int fl = 0;
	for(int i = 1; i <= n; i++) {
		int ins = read();
		point p;
		scanf("%llf%llf", &p.x, &p.y);
		problem[i].kind = ins;
		if(ins == 0) {
			db dis = sqrt(p.x * p.x + p.y * p.y);
			db dis2 = KK / dis;
			p = p * (dis2 * (1 / dis) * 0.5);
			problem[i].p.a = p;
			problem[i].p.b = (point) {
				p.x + (p.y / p.x * 10), p.y - 10
			};
			if(problem[i].p.b.x < problem[i].p.a.x) swap(problem[i].p.a, problem[i].p.b);
			problem[i].p.cal();
			fl = 1;
		} else {
			if((p.y < eps && p.x < eps && p.y > -eps && p.x > -eps) || (fl == 0)) {
				if(fl) {
					problem[i].kind = 3;
					problem[i].ans = 0;
					continue;
				}
				problem[i].kind = 3;
				problem[i].ans = 1;
				continue;
			}
			db dis = sqrt(p.x * p.x + p.y * p.y);
			db dis2 = KK / dis;
			p = p * (dis2 * (1 / dis));
			problem[i].p.a = p;
		}
	}
	solve(1, n);
	for(int i = 1; i <= n; i++) {
		if(problem[i].kind == 1 || problem[i].kind == 3) {
			if(problem[i].ans == 0) {
				puts("Yes");
			} else {
				puts("No");
			}
		}
	}
	return 0;
}
