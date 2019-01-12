#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N];
char s[N];
int main() {
  cin >> (s + 1);
  int l = strlen(s + 1);
  for (int i = 1; i <= n; ++i)
    if (s[i] == 'a')
      a[i] ^= 1, a[i - 1] ^= 1;
  for (int i = 1; i <= n; ++i)
    cout << a[i] << " ";
}