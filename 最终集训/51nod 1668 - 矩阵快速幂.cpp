#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 10005, MOD = 1e9 + 7;
struct Martrix {
  ll a, b, ma[5][5];
  Martrix() { memset(ma, 0, sizeof(ma)); }
  Martrix(int x, int y) : a(x), b(y) {}
  ll* operator[](int x) { return ma[x]; }
  Martrix operator*(const Martrix& val) {
    Martrix ret;
    ret.a = a, ret.b = val.b;
    for (int i = 1; i <= ret.a; ++i)
      for (int j = 1; j <= ret.b; ++j) {
        ll ans = 0;
        for (int k = 1; k <= a; ++k)
          ans = (ans + ma[i][k] * val.ma[k][j] % MOD) % MOD;
        ret.ma[i][j] = ans;
      }
    return ret;
  }
  Martrix pow(ll p) {
    Martrix b = *this, ans;
    ans.a = 4, ans.b = 4;
    for (int i = 1; i <= 4; ++i)
      ans[i][i] = 1;
    for (; p; p >>= 1) {
      if (p & 1) ans = b * ans;
      b = b * b;
    }
    return ans;
  }
} a, b;
ll n, f[N][2][2];
int main() {
  scanf("%lld", &n);
  a.a = 4, a.b = 1;
  for (int i = 1; i <= 4; ++i) a[i][1] = 1;
  b.a = b.b = 4;
  b[1][1] = 1, b[1][2] = 1;
  b[2][4] = 1;
  b[3][1] = 1, b[3][2] = 1;
  b[4][3] = 1, b[4][4] = 1;
  b = b.pow(n - 2);
  a = b * a;
  cout << (1ll * a[1][1] + a[2][1] + a[3][1] + a[4][1]) % MOD << endl;
  // f[2][0][0] = f[2][0][1] = f[2][1][0] = f[2][1][1] = 1;
  // for (int i = 3; i <= n; ++i) {
  //   f[i][0][0] = f[i - 1][0][0] + f[i - 1][1][0];
  //   f[i][0][1] = f[i - 1][0][0] + f[i - 1][1][0];
  //   f[i][1][0] = f[i - 1][1][1];
  //   f[i][1][1] = f[i - 1][1][1] + f[i - 1][0][1];
  // }
  // cout << f[n][0][0] + f[n][1][0] + f[n][1][1] + f[n][0][1];
}