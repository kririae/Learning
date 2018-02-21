#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int n;
int a[maxn], b[maxn][maxn], c[maxn];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    for (int j = i - 1; j >= 1; --j)
      if (a[j] <= a[i])
        c[i] = max(c[i], c[j]);
  for (int i = 1; i <= n; ++i)
    b[i][i] = c[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      if (a[i - 1] < a[j]) {
        if (a[i] < a[j + 1]) {
          b[i][j] = max(b[i][j], b[])
        }
      }
    }
  }
}