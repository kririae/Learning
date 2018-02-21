#include <bits/stdc++.h>
namespace qwq {

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