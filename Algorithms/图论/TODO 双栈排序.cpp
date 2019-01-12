// by kririae
#define ll long long
#define oo (1 << 30)
#include <bits/stdc++.h>

using namespace std;

namespace NOIP2008
{
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
/*
我知道是图论建模...所以还相对轻松
第一问，求出i < j < k使得a[k] < a[i] < a[j]
O(n^3)，可以简单优化一下。和CF有一场的C题一样（高级黑

 */
inline void solve()
{
  
}
}

int main()
{
  return NOIP2008::solve(), 0;
}