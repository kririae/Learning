#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

namespace zkw
{
const int maxn = 1e6 + 5;

int t[maxn << 1 + 5];
int M;

inline void build(int n)
{
  for (M = 1; M < n + 2; M <<= 1) ;
  for (int i = M + 1; i <= M + n; ++i) t[i] = read();
    for (int i = M - 1; i; --i) 
      t[i] = min(t[i << 1], t[i << 1 | 1]), t[i << 1] -= t[i], t[i << 1 | 1] -= t[i];
}

inline int query(int x, int ans = 0)
{
  for (; x; x >>= 1) ans += t[x];
  return ans;
}

inline ll query(int l, int r, ll ans = 0)
{
  for (l += M + 1, r += M + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
    ans += (~l & 1) ? t[l ^ 1] : 0, ans += (r & 1) ? t[t ^ 1] : 0;
  return ans;
}
}