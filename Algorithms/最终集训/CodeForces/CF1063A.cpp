#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
  scanf("%d", &n);
  int t = n / 3;
  int a, b, c;
  a = t, b = t, c = n - 2 * t;
  while ((a % 3 == 0 || c % 3 == 0) && a >= 1)
    --a, --b, c += 2;
  if (a == 0) {
    while ((a % 3 == 0 || c % 3 == 0) && c >= 3)
      ++a, ++b, c -= 2;
    cout << a << " " << b << " " << c;
    return 0;
  }
  cout << a << " " << b << " " << c;
}