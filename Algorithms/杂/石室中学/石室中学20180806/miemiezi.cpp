// by kririae
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 300005;
int n, m, a[N], b[N], tmp[N], tmp2[N]; ll cnt = 0, ans; bitset<N> vis;
inline void merge(int l, int r)
{
  if(l == r) return;
  int mid = l + r >> 1;
  merge(l, mid), merge(mid + 1, r);
  int i = l, j = mid + 1;
  for (int k = l; k <= r; ++k) {
    if(j > r || (i <= mid && b[i] <= b[j])) tmp2[k] = b[i++];
    else tmp2[k] = b[j++], ans += mid - i + 1;
  } for (int k = l; k <= r; ++k) b[k] = tmp2[k], tmp2[k] = 0;
}
inline void work(int pos)
{
  for (int i = 1; i <= n; ++i) b[i] = a[i];
  memset(tmp2, 0, sizeof(tmp2)); ans = 0; merge(1, n);
  cout << ans << endl;
  vis.reset(); cnt = 0;
  for (int i = 1; i <= n; ++i)
    if(i == pos || a[i] < a[pos]) vis[i] = 1, tmp[++cnt] = a[i];
  sort(tmp + 1, tmp + 1 + cnt); 
  cnt = 0;
  for (int i = 1; i <= n; ++i)
    if(vis[i]) a[i] = tmp[++cnt]; 
}
int main()
{
  freopen("miemiezi.in", "r", stdin);
  freopen("miemiezi.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1, val; i <= m; ++i)
    scanf("%d", &val), work(val);
  for (int i = 1; i <= n; ++i) b[i] = a[i];for (int i = 1; i <= n; ++i) b[i] = a[i];
  memset(tmp2, 0, sizeof(tmp2)); ans = 0; merge(1, n);
  cout << ans << endl;
}