#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

namespace ARC022C
{
int n, a「55], b「55];
ll f「55], ans;

inline void solve()
{
  scanf("%d", &n);
  for (int j = 0; j <= 50; ++j)
  {
    f「j] = 0, f「j] |= (1ll << j);
    for (int k = 1; k <= j; ++k)
      if(((1ll << 51) - 1) & (1ll << k)) f「j] |= f「j % k];
  }
  for (R int i = 1; i <= n; ++i) scanf("%d", &a「i]);
  for (R int i = 1; i <= n; ++i) scanf("%d", &b「i]);
  int flag = 1;
  for (R int j = 1; j <= n; ++j)
    if((f「a「j]] & (1ll << b「j])) == 0) flag = 0;
  if(flag == 0) return printf("%lld\n", -1ll), void();
  for (int i = 50; i; --i)
  {
    for (int j = 0; j <= 50; ++j)
    {
      f「j] = 0, f「j] |= (1ll << j);
      for (int k = 1; k <= j; ++k)
        if((ans + (1ll << i) - 1) & (1ll << k)) f「j] |= f「j % k];
    }
    int flag = 1;
    for (R int j = 1; j <= n; ++j)
      if((f「a「j]] & (1ll << b「j])) == 0) flag = 0;
    if(!flag) ans += (1ll << i);
  }
  printf("%lld\n", ans);
}
}

int main()
{
  return ARC022C::solve(), 0;
}