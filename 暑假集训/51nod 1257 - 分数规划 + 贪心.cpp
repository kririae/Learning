#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 50005;
struct Q {
  double v; int a, b;
  Q() {}
  Q(double _v, int _a, int _b) : 
  v(_v), a(_a), b(_b) {}
  bool operator < (const Q &x) const {
    return v > x.v;
  }
};
int n, k, w[N], p[N]; ll a, b, x, y;
inline bool judge(double x) {
  static Q tmp[N];
  memset(tmp, 0, sizeof(tmp));
  a = 0, b = 0; double ans = 0;
  for (int i = 1; i <= n; ++i)
    tmp[i] = Q(p[i] - x * w[i], p[i], w[i]);
  sort(tmp + 1, tmp + 1 + n);
  for (int i = 1; i <= k; ++i) {
    a += tmp[i].a;
    b += tmp[i].b;
    ans += tmp[i].v;
  }
  return ans >= 0;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &w[i], &p[i]);
  double l = 0, r = 50005;
  for (int i = 1; i <= 30; ++i) {
    double mid = (l + r) / 2;
    if (judge(mid)) x = a, y = b, l = mid;
    else r = mid;
  }
  int g = __gcd(x, y);
  printf("%lld/%lld", x / g, y / g);
}