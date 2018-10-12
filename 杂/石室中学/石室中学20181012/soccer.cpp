#include <bits/stdc++.h>
using namespace std;

int num, n, b[505];
char a[505];
int main() {
  freopen("soccer.in", "r", stdin);
  freopen("soccer.out", "w", stdout);
  scanf("%d", &num);
  while (num--) {
    scanf("%d", &n);
    memset(b, 0, sizeof b);
    for (int i = 1; i <= n; ++i) {
      scanf("%s", a + 1);
      for (int j = 1; j <= n; ++j) {
        if (a[j] == 'W')
          b[i] += 3;
        else if (a[j] == 'D')
          b[i] += 1, b[j] += 1;
        else if (a[j] == 'L')
          b[j] += 3;
      }
    }
    for (int i = 1; i <= n; ++i)
      cout << b[i] << " ";
    cout << endl;
  }
}