#define ll long long
#define oo (1 << 30)
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

const int maxn = 3005;
int n, head[maxn], ver[8005], nxt[8005], tot, w[maxn];
int dfn[maxn], low[maxn], cnt, bcnt, minv[maxn], belong[maxn];
stack<int> s;
bitset<maxn> vis;
inline void addedge(int u, int v)
{
	ver[++tot] = v, nxt[tot] = head[u], head[u] = tot;
}
inline void tarjan(int x)
{
	dfn[x] = low[x] = ++cnt;
	s.push(x), vis[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		int to = ver[i];
		if(!dfn[to]) {
			tarjan(to);
			low[x] = min(low[x], low[to]);
		} else if(vis[to]) low[x] = min(low[x], dfn[to]);
	} 
	if(dfn[x] == low[x]) {
		int curr; minv[++bcnt] = oo;
		do {
			curr = s.top(), s.pop(), vis[curr] = 0;
			belong[curr] = bcnt;
			if(w[curr] != 0) minv[bcnt] = min(minv[bcnt], w[curr]);
		} while(curr != x);
	}
}
int main()
{
	n = io;
	// for (int i = 0; i < maxn; ++i) w[i] = oo;
	int p = io, id, val, r;
	for (int i = 1; i <= p; ++i)
		id = io, val = io, w[id] = val;
	r = io;
	for (int i = 1; i <= r; ++i)
		id = io, val = io, addedge(id, val);
	for (int i = 1; i <= n; ++i)
		if(!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; ++i)
		if(minv[belong[i]] == 0) return io = "NO\n", io = i, 0;
	int ans = 0;
	for (int i = 1; i <= bcnt; ++i)
		(minv[i] != oo) && (ans += minv[i]);
	io = "YES\n", io = ans;
}