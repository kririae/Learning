#include <btis/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a, b, p[N];
map<int, int> mp;
int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &p[i]), mp[p[i]] = 1;
  for (int i = 1; i <= n; ++i) {
    if (mp[a - p[i]] == 0 && mp[b - p[i]] == 0) {
      puts("NO");
      return 0;
    }
    if (mp[a - p[i]] && mp[b - p[i]])
      if (mp[a - b + p[i]] == 0 && mp[b - a + p[i]]) {
        puts("NO");
        return 0;
      }
  }
  puts("YES");
}