#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, x, n, m;
vector<int> c, d;
int main() {
  scanf("%lld%lld", &a, &b);
  for (x = 1; x * (x - 1) / 2 <= a + b; ++x)
    ;
  --x;  // 找到最大的$x$!
  if (a < b) swap(a, b);
  for (; x >= 1; --x) {
    if (a >= x)
      a -= x, c.push_back(x);
    else if (b >= x)
      b -= x, d.push_back(x);
  }
  printf("%d\n", c.size());
  for (int i = 0; i < c.size(); ++i)
    printf("%d ", c[i]);
  puts("");
  printf("%d\n", d.size());
  for (int i = 0; i < d.size(); ++i)
    printf("%d ", d[i]);
}