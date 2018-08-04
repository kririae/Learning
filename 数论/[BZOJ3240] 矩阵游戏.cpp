// by kririae
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define R register
using namespace std;

namespace BZOJ3240
{
const int N = 1000005, MOD = 1e9 + 7;
struct Matrix
{
ll n, m, a[10][10];
ll* operator [] (ll x) { return a[x]; }
Matrix() { memset(a, 0, sizeof(a)); }
Matrix(int _n, int _m) : n(_n), m(_m) { memset(a, 0, sizeof a); }
inline Matrix operator * (Matrix b)
{
  Matrix ret(n, n);
  ret[1][1] = (1ll * a[1][1] * b[1][1] % MOD + 1ll * a[1][2] * b[2][1] % MOD);
  ret[1][2] = (1ll * a[1][1] * b[1][2] % MOD + 1ll * a[1][2] * b[2][2] % MOD);
  ret[2][1] = (1ll * a[2][1] * b[1][1] % MOD + 1ll * a[2][2] * b[2][1] % MOD);
  ret[2][2] = (1ll * a[2][1] * b[1][2] % MOD + 1ll * a[2][2] * b[2][2] % MOD);
  return ret;
}
inline Matrix fpow2(ll p)
{
  Matrix ret(n, n), b = *this;
  for (int i = 0; i < 10; ++i) ret[i][i] = 1;
  for (; p; p >>= 1) {
    if(p & 1) ret = b * ret;
    b = b * b;
  } return ret;
}
inline Matrix fpow10(char p[])
{
  Matrix ret(n, n), b = *this; int l = strlen(p + 1);
  for (int i = 0; i < 10; ++i) ret[i][i] = 1;
  for (int i = l; i >= 1; --i) {
    ret = b.fpow2(p[i] - '0') * ret;
    b = b.fpow2(10);
  } return ret;
}
} A(2, 1), B(2, 2), C(2, 2);
int a, b, c, d, ln, lm; char n[N], m[N];
// inline void red(int pos, char x[])
// {
//  if(pos == 0) return;
//  if(x[pos] == '0') x[pos] = '9', red(pos - 1, x);
//  else --x[pos];
// }
inline void solve()
{
  scanf("%s%s", n + 1, m + 1);
  ln = strlen(n + 1), lm = strlen(m + 1);
  scanf("%d%d%d%d", &a, &b, &c, &d);
  A[1][1] = A[2][1] = 1;
  B[1][1] = a, B[1][2] = b, B[2][2] = 1;
  C[1][1] = c, C[1][2] = d, C[2][2] = 1;
  // red(ln, n), red(lm, m);
  int mod = MOD - 1;
  if(a == 1) mod = MOD;
  ll x = 0, y = 0;
  for (int i = 1; i <= ln; ++i) x = (x * 10 + n[i] - '0') % mod;
  for (int i = 1; i <= lm; ++i) y = (y * 10 + m[i] - '0') % mod;
  B = B.fpow2(y - 1);
  B = (B * C).fpow2(x - 1) * B;
  printf("%lld\n", (B[1][1] + B[1][2]) % MOD);
}
}

int main()
{
  return BZOJ3240::solve(), 0;
}