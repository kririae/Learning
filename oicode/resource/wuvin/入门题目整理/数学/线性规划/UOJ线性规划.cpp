#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 55
#define eps 1e-8
#define LD double
using namespace std;
LD A[N][N];
int Base[N];//1-m
int out[N];
int n, m, T;

//-----------------------------------------
void pivot(int h, int x) //第h个方程x变量
{
	Base[h] = x;
	LD t = A[h][x];
	for(int i = 0; i <= n; i++) A[h][i] /= t;
	for(int i = 0; i <= m; i++) {
		if((A[i][x] < eps && A[i][x] > -eps) || i == h) continue;
		t = A[i][x];
		for(int j = 0; j <= n; j++)	A[i][j] -= A[h][j] * t;
	}
}
bool Initial()
{
	int h, x;
	LD t;
	while(1) {
		h = 0, x = 0;
		t = eps;
		for(int i = 1; i <= m; i++) if(A[i][0] > t) t = A[h = i][0];
		if(h == 0) return true;
		t = -eps; //初始解 000
		for(int j = 1; j <= n; j++) if(A[h][j] < t) {
				t = A[h][x = j];
				if(j % 3 == 0)break;
			}
		//随便找一个SUB2 25TLE，最小会SUB2 39TLE
		if(x == 0) return false; //because xi>=0
		pivot(h, x);
	}
}
bool Simplex()
{
	int h, x;
	LD t;
	while(1) {
		h = x = 0;
		t = 1e10; //这里可以rand一下
		for(int i = 1; i <= n; i++) if(A[0][i] > eps) {
				x = i;
				break;
			}
		if(x == 0) return true;
		for(int i = 1; i <= m; i++) if(A[i][x] > eps && -A[i][0] / A[i][x] < t) t = -A[i][0] / A[h = i][x];
		if(h == 0) return false;
		pivot(h, x);
	}
}
//-----------------------------------------
void read()
{
	scanf("%d%d%d", &n, &m, &T);
	for(int i = 1, t; i <= n; i++) scanf("%d", &t), A[0][i] = t;
	for(int i = 1, t; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &t);
			A[i][j] = t;
		}
		scanf("%d", &t);
		A[i][0] = -t;
	}
	for(int i = n + 1; i <= n + m; i++) A[i - n][i] = 1;
	for(int i = 1; i <= m; i++) Base[i] = i + n;
	n = n + m;
}
int main()
{
	read();
	if(!Initial()) return puts("Infeasible"), 0;
	if(!Simplex()) return puts("Unbounded"), 0;
	printf("%.8lf\n", A[0][0]);
	if(T) {
		for(int i = 1; i <= m; i++) out[Base[i]] = i;
		for(int i = 1; i <= n - m; i++)
			printf("%.8lf ", (out[i] == 0 ? 0 : -A[out[i]][0]));
	}
	return 0;
}
