#include <bits/stdc++.h>
using namespace std;

const int N = 30005;
char s[N], t[N], c[N];
int qwq, a[N], cnt, cnt1, d[N];
char b[N];
bool vis[N];
int main() {
  scanf("%d", &qwq);
start:
  while (qwq--) {
    memset(s, 0, sizeof s);
    memset(t, 0, sizeof t);
    memset(c, 0, sizeof c);
    memset(a, 0, sizeof a);
    memset(d, 0, sizeof d);
    memset(b, 0, sizeof b);
    memset(vis, 0, sizeof vis);
    cnt = cnt1 = 0;
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1);
    int m = strlen(t + 1);
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '*')
        vis[cnt] = 1;
      else {
        if (s[i] != b[cnt]) {
          b[++cnt] = s[i];
          a[cnt] = 1;
        } else
          ++a[cnt];
      }
    }
    for (int i = 1; i <= m; ++i)
      if (t[i] != c[cnt1]) {
        c[++cnt1] = t[i];
        d[cnt1] = 1;
      } else
        ++d[cnt1];
    if (cnt != cnt1) {
      puts("No");
      continue;
    }
    for (int i = 1; i <= cnt1; ++i) {
      if (b[i] != c[i]) {
        puts("No");
        goto start;
      }
      if (a[i] < d[i] && !vis[i]) {
        puts("No");
        goto start;
      }
      if (a[i] > d[i]) {
        puts("No");
        goto start;
      }
    }
    puts("Yes");
  }
}