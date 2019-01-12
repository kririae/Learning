#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll fpow(ll a, ll p, ll mod) {
  ll ans = 1;
  for (; p; p >>= 1) {
    if(p & 1) (ans *= a) %= mod;
    (a *= a) %= mod;
  } return ans;
}
ll a, b, k;
int main() {
  cin >> a >> b >> k;
  ll ans = (fpow(2, k, a + b) * a) % (a + b);
  cout << min(ans, a + b - ans) << endl;
}