// template review
#include <bitset>
#define ll long long
template <typename T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
inline T min(T a, T b) {
  return a < b ? b : a;
}
namespace NumberTheory {
template <typename T>
inline T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
inline T __gcd(T a, T b) {
  while (a ^= b ^= a ^= b %= a)
    ;
  return a;
}
// exgcd -> ax + by = gcd(a, b)
template <typename T>
inline void exgcd(T a, T b, T &x, T &y) {
  if (b == 0)
    (x = 1, y = 0);
  else
    exgcd(b, a % b, y, x), y -= (a / b) * x;
}
template <typename T>
inline ll fpow(T a, T p, T mod) {
  ll ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) ans = (1ll * a * ans) % mod;
    a = (1ll * a * a) % mod;
  }
  return ans;
}
inline void INV(int *inv, int p, int n) {
  inv[1] = 1;
  for (int i = 2; i <= n; ++i)
    inv[i] = (p - p / i) * inv[p % i] % p;
}
template <typename T>
inline ll inv(T a, T p) {
  return fpow(a, p - 2, p);
}
template <typename T>
inline ll phi(T x) {
  ll ans = x;
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) {
      ans = ans / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  if (ans) ans = ans / x * (x - 1);  // 易错
  return ans;
}
inline void PHI(int n, int *phi) {
  const int N = 10005;
  static int prm[N];
  static std::bitset<N> vis;
  int cnt = 0;
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) {
      prm[++cnt] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= cnt; ++j) {
      if (i * prm[j] > n) break;
      vis[i * prm[j]] = 1;
      if (i % prm[j] == 0) {
        phi[i * prm[j]] = phi[i] * prm[j];
        break;
        // 参照phi推导公式
      }
      phi[i * prm[j]] = phi[i] * phi[prm[j]];
      // 积性函数定义
    }
  }
}
struct LinearBasis {
  ll a[64];
  inline void Insert(ll x) {
    for (int i = 60; i >= 0; --i)
      if (x & (1ll << i)) {
        if (a[i] == 0) {
          a[i] = x;
          break;
        }
        x ^= a[i];
      }
  }
  inline ll Max() {
    ll ans = 0;
    for (int i = 60; i >= 0; --i)
      ans = max(ans, ans ^ a[i]);
    return ans;
  }
};
template <typename T>
inline ll C(T n, T m, T p) {
  // 略...
  // \frac{n!}{(n - m)!m!}
  // 组合数基本递推式:
  // \binom{n}{m} = \binom{n - 1}{m} + \binom{n - 1}{m - 1}
  return 0;
}
template <typename T>
inline ll lucas(T n, T m, T p) {
  if (n < m) return 0;
  if (n == 0) return 1;
  return lucas(n / p, m / p) * C(n % p, m % p) % p;
}
struct Matrix {
  enum { SIZE = 105, MOD = 1e9 + 7; }
  int n, m, a[N][N];
  inline Matrix() {}
  inline Matrix(int _n, int _m) : n(_n), m(_m) {}
  inline int *operator[](int x) { return a[x]; }
  inline Matrix(const Matrix &y) {
    Matrix ret(n, y.m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= y.m; ++j) {
        ll u = 0;
        for (int k = 1; k <= n; ++k)
          u = (u + a[i][k] * y[k][j]) % MOD;
        ret[i][j] = (int)u;
      }
    return ret;
  }
  inline Matrix pow(ll p) {
    Matrix ret(n, n), b = *this;
    for (int i = 1; i <= n; ++i) ret[i][i] = 1;
    for (; p; p >>= 1) {
      if (p & 1) ret = b * ret;
      b = b * b;
    }
    return ret;
  }
};
}  // namespace NumberTheory

namespace GraphTheory {
}
int main() {
}