#include<cstdio>
#include<cstdio>
#define N 1<<23
using namespace std;
const int LE = 0;
const int RI = 1;
int n, m, x, y, t, x2, y2, cnt;
int L[N], R[N], B[N], T[N], son[N][2], fx[N], mid[N], sum[N]; //left right bottom top  L<R B<T fx方向1-LR(x) 2-BT(y)
void change(int k, int x, int y, int c)
{
	sum[k] += c;
	if(son[k][0] == 0) {
		return;
	}
	int side = -1;
	if(fx[k] == 1 ) {
		side = mid[k] < x ? RI : LE;
	} else {
		side = mid[k] < y ? RI : LE;
	}
	change(son[k][side], x, y, c);
}
int getsum(int k, int x1, int y1, int x2, int y2) //区间和
{
	if(L[k] == x1 && R[k] == x2 && T[k] == y2 && B[k] == y1) return sum[k];
	if(fx[k] == 1 ) {
		if(mid[k] < x1 ) {
			return getsum(son[k][RI], x1, y1, x2, y2 );
		} else if(mid[k] >= x2) {
			return getsum(son[k][LE], x1, y1, x2, y2 );
		} else {
			return getsum(son[k][LE], x1, y1, mid[k], y2) + getsum(son[k][RI], mid[k] + 1, y1, x2, y2);
		}
	} else {
		if(mid[k] < y1 ) {
			return getsum(son[k][RI], x1, y1, x2, y2 );
		} else if(mid[k] >= y2 ) {
			return getsum(son[k][LE], x1, y1, x2, y2 );
		} else {
			return getsum(son[k][LE], x1, y1, x2, mid[k]) + getsum(son[k][RI], x1, mid[k] + 1, x2, y2);
		}
	}
}
void build(int &k, int x1, int y1, int x2, int y2)
{
	k = cnt++;
	L[k] = x1;
	R[k] = x2;
	T[k] = y2;
	B[k] = y1;
	if(x1 == x2 && y1 == y2) return;
	if(x2 - x1 > y2 - y1) {
		mid[k] = (x1 + x2) >> 1;
		fx[k] = 1;
		build(son[k][LE], x1, y1, mid[k], y2);
		build(son[k][RI], mid[k] + 1, y1, x2, y2 );
	} else {
		mid[k] = (y1 + y2) >> 1;
		fx[k] = 2;
		build(son[k][LE], x1, y1, x2, mid[k] );
		build(son[k][RI], x1, mid[k] + 1, x2, y2 );
	}
}
int main()
{
	scanf("%d", &n);
	int root = 0;
	cnt = 1;
	build(root, 1, 1, n, n);
	while(scanf("%d", &m) == 1 && m != 3) {
		if(m == 1) {
			scanf("%d%d%d", &x, &y, &t);
			x++;
			y++;
			change(root, x, y, t);
		} else if(m == 2) {
			scanf("%d%d%d%d", &x, &y, &x2, &y2);
			x++;
			y++;
			x2++;
			y2++;
			printf("%d\n", getsum(root, x, y, x2, y2));
		}
	}
}
