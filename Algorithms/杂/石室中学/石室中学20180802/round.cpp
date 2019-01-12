// by kririae
#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
int n, m;
int a[maxn][maxn];
inline void addedge(int u, int v) 
{
  a[u][v] = a[v][u] = 1;
}
int main()
{
  freopen("round.in", "r", stdin);
  freopen("round.out", "w", stdout);
  cin >> m;
  n = 100;
  register int i, j, k;
  for (i = 1; i <= n; ++i)
    for (j = i + 1; j <= n; ++j)
      for (k = j + 1; k <= n; ++k) {
        if(m == 0) break;
        addedge(i, j), addedge(j, k), addedge(i, k), --m;
      }
  cout << n << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      cout << a[i][j];
    cout << endl;
  }
}