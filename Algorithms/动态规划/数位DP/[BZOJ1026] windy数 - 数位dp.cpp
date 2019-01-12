// by kririae
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int f[25][25], a[50];
inline int dp(int pos, int last, bool limit, bool zero)
{
  // limit表示第一位是否定格
  // zero表示前面是不是0
  if(pos == 0) return 1;
  if(!limit && !zero && f[pos][last]) return f[pos][last];
  int up = limit ? a[pos] : 9; ll ans = 0;
  for (int i = 0; i <= up; ++i)
    if(abs(i - last) >= 2) 
      ans += dp(pos - 1, zero && i == 0 ? -1000 : i, limit && i == a[pos], zero && i == 0);
  if(!limit && !zero) f[pos][last] = ans;
  return ans;
}
inline ll work(ll x)
{
  int curr = 0;
  while(x) a[++curr] = x % 10, x /= 10;
  memset(f, 0, sizeof(f));
  return dp(curr, -(1 << 30), true, true);
}
int main()
{
  ll a, b;
  cin >> a >> b;
  printf("%lld", work(b) - work(a - 1));
}