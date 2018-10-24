#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, cnt[30];
char s[N];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int l = 1, r = 1, sta = 0, ans = n + 1;
  for (; r <= n; ++r) {
    if (++cnt[s[r] - 'A'] == 1) ++sta;
    if (sta < 26) continue;
    while (l < r && sta - (cnt[s[l] - 'A'] - 1 == 0) >= 26)
      sta -= (--cnt[s[l++] - 'A'] == 0);
    ans = min(ans, r - l + 1);
  }
  if (ans == n + 1)
    puts("No Solution");
  else
    cout << ans;
}