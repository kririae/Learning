// by kririae
// Uva10453
#define pa pair<int, int>
#include <bits/stdc++.h>

using namespace std;

namespace MakePalindrome
{
const int maxn = 1005;

int len, f[maxn][maxn];
pa g[maxn][maxn];
char s[maxn];

inline int dp(int l, int r)
{
  if(l >= r) return 0;
  if(f[l][r]) return f[l][r];
  f[l][r] = 1e9;
  if(s[l] == s[r]) f[l][r] = dp(l + 1, r - 1), g[l][r] = make_pair(l + 1, r - 1);
  int a = dp(l + 1, r), b = dp(l, r - 1);
  if(f[l][r] >= min(a, b) + 1)
  {
    f[l][r] = min(a, b) + 1;
    if(a <= b) g[l][r] = make_pair(l + 1, r);
    else g[l][r] = make_pair(l, r - 1);
  }
  return f[l][r];
}

inline void print(int l, int r)
{
  if(l > r) return;
  if(l == r) return putchar(s[l]), void();
  pa &a = g[l][r];
  if(l == a.first - 1 && r == a.second + 1) return putchar(s[l]), print(a.first, a.second), putchar(s[r]), void();
  if(r == a.second + 1) return putchar(s[r]), print(a.first, a.second), putchar(s[r]), void();
  if(l == a.first - 1) return putchar(s[l]), print(a.first, a.second), putchar(s[l]), void();
}

inline void solve()
{
  while(cin >> s)
  {
    len = strlen(s);
    cout << dp(0, len - 1) << " ";
    print(0, len - 1);
    cout << endl;
    memset(f, 0, sizeof(f));
    memset(s, 0, sizeof(s));
    memset(g, 0, sizeof(g));
  }
}
}

int main()
{
  return MakePalindrome::solve(), 0;
}