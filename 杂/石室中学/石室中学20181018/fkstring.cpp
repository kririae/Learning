#include <bits/stdc++.h>
using namespace std;

const int N = 3e7 + 5;
int x, cnt = 1, tot = 0, ans[305];
inline int log2(int x) {
  int cnt = 0;
  for (; x; x >>= 1, ++cnt)
    if (x & 1) return cnt + 1;
  return cnt;
}
inline void work(int x) {
  int t = log2(x + 1);
  for (int i = 1; i <= t; ++i)
    ans[++tot] = cnt;
}
int main() {
  freopen("fkstring.in", "r", stdin);
  freopen("fkstring.out", "w", stdout);
  // n == 1的时候，输出cnt, cnt(两个)
  scanf("%d", &x);
  if (bitset<30>(x + 1).count() == 1) {
    work(x);
    printf("%d\n", tot);
    for (int i = 1; i <= tot; ++i)
      printf("%d ", ans[i]);
    return 0;
  }
  for (int i = 0; i <= 30; ++i) {
    if (x & (1ll << i)) {
      // 在第i位有一个1
      if (i == 0)
        ans[++tot] = ++cnt,
        ans[++tot] = cnt;
      else {
        ++cnt;
        work((1ll << i) - 1);
        ++cnt;
        ans[++tot] = cnt;
        ans[++tot] = cnt;
      }
    }
  }
  printf("%d\n", tot);
  for (int i = 1; i <= tot; ++i)
    printf("%d ", ans[i]);
}
