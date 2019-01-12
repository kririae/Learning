#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 65;
int n, m, cnt; char s[N];
ll a[N];
inline void Insert(ll x) {
  for (int i = 60; i >= 0; --i)
    if ((x >> i) & 1) {
      if (a[i] == 0)
        return a[i] = x, void();
      x ^= a[i];
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%s", s);
    ll x = 0;
    for (int j = 0; j < n; ++j)
      if (s[j] == 'O') x += (1ll << (n - j));
    Insert(x);
  }
  for (int i = 0; i <= 60; ++i) 
    if (a[i] != 0) ++cnt;
  cout << ((1ll << cnt) % 2008);
}