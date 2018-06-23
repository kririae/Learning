// by kririae
#define MOD 1000000007
#define R register
#include <bits/stdc++.h>

using namespace std;

int k, val, a[20], f[16][16][16][16][16][6];

inline long long dp(int a, int b, int c, int d, int e, int k)
{
  long long val = 0;
  if(f[a][b][c][d][e][k]) return f[a][b][c][d][e][k];
  if(a + b + c + d + e == 0) return 1;
  if(a) val = (val + (a - (k == 2)) * dp(a - 1, b, c, d, e, 1)) % MOD;
  if(b) val = (val + (b - (k == 3)) * dp(a + 1, b - 1, c, d, e, 2)) % MOD;
  if(c) val = (val + (c - (k == 4)) * dp(a, b + 1, c - 1, d, e, 3)) % MOD;
  if(d) val = (val + (d - (k == 5)) * dp(a, b, c + 1, d - 1, e, 4)) % MOD;
  if(e) val = (val +  e             * dp(a, b, c, d + 1, e - 1, 5)) % MOD;
  return f[a][b][c][d][e][k] = val % MOD;
}

int main()
{
  scanf("%d", &k);
  for (R int i = 1; i <= k; ++i) scanf("%d", &val), ++a[val];
  return printf("%lld", dp(a[1], a[2], a[3], a[4], a[5], 0)), 0;
}