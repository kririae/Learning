#include<cstdio>
#include<algorithm>
#define N 7505
#define db double
#define eps 1e-8
using namespace std;
//------------------------
struct point {
	db x, y;
};
inline int sg(double a) {
	if(a < eps && a > -eps) return 0;

	return a > 0 ? 1 : -1;
}
inline db cross(point a, point b) {
	return a.x * b.y - a.y * b.x;
}
inline point operator -(const point &a, const point &b) {
	return (point) {
		a.x - b.x, a.y - b.y
	};
}
inline point operator +(const point &a, const point &b) {
	return (point) {
		a.x + b.x, a.y + b.y
	};
}
inline bool operator <(const point &a, const point &b) {
	return a.x < b.x;
}
inline int onleft(point &o, point &a, point &b) {
	return sg(cross(a - o, b - o));
}
//------------------------
point tbin[N], tbout[N]; //凸包输入输出点集 逆时针 开头点算两次
int szin, szout; //输入点集大小 输出点集大小
#define addpoint() while(szout>=p+1&&onleft(tbout[szout-1],tbin[i],tbout[szout])==1) szout--;tbout[++szout]=tbin[i]
void tb() {
	sort(tbin + 1, tbin + szin + 1);
	szout = 0;

	for(int i = 1, p = 1; i <= n; i++) {
		addpoint();
	}

	for(int i = n - 1, p = szout; i >= 1; i--) {
		addpoint();
	}
}
//-------------------------
int main() {

	return 0;
}
