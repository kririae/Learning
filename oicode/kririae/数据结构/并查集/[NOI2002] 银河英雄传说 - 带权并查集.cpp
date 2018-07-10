// by kririae
#define R register
#include <bits/stdc++.h>

using namespace std;

namespace NOI2002
{
const int maxn = 3e4 + 5;

int t, x, y, father[maxn], d[maxn], size[maxn];
char op;

inline int find(int x)
{
  if(x == father[x]) return x;
  int fa = find(father[x]);
  d[x] += d[father[x]];
  return father[x] = fa;
}

inline void solve()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> t;
  for (R int i = 1; i < maxn; ++i) father[i] = i, size[i] = 1;
  for (R int i = 1; i <= t; ++i)
  {
    cin >> op >> x >> y;
    if(op == 'M')
    {
      int a = find(x), b = find(y);
      father[a] = b, d[a] = size[b], size[b] += size[a];
    } else {
      int a = find(x), b = find(y);
      if(a != b) printf("%d\n", -1);
      else printf("%d\n", abs(d[x] - d[y]) - 1);
    }
  }
}
}
int main()
{
  return NOI2002::solve(), 0;
}