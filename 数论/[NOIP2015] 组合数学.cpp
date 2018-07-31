#include <bits/stdc++.h>

using namespace std;

struct IO
{
char ibuf[1 << 18], *s, *t, obuf[1 << 18], *o, vbuf[65];
IO() : s(ibuf), t(ibuf), o(obuf) {}
~IO() { fwrite(obuf, 1, o - obuf, stdout); }
inline char gc() 
{
  (s == t) && 
  (t = (s = ibuf) + fread(ibuf, 1, 1 << 18, stdin));
  return s == t ? 0 : *s++;
}
inline void pc(char c)
{
  (o == obuf + (1 << 18)) &&
  (fwrite(obuf, 1, 1 << 18, stdout), o = obuf);
  *o++ = c;
}
template<typename T>
operator T()
{
  register T ret = 0, f = 1; 
  register char c = gc();
  for (; !isdigit(c); c = gc())
  f = c == '-' ? -1 : 1;
  for (; isdigit(c); c = gc())
  ret = (((ret << 2) + ret) << 1) + (c - '0');
  return f == 1 ? ret : -ret;
}
void operator = (char x) { pc(x); }
void operator = (const char *x) 
{
  register int curr = 0;
  while(x[curr]) pc(x[curr++]);
}
template<typename T>
void operator = (T x) 
{
  register int curr = 0;
  if(x == 0) return pc('0'), void();
  if(x < 0) x = -x, pc('-');
  while(x) vbuf[++curr] = x % 10 + 48, x /= 10;
  while(curr) pc(vbuf[curr--]);
}
} io;
const int maxn = 2005;
int t, k, c[maxn][maxn], s[maxn][maxn];
int main()
{
  t = io, k = io;
  c[0][0] = c[1][0] = c[1][1] = 1;
  register int i, j;
  for (i = 1; i <= 2000; s[i][i + 1] = s[i][i], c[i][0] = 1, ++i)
    for (j = 1; j <= i; ++j) {
      c[i][j] = (1ll * c[i - 1][j] + c[i - 1][j - 1]) % k;
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
      s[i][j] += (c[i][j] == 0 ? 1 : 0);
    }
  while(t--) i = io, j = io, j = min(j, i), io = s[i][j], io = '\n';
}