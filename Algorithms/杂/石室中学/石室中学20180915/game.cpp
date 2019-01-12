#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1005, MOD = 1e9 + 7;
int n, wi, lst, ti, a[N], b[N], c[N], tmp[4] = { 1, 2, 3 };
set<int> cnt;
inline ll fpow(ll a, ll p) {
  a %= MOD;
  ll ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) (ans *= a) %= MOD;
    (a *= a) %= MOD;
  }
  return ans;
}
inline int judge(int x, int y) {
  // t = 1 -> jiandao
  // t = 2 -> shitou
  // t = 3 -> bu
  if (x == 1) {
    if (y == 1) return ti;
    if (y == 2) return lst;
    if (y == 3) return wi;
  }
  if (x == 2) {
    if (y == 1) return wi;
    if (y == 2) return ti;
    if (y == 3) return lst;
  }
  if (x == 3) {
    if (y == 1) return lst;
    if (y == 2) return wi;
    if (y == 3) return ti;
  }
}
inline int hsh() {
  unsigned int ans = 0;
  for (int i = 1; i <= n + 1; ++i)
    ans = ans * 1ll * 19260817 + c[i];
  return ans;
}
inline int calc() {
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += judge(c[i], b[i]);
  return ans;
}
inline void dfs(int x) {
  if (x == n) {
    int s = -1, flag = 0;
    do {
      memset(b, 0, sizeof b);
      for (int i = 1; i <= n; ++i)
        b[i] = tmp[a[i]];
      if (s == -1) s = calc();
      else if (s != calc()) flag = 1;
    } while (next_permutation(tmp, tmp + 3));
    if (flag == 0) {
      c[n + 1] = s;
      cnt.insert(hsh());
    }
    return;
  }
  c[x + 1] = 1, dfs(x + 1), c[x + 1] = 0;
  c[x + 1] = 2, dfs(x + 1), c[x + 1] = 0;
  c[x + 1] = 3, dfs(x + 1), c[x + 1] = 0;
}
int main() {
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  scanf("%d%d%d%d", &n, &wi, &lst, &ti);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  if (wi == lst && lst == ti) {
    cout << fpow(3, n);
    return 0;
  } else {
    dfs(0);
    cout << cnt.size();
    return 0;
  }
}