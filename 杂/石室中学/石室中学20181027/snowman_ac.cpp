#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline ll read() {
  register ll k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 500005, MOD = 15608;
struct Map {
  vector<ull> a[MOD];
  inline void add(ull x) {
    a[x % MOD].push_back(x);
  }
  inline bool exist(ull x) {
    for (int i = a[x % MOD].size() - 1; i >= 0; --i)
      if (a[x % MOD][i] == x) return true;
    return false;
  }
  inline void clear() {
    for (int i = 0; i < MOD; ++i)
      a[i].clear();
  }
} mp;
int n, a[N], b[N];
ull c[N], c1[N], pw[N], pw1[N], p, p1;
inline ull get(int l, int r) {
  return c[r] - c[l - 1] * pw[r - l + 1];
}
inline bool judge(int x) {
  // 是否存在两段hash相同且长度 == x
  mp.clear();
  for (int i = x + 1; i <= n - x; ++i) {
    mp.add(get(i - x, i - 1));
    if (mp.exist(get(i, i + x - 1)))
      return true;
  }
  return false;
}
int main() {
  srand(time(NULL));
  p = 19260817;
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i < n; ++i) b[i] = a[i] - a[i + 1];
  pw[0] = 1;
  for (int i = 1; i < n; ++i)
    c[i] = c[i - 1] * p + b[i], pw[i] = pw[i - 1] * p;
  int ans = 0;
  int l = 0, r = n + 1;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (judge(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l + 1;
}
