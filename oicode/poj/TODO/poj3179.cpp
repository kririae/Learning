/*
by kririae
2018/2/13
*/
#include <bits/stdc++.h>
namespace qwq {
inline char read() {
  static const int IN_LEN = 1000000;
  static char buf[IN_LEN], *s, *t;
  s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
  return s == t ? -1 : *s++;
}

template <typename T> inline void read(T &x) {
  static char c;
  static bool iosig;
  for (c = read(), iosig = false; !isdigit(c); c = read()) {
    if (c == -1)
      return;
    c == '-' ? iosig = true : 0;
  }
  for (x = 0; isdigit(c); c = read())
    x = (x + (x << 2) << 1) + (c ^ '0');
  iosig ? x = -x : 0;
}
inline void init() {}

inline void solve() {}
} // namespace qwq

int main() { return 0; }