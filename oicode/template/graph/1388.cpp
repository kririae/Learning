#include <bits/stdc++.h>
using namespace std;
map<string, string> gen;
string va, tempo;
inline string find(string val) {
  if (gen[val] != val)
    gen[val] = find(gen[val]);
  return gen[val];
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c;
  cin >> c;
  while (c != '$') {
    cin >> va;
    if (c == '#') {
      tempo = va;
      if (gen[va] == "")
        gen[va] = va;
    } else if (c == '+') {
      gen[va] = tempo;
    } else
      cout << va << " " << find(va) << endl;
    cin >> c;
  }
  return 0;
}
