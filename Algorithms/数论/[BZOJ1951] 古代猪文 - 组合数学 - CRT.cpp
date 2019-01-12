#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace BZOJ1951
{
const int mod = 999911658;
const int prm[4] = {2, 3, 4679, 35617};

inline ll fpow(ll a, ll p, ll mod)
{
  ll ans = 1;
  for (; p; p >>= 1) {
    if(p & 1) ans = (a * ans) % mod;
    a = (a * a) % mod;
  } return ans;
}
int g, n, factor[40000], cnt, fact[40000], a[4];
inline void init()
{
  for (int i = 1; i * i <= n; ++i)
    if(n % i == 0) {
      factor[++cnt] = i;
      if(i != n / i) factor[++cnt] = n / i;
    }
}
inline int C(int n, int m, int p)
{
  if(m > n) return 0;
  return fact[n] * fpow(fact[m] * fact[n - m], p - 2, p) % p;
}
inline int lucas(int n, int m, int p)
{
  if(m == 0) return 1;
  return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}
inline int work(int p)
{
  memset(fact, 0, sizeof(fact));
  fact[0] = 1;
  for (int i = 1; i <= p; ++i)
    fact[i] = fact[i - 1] * i % p;
  ll ans = 0;
  for (int i = 1; i <= cnt; ++i)
    ans = (ans + lucas(n, factor[i], p)) % p;
  return ans;
}
inline int CRT()
{
  ll ans = 0, M = 999911658;
  for (int i = 0; i < 4; ++i)
    ans = (ans + (a[i] * (M / prm[i]) % mod) * fpow(M / prm[i], prm[i] - 2, prm[i])) % mod;
  return ans;
}
inline void solve()
{
  cin >> n >> g;
  if(g == 999911659) return puts("0"), void();
  init();
  for (int i = 0; i < 4; ++i) a[i] = work(prm[i]);
  printf("%lld\n", fpow(g, CRT(), 999911659));
}
}

int main()
{
  return BZOJ1951::solve(), 0;
}