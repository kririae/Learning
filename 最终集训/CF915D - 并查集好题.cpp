// ???
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, fa[30], cnt; 
char s[N], t[N], f[N], g[N];
inline int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
  scanf("%d", &n);
  scanf("%s%s", s + 1, t + 1);
  for (int i = 0; i < 30; ++i) fa[i] = i;
  for (int i = 1; i <= n; ++i) {
    int x = find(s[i] - 'a'), y = find(t[i] - 'a');
    if (x != y) {
      fa[x] = y;
      f[++cnt] = s[i];
      g[cnt] = t[i];
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; ++i)
    printf("%c %c\n", f[i], g[i]);
}