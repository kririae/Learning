#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, a[N], b[N];
vector<int> c;
inline bool check(int x) {
  for (int i = 1; i + x <= n; ++i)
    if (b[i] != b[i + x]) return false;
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i] - a[i - 1];
  }
  for (int i = 1; i <= n; ++i)
    if (check(i)) c.push_back(i);
  cout << c.size() << endl;
  for (int i = 0; i < c.size(); ++i)
    cout << c[i] << " ";
}