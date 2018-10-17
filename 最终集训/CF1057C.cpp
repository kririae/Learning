#include <bits/stdc++.h>
using namespace std;

const int N = 55;
struct Candy {
  int r, p;
  char c;
  bool operator<(const Candy &c) const { return r < c.r; }
} a[N];
int n, s, K, f[N][2005];
int main() {
  scanf("%d%d%d", &n, &s, &K);
  int st = 0;
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i].r), a[i].p = i;
  char sc[N];
  scanf("%s", sc + 1);
  for (int i = 1; i <= n; ++i)
    a[i].c = sc[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i)
    if (a[i].p == s) st = i;
  memset(f, 0x3f, sizeof f);
  f[st][a[st].r] = 0;
  for (int i = st; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (a[i].r < a[j].r && a[i].c != a[j].c)
        for (int k = 0; k <= K; ++k)
          if (k + a[i].r <= K)
            f[j][k + a[i].r] = min(f[j][k + a[i].r], f[i][k] + abs(a[j].p - a[i].p));
  cout << f[n][K];
}