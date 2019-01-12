#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int N = 105;
int t, n;
ll a[N], ans;
inline void dfs(int pos, ll v) {
  if (pos == n) {
    ans = min(ans, v);
    return;
  }
  dfs(pos + 1, v & a[pos + 1]);
  dfs(pos + 1, v & ~a[pos + 1]);
  dfs(pos + 1, v | a[pos + 1]);
  dfs(pos + 1, v | ~a[pos + 1]);
  dfs(pos + 1, v ^ a[pos + 1]);
  dfs(pos + 1, v ^ ~a[pos + 1]);
}
int main() {
  cin >> t;
st:
  while (t--) {
    ans = ((ll)1) << 63;
    cin >> n;
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    if (n >= 7) {
      puts("0");
      goto st;
    }
    dfs(1, a[1]);
    dfs(1, ~a[1]);
    cout << ans << endl;
  }
}