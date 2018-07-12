#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

ll n, k, a[maxn], b[maxn], cnt;
ll l = 0, r = 1e9, mid;

inline ll calc(ll val)
{
  ll cnt = 0;
  for (R int i = 1; i <= n; ++i)
  {
    int l = 0, r = n, mid;
    while(l < r)
    {
      int mid = (l + r + 1) >> 1;
      if(a[i] * b[mid] > val) r = mid - 1;
      else l = mid;
    }
    if(l == 0) break;
    cnt += l;
  }
  return cnt;
}

int main()
{
  freopen("klarge.in", "r", stdin);
  freopen("klarge.out", "w", stdout);
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> k;
  k = (n * n - k + 1);
  for (R int i = 1; i <= n; ++i) cin >> a[i];
  for (R int i = 1; i <= n; ++i) cin >> b[i];
  sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
  while(l < r)
  {
    int mid = (l + r) >> 1;
    if(calc(mid) >= k) r = mid;
    else l = mid + 1;
  }
  cout << l << endl;
}
