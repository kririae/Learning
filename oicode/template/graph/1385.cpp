#include <bits/stdc++.h>
using namespace std;
map<string, string> gen;
string fa, son;
inline string find(string val) {
  if (gen[val] != val)
    gen[val] = find(gen[val]);
  return gen[val];
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c;
  for (int i = 0; i <= 50000; ++i)
    father[i] = i;
  c = getchar();
  while (c != '$') {
    cin >> fa;
    if (c == '#') {
      son = fa;
      if (gen[fa] == "")
        gen[fa] = fa;
    } else {
      if (c == '+') {
        gen[fa] = son;
      } else {
        cout << s << ' ' << find(s) << endl;
      }
    }
  }
  return 0;
}
