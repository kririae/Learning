#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, x, y;
int main() {
  scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
  ll t = __gcd(x, y);
  x /= t, y /= t;
  cout << min(a / x, b / y);
}