#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100005;
int n, a[N], s[N], top, l[N], r[N];
ll ans[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    while (top && a[i] >= a[s[top]]) --top;
    l[i] = top == 0 ? 1 : s[top] + 1;
    s[++top] = i;
  }
  top = 0;
  for (int i = n; i >= 1; --i) {
    while (top && a[i] > a[s[top]]) --top;
    r[i] = top == 0 ? n : s[top] - 1;
    s[++top] = i;
  }
  for (int i = 1; i <= n; ++i)
    ans[a[i]] += 1ll * (i - l[i] + 1) * (r[i] - i + 1);
  for (int i = 100000; i >= 0; --i) ans[i] += ans[i + 1];
  int x, q;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &x);
    printf("%lld\n", ans[x]);
  }
}