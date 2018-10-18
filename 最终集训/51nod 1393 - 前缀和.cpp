#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int n, p[N], l[N];
char s[N];
int main() {
  memset(p, 0x3f, sizeof p);
  memset(l, 0x3f, sizeof l);
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int ans = 0, u = 0;
  p[0] = 0;
  if (s[1] == '1')
    ++u;
  else
    --u;
  if (u >= 0)
    p[u] = 1;
  else
    l[u] = 1;
  for (int i = 2; i <= n; ++i) {
    if (s[i] == '1')
      ++u;
    else
      --u;
    if (u >= 0)
      ans = max(ans, i - p[u]),
      p[u] = min(p[u], i);
    else
      ans = max(ans, i - l[-u]),
      l[-u] = min(l[-u], i);
  }
  cout << ans;
}