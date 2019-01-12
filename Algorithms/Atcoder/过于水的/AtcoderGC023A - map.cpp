#define R register
#define ll long long
#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 2e5 + 5;
 
int n, curr;
int a[maxn];
ll s[maxn], ans;
map<ll, int> cnt;
 
int main()
{
  scanf("%d", &n);
  for (R int i = 1; i <= n; ++i) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i], cnt[s[i]] = 0;
  for (R int i = n; i >= 1; --i)
  {
    if(s[i] == 0) ++ans;
    ans += cnt[s[i]];
    cnt[s[i]] += 1;
  }
  printf("%lld", ans);
}