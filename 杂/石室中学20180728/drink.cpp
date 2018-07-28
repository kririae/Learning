// by kririae
// 常数可能...会...
#define ll long long
#define ls t[k].son[0]
#define rs t[k].son[1]
#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[55][5005], l[55], id[250005];
ll L[55], R[55], MID[55], SUM[55], tmp[5005];

struct Node
{
  int son[2], l, r;
  ll L, R, MID, SUM;
} t[250005 << 2];
int root, cnt;

inline void pushup(int k)
{
  t[k].SUM = t[ls].SUM + t[rs].SUM;
  t[k].MID = max(t[ls].MID, t[rs].MID);
  t[k].MID = max(t[k].MID, t[ls].R + t[rs].L);
  t[k].L = max(t[ls].L, t[ls].SUM + t[rs].L);
  t[k].R = max(t[rs].R, t[rs].SUM + t[ls].R);
}

inline void build(int &k, int l, int r)
{
  k = ++cnt, t[k].l = l, t[k].r = r;
  if(l == r) {
    t[k].L = L[id[l]], t[k].R = R[id[l]];
    t[k].MID = MID[id[l]], t[k].SUM = SUM[id[l]];
    return;
  }
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(k);
}

inline void proc(int x)
{
  // 初始化每个块的信息...
  memset(tmp, 0, sizeof(tmp));
  ll mx = -1e9, summ = 0;
  for (int i = 1; i <= l[x]; ++i)
  {
    summ += a[x][i];
    mx = max(mx, summ);
  }
  L[x] = mx, SUM[x] = summ;
  mx = -1e9, summ = 0;
  for (int i = l[x]; i >= 1; --i)
  {
    summ += a[x][i];
    mx = max(mx, summ);
  }
  R[x] = mx, MID[x] = -1e9;
  for (int i = 1; i <= l[x]; ++i)
  {
    tmp[i] = max(tmp[i - 1] + a[x][i], (ll)a[x][i]);
    MID[x] = max(MID[x], tmp[i]);
  }
}

int main()
{
  freopen("drink.in", "r", stdin);
  freopen("drink.out", "w", stdout);
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
  {
    cin >> l[i];
    for (int j = 1; j <= l[i]; ++j)
      cin >> a[i][j];
  }
  for (int i = 1; i <= m; ++i)
    cin >> id[i];
  for (int i = 1; i <= n; ++i)
    proc(i); // 初始化dp信息。
  // 我只会用线段树处理QAQ
  build(root, 1, m);
  printf("%lld", t[root].MID);
}