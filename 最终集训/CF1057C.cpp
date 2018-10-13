#include <bits/stdc++.h>
using namespace std;

const int N = 55;
struct Candy {
  int r, p;
  char c;
  bool operator < (const Candy &c) const { return r < c.r; }
} a[N];
int n, s, k, f[N][2005];
int main() {
  scanf("%d%d%d", &n, &s, &k);
  int st = 0;
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i].r), a[i].p = i;
  char sc[N];
  scanf("%s", sc + 1);
  for (int i = 1; i <= n; ++i)
    a[i].c = sc[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i)
    if (a[i].p == s)
      st = i;
  memset(f, 0x3f, sizeof f);
  for (int i = 1; i <= n; ++i) {}
}