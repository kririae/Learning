#include <bits/stdc++.h>
namespace qwq {

inline char read() {
  static const int IN_LEN = 1000000;
  static char buf[IN_LEN], *s, *t;
  s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
  return s == t ? -1 : *s++;
}

template <typename T> inline void read(T &x) {
  static char c;
  static bool iosig;
  for (c = read(), iosig = false; !isdigit(c); c = read()) {
    if (c == -1)
      return;
    c == '-' ? iosig = true : 0;
  }
  for (x = 0; isdigit(c); c = read())
    x = (x + (x << 2) << 1) + (c ^ '0');
  iosig ? x = -x : 0;
}

const int maxn = 55;
const long long inf = (long long)1e18;
const long long minf = (long long)-1e18;
int n, m;
int a[50], b[50];
int amax = -1e9, maxi = 0;
long long mx = (long long)-1e18;
std::vector<long long> res;
inline void init() {
  read(n);
  read(m);
  for (int i = 1; i <= n; ++i)
    read(a[i]);
  for (int i = 1; i <= m; ++i)
    read(b[i]);
}
template <typename T> inline T max(T a, T b) { return a < b ? b : a; }
inline void solve() {
  using std::cout;
  using std::endl;
  init();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      res.push_back((long long)a[i] * b[j]);
    }
  }
  std::sort(res.begin(), res.end());
  cout << res[res.size() - 2] << endl;
}
} // namespace qwq

int main() {
  qwq::solve();
  return 0;
}