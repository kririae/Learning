#include<bits/stdc++.h>
using namespace std;
#define N 10000
#define G(x) (rand()*rand()%(x)+1)
int ecnt;
struct edge {
	int f, t;
	edge() {}
	edge(int ff, int tt)
	{
		f = ff;
		t = tt;
	}
} e[N * 2];
int to[N], mark[N];
int deep[N];
void make(int fr, int aim)
{
	int p = fr, cnt = 0;
	while(mark[to[p]] != 1 && p != aim) cnt++, p = e[to[p]].t;
	if(cnt >= 2) {
		e[++ecnt] = edge(fr, p);
		int t = fr;
		while(t != p) mark[to[t]] = 1, t = e[to[t]].t;
	}
}
int rd(int u)
{
	int t = u;
	while(e[to[t]].t != 0 && (rand() % 3 != 1)) t = e[to[t]].t;
	return t;
}
int main()
{
	int n = N;
	srand(time(0));
	int mxdp = 0;
	for(int i = 2, t; i <= n; i++) e[i - 1] = edge(i, t = (rand() % (n / 5) != 1) ? i - 1 : G(i - 1)), mxdp = max(mxdp, deep[i] = deep[t] + 1), to[i] = i - 1;
	ecnt = n - 1;
	make(G(n), 1);
	for(int i = 1; i <= n; i++) make(i, rd(i));
	printf("%d %d\n", n, ecnt);
	for(int i = 1; i <= ecnt; i++) printf("%d %d\n", n - e[i].f + 1, n - e[i].t + 1);
	return 0;
}
