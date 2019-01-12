#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

const int N = 1e6 + 5;
int n, s[N], r[N], c[N], top;
char a[N];
int main() {
  scanf("%s", a + 1);
  n = strlen(a + 1);
  for (int i = 1; i <= n; ++i)
    s[i] = s[i - 1] + (a[i] == '(' ? 1 : -1);
  // scanf("%d", &n);
  // for (int i = 1; i <= n; ++i)
  //   scanf("%d", &s[i]);
  s[0] = -1;
  for (int i = n; i >= 1; --i) {
    while (top && s[c[top]] > s[i]) --top;
    if (s[c[top]] == s[i]) {
      r[i] = r[c[top]];
      continue;
    }
    r[i] = c[top];
    c[++top] = i;
  }
  // for (int i = 1; i <= n; ++i)
  //   cout << r[i] << " ";
  int ans = 0, cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (a[i] == '(') ans = max(ans, r[i] - i + 1);
  for (int i = 1; i <= n; ++i)
    if (a[i] == '(' && ans == r[i] - i + 1) ++cnt;
  cout << ans << " " << cnt;
}