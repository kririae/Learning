#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N], b[N], vis[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  int p = 1;
  for (int i = 1; i <= n; ++i) {
    if (vis[b[i]]) {
      printf("%d ", 0);
      continue;
    }
    int cnt = 0;
    while (a[p] != b[i]) ++p, ++cnt;
    printf("%d ", cnt);
  }
}