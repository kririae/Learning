title: 「TEST」T2
author: kririae
tags:
  - 树形dp
categories:
  - oi
date: 2018-10-10 12:24:00
---
# 「TEST」T2

树形dp即可。

<!--more-->

树有$n$点，有$m$边询问，问经过$i$边的最长链是？$m < n \le 10^5$。

aha我骗到了80分，开心。
考试的时候忽然想起昨天没做完的一道题，CF109C
于是我用类似的方法尝试了今天这道题，居然暴力骗到了$80$?
剩下一个10分是写炸了，还有一个10分是数据太坑了。
总之，是跑过了！
哈，我们来看正解之一。
$f[x]$表示$x$的子树中距离$x$最远点的距离。
$g[x]$表示$x$的子树中距离$x$次远点的距离。
更新的时候需要注意，如果新的距离$\ge f[x]$，那么$g[x] = f[x], f[x] = a$。如果新的距离$> g[x]$，小于$f[x]$，那么只更新$g[x] = a$。
啊，还要维护$l[x]$，表示在$n$点点集$V$中，抛开子树后的点集$V'$中，距离$x$最远的一个点。
对于边$fa[i] \rightarrow i$，如果$f[fa[i]] == f[i] + 1$，代表最长链是同一条，则需要用次长链来转移。否则，可以用最长链来转移。

奉上两份代码。

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int id, t, n, m, fa[N], f[N], g[N], dep[N], dis[N], del[N], vis[N];
int head[N], ver[N << 1], nxt[N << 1], tot;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
int main() {
  scanf("%d%d", &id, &t);
  while (t--) {
    memset(head, -1, sizeof head);
    memset(ver, 0, sizeof ver);
    memset(nxt, 0, sizeof nxt);
    tot = 0;
    memset(fa, 0, sizeof fa);
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i) {
      scanf("%d", &fa[i]);
      addedge(fa[i], i);
      addedge(i, fa[i]);
    }
    for (int i = 1; i <= n; ++i) dep[i] = dep[fa[i]] + 1;
    for (int i = n; i >= 1; --i) f[fa[i]] = max(f[fa[i]], f[i] + 1);
    for (int i = 2; i <= n; ++i)
      for (int j = head[i]; ~j; j = nxt[j]) {
        int to1 = ver[j];
        if (dep[to1] < dep[i]) continue;
        for (int k = head[i]; ~k; k = nxt[k]) {
          int to2 = ver[k];
          if (to1 == to2) continue;
          g[to1] = max(g[to1], f[to2] + 1);
        }
        g[to1] = max(g[to1], g[i]);
      }
    for (int i = 1, x; i <= m; ++i) {
      scanf("%d", &x);
      cout << f[x] + g[x] << endl;
    }
  }
}
```

```cpp
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
int id, t, n, m, fa[N], f[N], g[N], l[N];
int main() {
  id = io, t = io;
  while (t--) {
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    memset(l, 0, sizeof l);
    n = io, m = io;
    for (int i = 2; i <= n; ++i) fa[i] = io;
    for (int i = n; i >= 1; --i) {
      if (f[i] + 1 >= f[fa[i]])
        g[fa[i]] = f[fa[i]], f[fa[i]] = f[i] + 1;
      else if (f[i] + 1 > g[fa[i]])
        g[fa[i]] = f[i] + 1;
    }
    for (int i = 2; i <= n; ++i)
      l[i] = max(l[fa[i]] + 1, f[i] + 1 == f[fa[i]] ? g[fa[i]] + 1 : f[fa[i]] + 1);
    for (int i = 1, x; i <= m; ++i) {
      x = io, io = l[x] + f[x];
      if (i != m) io = ' ';
    }
    if (m) io = '\n';
  }
}
```