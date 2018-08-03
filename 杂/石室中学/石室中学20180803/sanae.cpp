// by kririae
// 妙妙的图论建模
// WA了？？？不知道为啥
// ...N没开够，father没开够...
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, ans, a[N], b[N], fa[N], all[N], cnt;
inline int find(int x)
{
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < N; ++i) fa[i] = i;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    all[++cnt] = a[i], all[++cnt] = b[i];
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