#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int n, a[maxn];
ll ans;

int main()
{
  scanf("%d", &n);
  for (R int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (R int i = 1; i <= n; ++i)
    if(a[i] >= i) return puts("-1"), 0;
  for (R int i = 2; i <= n; ++i)
  {
    if(a[i] - a[i - 1] > 1) return puts("-1"), 0;
    if(a[i] == a[i - 1] + 1) ++ans;
    else ans += a[i];
  }
  printf("%d\n", ans);
}