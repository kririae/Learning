#include <bits/stdc++.h>
using namespace std;

struct IO {
  char ibuf[1 << 18], *s, *t, obuf[1 << 18], *o, vbuf[65];
  IO() : s(ibuf), t(ibuf), o(obuf) {}
  ~IO() { fwrite(obuf, 1, o - obuf, stdout); }
  inline char gc() {
    (s == t) && (t = (s = ibuf) + fread(ibuf, 1, 1 << 18, stdin));
    return s == t ? 0 : *s++;
  }
  inline void pc(char c) {
    (o == obuf + (1 << 18)) && (fwrite(obuf, 1, 1 << 18, stdout), o = obuf);
    *o++ = c;
  }
  template <typename T>
  operator T() {
    register T r = 0, f = 1;
    register char c = gc();
    for (; !isdigit(c); c = gc()) f = c == '-' ? -1 : 1;
    for (; isdigit(c); c = gc()) r = (((r << 2) + r) << 1) + (c - '0');
    return f == 1 ? r : -r;
  }
  void operator=(char x) { pc(x); }
  void operator=(const char *x) {
    register int u = 0;
    while (x[u]) pc(x[u++]);
  }
  template <typename T>
  void operator=(T x) {
    register int u = 0;
    if (x == 0) return pc('0'), void();
    if (x < 0) x = -x, pc('-');
    while (x) vbuf[++u] = x % 10 + 48, x /= 10;
    while (u) pc(vbuf[u--]);
  }
} io;
const int N = 1e5 + 5;
struct Rainbow {
  int x, y;
  bool operator<(const Rainbow &r) const {
    return x < r.x;
  }
} a[N];
int n, d;
inline bool judge(int x) {
  static deque<int> q1, q2;
  q1.clear(), q2.clear();
  for (int i = 1; i <= n; ++i) {
    while (q1.size() >= 1 && a[i].x - a[q1.front()].x > x) q1.pop_front();
    while (q1.size() >= 1 && a[q1.back()].y <= a[i].y) q1.pop_back();
    while (q2.size() >= 1 && a[i].x - a[q2.front()].x > x) q2.pop_front();
    while (q2.size() >= 1 && a[q2.back()].y >= a[i].y) q2.pop_back();
    q1.push_back(i), q2.push_back(i);
    if (a[q1.front()].y - a[q2.front()].y >= d) return true;
  }
  return false;
}
int main() {
  n = io, d = io;
  for (int i = 1; i <= n; ++i)
    a[i].x = io, a[i].y = io;
  sort(a + 1, a + 1 + n);
  int l = 0, r = 1e6 + 5;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (judge(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l;
}