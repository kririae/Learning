// by kririae
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace Seg
{
/*
写不来正解，分块骗分好了~
 */
inline char gc()
{
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read()
{
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
inline char read_c()
{
  register char c;
  for (c = gc(); isspace(c); c = gc());
  return c;
}
const int maxn = 100005;
int n, bs, bc, belong[maxn], L[maxn], R[maxn], CNT[maxn];
ll a[maxn], ADD[maxn];
inline void pushdown(int x) 
{
  if(!ADD[x]) return;
  for (int i = L[x]; i <= R[x]; ++i) {
    if(a[i] % 7 == 0) --CNT[x];
    a[i] += ADD[x];
    if(a[i] % 7 == 0) ++CNT[x];
  }
  ADD[x] = 0;
}
inline void modify(int l, int r, int add) 
{
  pushdown(belong[l]), pushdown(belong[r]);
  if(belong[l] == belong[r]) {
    for (int i = l; i <= r; ++i) {
      if(a[i] % 7 == 0) --CNT[belong[i]];
      a[i] += add;
      if(a[i] % 7 == 0) ++CNT[belong[i]];
    } return;
  }
  for (int i = l; i < L[belong[l] + 1]; ++i) {
    if(a[i] % 7 == 0) --CNT[belong[i]];
    a[i] += add;
    if(a[i] % 7 == 0) ++CNT[belong[i]];
  }
  for (int i = belong[l] + 1; i <= belong[r] - 1; ++i)
    ADD[i] += add;
  for (int i = L[belong[r]]; i <= r; ++i) {
    if(a[i] % 7 == 0) --CNT[belong[i]];
    a[i] += add;
    if(a[i] % 7 == 0) ++CNT[belong[i]];
  }
}
inline int query(int l, int r) 
{
  int ans = 0;
  pushdown(belong[l]), pushdown(belong[r]);
  if(belong[l] == belong[r]) {
    for (int i = l; i <= r; ++i) {
      if(a[i] % 7 == 0) ++ans;
    } return ans;
  }
  for (int i = l; i < L[belong[l] + 1]; ++i)
    if(a[i] % 7 == 0) ++ans;
  for (int i = belong[l] + 1; i <= belong[r] - 1; ++i)
    pushdown(i), ans += CNT[i];
  for (int i = L[belong[r]]; i <= r; ++i)
    if(a[i] % 7 == 0) ++ans;
  return ans;
}
inline void solve()
{
	freopen("seg.in", "r", stdin);
	freopen("seg.out", "w", stdout);
  n = read();
  bs = sqrt(n);
  bc = (n % bs == 0 ? n / bs : n / bs + 1);
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= bc; ++i)
    L[i] = R[i - 1] + 1, R[i] = L[i] + bs - 1;
  R[bc] = n;
  for (int i = 1; i <= bc; ++i)
    for (int j = L[i]; j <= R[i]; ++j)
      belong[j] = i, CNT[i] += (a[j] % 7 == 0 ? 1 : 0);
  // 初始化完毕
  int q, a, b, c;
  char op;
  q = read();
  while(q--) {
    op = read_c();
    switch(op) {
      case 'a': a = read(), b = read(), c = read(), modify(a, b, c); break;
      case 'c': a = read(), b = read(), printf("%d\n", query(a, b)); break;
    }
  }
}
}

int main()
{
  return Seg::solve(), 0;
}