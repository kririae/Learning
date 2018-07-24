// by kririae
#define ll long long
#include <bits/stdc++.h>

using namespace std;

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

namespace BZOJ4027
{
const int maxn = 2e6 + 5;

int N, M, c[maxn], s[maxn], L[maxn], R[maxn], cnt, ans;

inline bool cmp(int a, int b)
{
  return c[a] < c[b];
}

inline void dfs(int k)
{
  if(k == 0) return;
  for (int i = L[k]; i <= R[k]; ++i)
    dfs(s[i]);
  sort(s + L[k], s + R[k] + 1, cmp);
  for (int i = L[k]; i <= R[k]; ++i)
    if(c[k] + c[s[i]] - 1 > M) break;
    else c[k] += c[s[i]] - 1, ++ans;
}

inline void solve()
{
  using namespace IO;
  N = read(), M = read();
  for (int i = 1; i <= N; ++i) c[i] = read();
  for (int i = 1, j; i <= N; ++i)
  {
    L[i] = cnt + 1;
    for (j = read(), c[i] += j; j >= 1; --j) s[++cnt] = read() + 1;
    R[i] = cnt;
  }
  dfs(1);
  printf("%d\n", ans);
}
}

int main()
{
  return BZOJ4027::solve(), 0;
}