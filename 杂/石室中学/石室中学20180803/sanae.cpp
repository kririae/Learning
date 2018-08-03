// by kririae
// 妙妙的图论建模
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5 + 5;
int n, ans, a[maxn], b[maxn], fa[maxn], all[maxn << 1], cnt;
inline int find(int x)
{
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main()
{
  freopen("sanae.in", "r", stdin);
  freopen("sanae.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < maxn; ++i) fa[i] = i;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    // 对于a[i] == b[i]的情况，直接continue
    if(a[i] == b[i]) ++ans;
    else all[++cnt] = a[i], all[++cnt] = b[i];
  }
  sort(all + 1, all + 1 + cnt);
  int siz = unique(all + 1, all + 1 + cnt) - all - 1;
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(all + 1, all + 1 + siz, a[i]) - all,
    b[i] = lower_bound(all + 1, all + 1 + siz, b[i]) - all;
  for (int i = 1; i <= n; ++i) {
    int x = find(a[i]), y = find(b[i]);
    if(x == y) ++ans;
    else fa[x] = y;
  }
  printf("%d\n", ans);
}