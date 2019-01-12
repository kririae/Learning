#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline ll read() {
  register ll k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 500005;
int n, m, a[N]; ll s[N];
struct Sgt {
int L[N << 2], R[N << 2], son[N << 2][2], rt, cnt;
ll sum[N << 2], add[N << 2], set[N << 2], mx[N << 2];
// sum, set, mx maintain specfic value, while add maintains timestamp.
inline void pushup(int k) {
  sum[k] = sum[ls] + sum[rs];
  mx[k] = max(mx[ls], mx[rs]);
}
inline void pushdown(int k) {
  if (~set[k]) {
    sum[ls] = (R[ls] - L[ls] + 1) * set[k];
    sum[rs] = (R[rs] - L[rs] + 1) * set[k];
    add[ls] = add[rs] = 0;
    mx[ls] = mx[rs] = set[k];
    set[ls] = set[rs] = set[k];
    set[k] = -1;
  }
  if (add[k]) {
    sum[ls] += (s[R[ls]] - s[L[ls] - 1]) * add[k];
    sum[rs] += (s[R[rs]] - s[L[rs] - 1]) * add[k];
    add[ls] += add[k];
    add[rs] += add[k];
    mx[ls] += a[R[ls]] * add[k];
    mx[rs] += a[R[rs]] * add[k];
    add[k] = 0;
  }
}
inline void Build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l;
  R[k] = r;
  if (l == r)
    return;
  int mid = l + r >> 1;
  Build(ls, l, mid);
  Build(rs, mid + 1, r);
}
inline void Add(ll x) {
  add[rt] += x;
  sum[rt] += s[n] * x;
  mx[rt] += a[n] * x;
}
inline int QueryPos(int k, ll x) {
  if (L[k] == R[k])
    return L[k];
  pushdown(k);
  if (mx[ls] >= x)
    return QueryPos(ls, x);
  else 
    return QueryPos(rs, x);
}
inline ll Query(int k, int l, int r) {
  if (L[k] == l && R[k] == r)
    return sum[k];
  pushdown(k);
  int mid = L[k] + R[k] >> 1;
  if (r <= mid)
    return Query(ls, l, r);
  else if (l > mid)
    return Query(rs, l, r);
  else 
    return Query(ls, l, mid) + Query(rs, mid + 1, r);
  pushup(k);
}
inline void Set(int k, int l, int r, ll x) {
  if (L[k] == l && R[k] == r) {
    set[k] = mx[k] = x;
    sum[k] = 1ll * (r - l + 1) * x;
    add[k] = 0;
    return;
  }
  pushdown(k);
  int mid = L[k] + R[k] >> 1;
  if (r <= mid)
    Set(ls, l, r, x);
  else if (l > mid)
    Set(rs, l, r, x);
  else
    Set(ls, l, mid, x), Set(rs, mid + 1, r, x);
  pushup(k);
}
inline ll operator [] (int x) {
  return Query(rt, x, x);
}
} t;
inline ll Work(ll d, ll x) {
  static ll pre = 0;
  ll tp = d - pre, ans = 0;
  t.Add(tp);
  if (x >= t.mx[t.rt]) {
    pre = d;
    return 0;
  }
  int pos = t.QueryPos(t.rt, x);
  ans = t.Query(t.rt, pos, n) - x * (n - pos + 1);
  t.Set(t.rt, pos, n, x);
  pre = d;
  return ans;
}
int main() {
  memset(t.set, -1, sizeof t.set);
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) 
    a[i] = read();
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i)
    s[i] = s[i - 1] + a[i];
  t.Build(t.rt, 1, n);
  for (int i = 1; i <= m; ++i) {
    ll d, x;
    d = read(), x = read();
    printf("%lld\n", Work(d, x));
  }
}