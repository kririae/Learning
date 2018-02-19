/*
 * by kriaeth
 * time:
 * using template v0.0
 * read function by xehoth
 */

#include <bitset>
#include <cstdio>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
namespace solve {
int lst[50]{1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
int k;
int res[50];
inline void solve() {
  cin >> k;
  if (k > 34)
    cout << -1 << endl;
  else {
    if (k % 2 == 0) {
      for (int i = 0; i < (k / 2); ++i) {
        cout << 8;
      }
    }
    if (k % 2 != 0) {
      for (int i = 0; i < (k / 2); ++i) {
        cout << 8;
      }
      cout << 9;
    }
  }
}
} // namespace solve

int main() {
  solve::solve();
  return 0;
}
