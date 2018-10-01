#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;

const int N = 100005;
int n, a[N], l[N], r[N], s[N], top;
ll b[N];
int main() {
  while (~scanf("%d", &n)) {
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    for (int i = 1; i <= n; ++i) 
      scanf("%d", &a[i]), b[i] = b[i - 1] + a[i];
    top = 0;
    for (int i = 1; i <= n; ++i) {
      while (top && s[top] >= a[i]) 
        ++l[i], --top;
      s[++top] = a[i];
    }
    top = 0;
    for (int i = n; i >= 1; --i) {
      while (top && s[top] >= a[i])
        ++r[i], --top;
      s[++top] = a[i];
    }
    ll ans = 0, L = 0, R = 0;
    for (int i = 1; i <= n; ++i) {
      ll x = (b[i + r[i]] - b[i - l[i] - 1]) * a[i];
      if (x > ans)
        ans = x, L = i - l[i], R = i + r[i];
    }
    printf("%lld\n%d %d\n", ans, L, R);
  }
}