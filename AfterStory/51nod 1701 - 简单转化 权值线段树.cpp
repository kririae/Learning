#include <bits/stdc++.h>
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

const int N = 2e5 + 5;
int n, ans = -1, rt, a[N], b[N];
int son[N << 2][2], L[N << 2], R[N << 2], mx[N << 2], cnt;
char s[N];
inline bool checker(char s) {
  if (s == 'a') return 1;
  if (s == 'e') return 1;
  if (s == 'i') return 1;
  if (s == 'o') return 1;
  if (s == 'u') return 1;
  return 0;
}
inline void pushup(int k) {
  mx[k] = max(mx[ls], mx[rs]);
}
inline void build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l, R[k] = r;
  if (l == r)
    return (void) (mx[k] = -1e9);
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
inline void Insert(int k, int p, int v) {
  if (L[k] == R[k])
    return (void) (mx[k] = max(mx[k], v));
  int mid = (L[k] + R[k]) >> 1;
  if (p <= mid)
    Insert(ls, p, v);
  else
    Insert(rs, p, v);
  pushup(k);
}
inline int Query(int k, int l, int r) {
  if (L[k] == l && R[k] == r)
    return mx[k];
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    return Query(ls, l, r);
  else if (l > mid)
    return Query(rs, l, r);
  else
    return max(Query(ls, l, mid), Query(rs, mid + 1, r));
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  build(rt, 1, 2 * n);
  for (int i = 1; i <= n; ++i) {
    a[i] = a[i - 1] + checker(s[i]);
    b[i] = b[i - 1] + (a[i] == a[i - 1]);
  }
  for (int i = n; i >= 1; --i) {
    ans = max(ans, Query(rt, 1, a[i - 1] - 2 * b[i - 1] + n) - i + 1);
    Insert(rt, a[i] - 2 * b[i] + n, i);
  }
  if (ans == -1)
    printf("No Solution");
  else
    printf("%d", ans);
}