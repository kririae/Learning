// by kririae
#include <bits/stdc++.h>

using namespace std;

namespace BZOJ1090
{
const int maxn = 105;

int f[maxn][maxn];
char s[maxn];

inline bool eql(int l1, int r1, int l2, int r2)
{
  if((r2 - l2 + 1) % (r1 - l1 + 1)) return false;
  for (int i = l2; i <= r2; ++i)
    if(s[i] != s[l1 + (i - l2) % (r1 - l1 + 1)]) return false;
  return true;
}

inline int calc(int val)
{
  int cnt = 0;
  for (; val; val /= 10, ++cnt) ;
  return cnt;
}

inline int dp(int l, int r)
{
  if(l >= r) return 1;
  if(f[l][r]) return f[l][r];
  f[l][r] = r - l + 1;
  for (int k = l; k < r; ++k)
  {
    f[l][r] = min(f[l][r], dp(l, k) + dp(k + 1, r));
    if(eql(l, k, k + 1, r)) f[l][r] = min(f[l][r], dp(l, k) + 2 + calc((r - k) / (k - l + 1) + 1));
  }
  return f[l][r];
}

inline void solve()
{
  scanf("%s", &s);
  printf("%d\n", dp(0, strlen(s) - 1));
}
}

int main()
{
  return BZOJ1090::solve(), 0;
  return 0;
}