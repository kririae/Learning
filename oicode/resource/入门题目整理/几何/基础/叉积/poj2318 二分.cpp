#include<cstdio>
#include<algorithm>
#include<cstring>
#define for(a,b,c) for(int a=b;a<=c;a++)
#define eps 1e-8
#define INF 999999
using namespace std;
const int L = -1;
const int R = 1;
int n, m;
double x1, y1, x2, y2;
struct line { //top,y1 bot,y2 向量式
	double top, bot;
	double a, b; //a-x b-y
	void initial() {
		a = top - bot;
		b = y1 - y2;
	}
	int pd(double x, double y) {
		x -= bot;
		y -= y2;
		double xj = a * y - x * b; //叉积

		if(xj < eps) {
			return R;
		}

		return L;
	}
};
line a[5005];
int cnt = 0;
int ans[5005];
void add(double xj, double yj) {
	int left = 0;
	int right = cnt - 1;

	while(left + 1 < right) {
		int mid = (left + right) / 2;

		if(a[mid].pd(xj, yj) == L) {
			right = mid;
		} else {
			left = mid;
		}
	}

	ans[left]++;
}
int main() {
	while(scanf("%d%d%lf%lf%lf%lf", &n, &m, &x1, &y1, &x2, &y2) == 6) {
		cnt = 0;
		memset(ans, 0, sizeof(ans));
		a[cnt].top = x1;
		a[cnt++].bot = x1;

		for(i, 1, n) {
			int to, bo;
			scanf("%d%d", &to, &bo);
			a[cnt].top = to;
			a[cnt++].bot = bo;
		}

		a[cnt].top = x2;
		a[cnt++].bot = x2;

		for(i, 0, cnt - 1) {
			a[i].initial();
		}

		for(mm, 1, m) {
			int xj, yj;
			scanf("%d%d", &xj, &yj);
			add(xj, yj);
		}

		for(i, 0, n) {
			printf("%d: %d\n", i, ans[i]);
		}

		printf("\n");
	}

	return 0;
}
