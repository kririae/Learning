#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, a[maxn], b;
ll ans;

int main()
{
  scanf("%d", &n);
  for (R int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i] -= i;
  sort(a + 1, a + 1 + n);
  b = a[n / 2 + 1];
  for (R int i = 1; i <= n; ++i)
    ans += abs(a[i] - b);
  printf("%lld\n", ans);
}