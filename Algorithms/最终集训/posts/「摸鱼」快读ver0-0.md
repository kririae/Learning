title: 「摸鱼」快读ver0.0
author: kririae
date: 2018-07-31 08:46:03
tags:
---
打完比赛就开始摸...摸了一份快读

<!--more-->

写的快读
暂时测试没有问题
速度没有测试，但是应该不慢
骚操作~
就是有点长QAQ
```cpp
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
```

```cpp
int a = io, b = io;
io = a, io = b;
```
很无脑，我会修改一下...