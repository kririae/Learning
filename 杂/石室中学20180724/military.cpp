// by kririae
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

namespace IO
{
inline char gc()
{
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read()
{
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
}

namespace Military
{
int n, m[maxn], c[maxn], cnt, all[maxn * 10];
vector<int> a[maxn];

inline int calc(int val)
{
  int maxv = 0;
  for (R int i = 1; i <= n; ++i)
  {
    int pos = lower_bound(a[i].begin(), a[i].end(), val) - a[i].begin();
    maxv = max(maxv, a[i][pos + c[i] - 1]);
  }
  return maxv;
}

inline void solve()
{
  freopen("military.in", "r", stdin);
  freopen("military.out", "w", stdout);
  using namespace IO;
  n = read();
  for (R int i = 1; i <= n; ++i)
  {
    m[i] = read(), c[i] = read();
    R int v;
    for (R int j = 1; j <= m[i]; ++j)
      v = read(), a[i].push_back(v), all[++cnt] = v;
  }
  for (R int i = 1; i <= n; ++i)
    sort(a[i].begin(), a[i].end());
  sort(all + 1, all + 1 + cnt);
  int siz = unique(all + 1, all + 1 + cnt) - all - 1;
  int l = 0, r = 1e9; // ???
  for (R int i = 1; i <= n; ++i)
    r = min(r, a[i][m[i] - c[i]]);
  int pos = upper_bound(all + 1, all + 1 + siz, r) - all;
  int ans = 1e9;
  for (R int i = 1; i < pos; ++i)
    ans = min(ans, calc(all[i]) - all[i]);
  cout << ans << endl;
}
}

int main()
{
  return Military::solve(), 0;
}