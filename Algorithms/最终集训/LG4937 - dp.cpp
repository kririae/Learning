#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 2005;
struct Obj {
  int t, d, c, id;
  bool operator<(const Obj &a) const { return d < a.d; }
} a[N];
int n, f[N][M], t[N][M];
vector<int> res;
int main() {
  memset(f, -1, sizeof f);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].c), a[i].id = i;
  sort(a + 1, a + 1 + n);
  f[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 2001; ++j) f[i][j] = f[i - 1][j];
    for (int j = a[i].t; j <= a[i].d - 1; ++j) {
      // if (j > a[i].d) break;
      if (~f[i - 1][j - a[i].t])
        if (f[i][j] < f[i - 1][j - a[i].t] + a[i].c) {
          f[i][j] = f[i - 1][j - a[i].t] + a[i].c;
          t[i][j] = 1;
        }
    }
  }
  int ans = 0, p = 0;
  for (int j = 0; j <= 2001; ++j)
    if (f[n][j] >= ans) {
      ans = f[n][j];
      p = j;
    }
  cout << ans << endl;
  for (int i = n; i >= 1; --i)
    if (t[i][p]) {
      res.push_back(a[i].id);
      p -= a[i].t;
    }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); ++i)
    cout << res[i] << " ";
}