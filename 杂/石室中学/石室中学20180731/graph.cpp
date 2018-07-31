// by kririae
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

namespace Graph
{
const int maxn = 1e5 + 5;
int n, to[maxn], w[maxn];
ll k, f[maxn][35], su[maxn][35], mi[maxn][35];
inline void solve()
{
  freopen("graph.in", "r", stdin);
  freopen("graph.out", "w", stdout);
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> f[i][0];
  for (int i = 0; i < n; ++i) cin >> su[i][0], mi[i][0] = su[i][0];
  for (int t = 1; t <= 34; ++t)
    for (int i = 0; i < n; ++i) {
      f[i][t] = f[f[i][t - 1]][t - 1];
      su[i][t] = su[i][t - 1] + su[f[i][t - 1]][t - 1];
      mi[i][t] = min(mi[i][t - 1], mi[f[i][t - 1]][t - 1]);
    }
  for (int i = 0; i < n; ++i) {
    ll tmp = k, curr = i, sum = 0, miv = (1ll << 60);
    for (int cnt = 0; cnt <= 34; ++cnt)
      if((tmp >> cnt) & 1) {
        sum += su[curr][cnt];
        miv = min(miv, mi[curr][cnt]);
        curr = f[curr][cnt];
      }
    printf("%lld %lld\n", sum, miv);
  }
}
}

int main()
{
  return Graph::solve(), 0;
}