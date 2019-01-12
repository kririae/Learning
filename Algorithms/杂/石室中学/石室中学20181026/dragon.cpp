#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
struct C {
  int c, cnt;
  bool operator<(const C &a) const { return cnt < a.cnt; }
} b[30];
int n, k, cnt[30];
char s[N];
int main() {
  freopen("dragon.in", "r", stdin);
  freopen("dragon.out", "w", stdout);
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i)
    ++b[s[i] - 'a' + 1].cnt;
  if (k == 0) {
    for (int i = 1; i <= 26; ++i)
      for (int j = 0; j < b[i].cnt; ++j)
        putchar(i + 'a' - 1);
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    b[s[i] - 'a' + 1].c = s[i] - 'a' + 1;
  sort(b + 1, b + 1 + 26);
  for (int i = 1; i <= 25; ++i) {
    if (b[i].cnt == 0) continue;
    if (b[i].cnt >= k) {
      b[i].cnt -= k;
      b[26].cnt += k;
      break;
    } else {
      k -= b[i].cnt;
      b[26].cnt += b[i].cnt;
      b[i].cnt = 0;
    }
  }
  for (int i = 1; i <= 26; ++i) {
    if (b[i].cnt == 0) continue;
    for (int j = 0; j < b[i].cnt; ++j)
      putchar(b[i].c + 'a' - 1);
  }
}
