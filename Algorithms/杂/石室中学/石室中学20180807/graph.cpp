#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const double eps = 1e-6;
struct Matrix
{
int n, m, rk;
// n -> 行数 m -> 列数
double ma[N][N];
double* operator [] (int x) { return ma[x]; }
void convert()
{
  for (R int k = 1; k <= m; ++k) {
    double maxv = -1e9;
    int maxp = k + 1;
    for (R int i = k + 1; i <= n; ++i)
      if(ma[i][k] > maxv) maxv = ma[i][k], maxp = i;
    if(maxp != k + 1)
    for (int j = 1; j <= m; ++j) 
      swap(ma[k + 1][j], ma[maxp][j]);
    for (R int i = k + 1; i <= n; ++i) {
      double d = ma[k][k] / ma[i][k];
      for (R int j = 1; j <= m; ++j) 
        ma[i][j] *= d, ma[i][j] -= ma[k][j];
    }
  }
  for (R int i = 1; i <= n; ++i) 
    for (R int j = 1; j < m; ++j) 
      if(fabs(ma[i][j]) > eps) 
      { ++rk; break; }
}
void trace()
{
  for (R int k = m - 1; k >= 1; --k)
    for (R int i = n - 1 - (m - 1 - k); i >= 1; --i) {
      double d = ma[k][k] / ma[i][k];
      for (R int j = m; j >= 1; --j) 
        ma[i][j] *= d, ma[i][j] -= ma[k][j];
    }
}
Matrix() { memset(ma, 0, sizeof(ma)); }
Matrix(int a, int b) : n(a), m(b) { }
} x;
int n, m, head[N], ver[N << 1], nxt[N << 1], tot; double a[N][N], len[N];
inline void addedge(int u, int v)
{
  ver[tot] = v, nxt[tot] = head[u], head[u] = tot++;
}
int main()
{
  freopen("graph.in", "r", stdin);
  freopen("graph.out", "w", stdout);
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &m);
  if(n > 100) return puts("0"), 0;
  for (int i = 1; i <= n; ++i)
    scanf("%lf", &x[i][m + 1]), x[i][m + 1] *= 100;
  x.n = n, x.m = m + 1;
  for (int i = 1, a, b; i <= m; ++i)
    scanf("%d%d", &a, &b), addedge(a, b), addedge(b, a);
  for (int i = 1; i <= n; ++i)
    for (int j = head[i]; ~j; j = nxt[j])
      x[i][(j >> 1) + 1] = 50;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m + 1; ++j)
      if(fabs(x[i][j]) < eps) x[i][j] = 1e-4;
  x.convert(), x.trace();
  if(x.rk != n) return puts("0"), 0;
  for (R int i = 1; i <= n; ++i)
    if(round(x.ma[i][n + 1] / x.ma[i][i]) == -0) printf("0\n");
    else printf("%.0lf\n", x.ma[i][n + 1] / x.ma[i][i]);
}