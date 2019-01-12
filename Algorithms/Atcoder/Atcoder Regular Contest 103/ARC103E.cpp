#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int fa[N];
char s[N];
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  if (s[1] == '0' || s[n] == '1') goto BE;
  for (int i = 1; i <= n; ++i)
    if (s[i] != s[n - i]) goto BE;
  int u = 1, ls = 1;
  fa[u] = 0;
  for (int i = 2; i <= n; --i) {
    if (s[i] == '1') {
      for (int j = 1; j <=)
      // TODO
    }
  }
BE:
  puts("-1");
  return 0;
}