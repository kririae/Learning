#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 105, MOD = 1e9 + 7;
struct Matrix {
ll n, m, a[N][N];
Matrix() 
{ memset(a, 0, sizeof a); }
Matrix(int _n, int _m) : n(_n), m(_m) 
{ memset(a, 0, sizeof a); }
ll* operator [] (int x) {
  return a[x];
}
Matrix operator * (Matrix b) {
  Matrix ret(this->n, b.m);
  for (int i = 1; i <= ret.n; ++i)
    for (int j = 1; j <= ret.m; ++j) {
      ll ans = 0;
      for (int k = 1; k <= ret.n; ++k)
        (ans += this->a[i][k] * b[k][j]) %= MOD;
      ret[i][j] = ans;
    }
  return ret;
}
} a, b;
inline ll fpow(ll a, ll p, ll mod) {
  a %= mod;
  ll ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) (ans *= a) %= mod;
    (a *= a) %= mod;
  }
  return ans;
}
inline int inv(int x, int p) {
  return fpow(x, p - 2, p);
}
int n, k, s[N];
ll t[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &s[i]);
  a.n = n, a.m = 1;
  b.n = n, b.m = n;
  for (int i = 1; i <= n; ++i)
    a[i][1] = s[i];
  t[0] = 1;
  for (int i = 1; i <= min(k, n); ++i)
    t[i] = 1ll * t[i - 1] * (k + 1 - i) % MOD * inv(i, MOD) % MOD;
  for (int i = 1; i <= min(k, n); ++i) {
    if (i & 1) b[i][1] = t[i - 1];
    else b[i][1] = -t[i - 1];
  }
  for (int i = 2; i <= n; ++i)
    for (int j = i - 1; j <= min(k, n); ++j)
      b[j][i] = b[j - 1][i - 1];
  a = b * a;
  for (int i = 1; i <= a.n; ++i)
    printf("%d ", (a[i][1] + MOD) % MOD);
}