#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, m, q;
ll a[N], cnt[N], add[N], st[N];
double ans[N];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &a[i]);
  for (int i = 1, c, l, r, x; i <= m; ++i) {
    scanf("%d%d%d%d", &c, &l, &r, &x);
    if (c == 1)
      add[l] += x,
          add[r + 1] -= x;
    else {
      st[l] += x;
      st[r + 1] -= x;
      ++cnt[l];
      --cnt[r + 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    add[i] += add[i - 1];
    st[i] += st[i - 1];
    cnt[i] += cnt[i - 1];
    if (cnt[i] == 0)
      ans[i] = a[i] + add[i];
    else
      ans[i] = 1.0 * st[i] / cnt[i],
      ans[i] += 1.0 * add[i] / (cnt[i] + 1);
    ans[i] += ans[i - 1];
  }
  for (int i = 1, l, r; i <= q; ++i) {
    scanf("%d%d", &l, &r);
    printf("%.3lf\n", ans[r] - ans[l - 1]);
  }
}