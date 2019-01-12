#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
  freopen("chess.in", "r", stdin);
  freopen("chess.out", "w", stdout);
  scanf("%d%d", &n, &m);
  if (n == 1 || m == 1) return printf("1"), 0;
  if (n == 2) return printf("%lld", m % 2 ? m / 2 + 1 : m / 2), 0;
  if (m == 2) return printf("%lld", n % 2 ? n / 2 + 1 : n / 2), 0;
  printf("%lld", 1ll * n * m);
  return 0;
}