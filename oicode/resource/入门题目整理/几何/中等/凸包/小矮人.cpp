#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define db double
#define eps 1e-8
#define N 100005
using namespace std;
/////////////////////////////////////////////
struct point {
	db x, y;
};
inline int sg(double a)
{
	if(a < eps && a > -eps) return 0;
	return a > 0 ? 1 : -1;
}
inline db cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
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
inline bool operator <(const point &a, const point &b)
{
	return a.x < b.x;
}
inline bool onleft(point &o, point &a, point &b)
{
	return sg(cross(a - o, b - o)) > 0;
}
//------------------------------------------
int n;
point p[N];
///////////////////////////////////////////库
#define tbout out
#define tbin p
#define szout cnt
#define szin n
int tbout[N];//凸包输入输出点集 逆时针 开头点算两次
int szout;//输入点集大小 输出点集大小
#define addpoint() while(szout>=p2+1&&onleft(p[tbout[szout-1]],tbin[i],p[tbout[szout]])==1) szout--;tbout[++szout]=i
void tb()
{
	sort(tbin + 1, tbin + szin + 1);
	szout = 0;
	for(int i = 1, p2 = 1; i <= n; i++) {
		addpoint();
	}
	for(int i = n - 1, p2 = szout; i >= 1; i--) {
		addpoint();
	}
}
//------------------凸包---------------------
struct seg {
	int from, to;
	db ang;
	inline bool operator <(const seg &b)const
	{
		return ang < b.ang;
	}
};
seg s[N];
int ch0, ch1, ch2;
point fr, to;
void pre()
{
	cnt--;
	for(int i = 1; i <= cnt; i++) {
		s[i].from = out[i];
		s[i].to = out[i + 1];
		s[i].ang = atan2(p[out[i + 1]].y - p[out[i]].y, p[out[i + 1]].x - p[out[i]].x);
	}
	sort(s + 1, s + cnt + 1);
	if(s[1].from != s[cnt].to) printf("WA\n");
	ch0 = s[1].from;
}
inline int find(db k)
{
	int left = 1, right = cnt + 1;
	while(left + 1 < right) {
		int mid = (left + right) >> 1;
		if(!sg(s[mid].ang - k)) return s[mid].to;
		if(s[mid].ang < k) {
			left = mid;
		} else {
			right = mid;
		}
	}
	return s[left].to;
}
bool check() //fr to 已填充
{
	db angl = atan2(fr.y - to.y, fr.x - to.x);
	ch1 = find(angl);
	angl = atan2(to.y - fr.y, to.x - fr.x);
	ch2 = find(angl);
	if((onleft(fr, to, p[ch0])^onleft(fr, to, p[ch1]) == 0) && (onleft(fr, to, p[ch2])^onleft(fr, to, p[ch1]) == 0)) {
		return true;
	}
	return false;
}
//-----------极角预处理、查询---------------
int main()
{
	scanf("%d", &n);
	if(n != 0) {
		for(int i = 1; i <= n; i++) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		tb();
		pre();
	}
	while(scanf("%lf%lf%lf%lf", &fr.x, &fr.y, &to.x, &to.y) == 4) {
		if(n == 0) {
			printf("GOOD\n");
			continue;
		}
		if(check()) printf("GOOD\n");
		else printf("BAD\n");
	}
	return 0;
}
