#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

int n, val, ans;
bitset<maxn> f;
int main()
{ 
  scanf("%d", &n);
  for (R int i = 1; i <= n; ++i) scanf("%d", &val), f |= (f << val);
  for (R int i = 1; i <= 10000; ++i) if(i % 10 != 0 && f「i]) ans = max(ans, i);
  printf("%d", ans);
}