#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 505, MOD = 2009;
int n, m, cnt; 
ll t; char s[N];
struct Matrix {
int n, a[N][N];
int* operator [] (int x) {
  return a[x];
}
Matrix operator * (Matrix x) {
  Matrix ret;
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= m; ++j) {
      int ans = 0;
      for (int k = 1; k <= m; ++k)
        ans = (ans + 1ll * a[i][k] * x[k][j]) % MOD;
      ret[i][j] = ans;
    }
  return ret;
}
inline Matrix pow(ll p) {
  Matrix ret, b = *this;
  for (int i = 1; i <= m; ++i)
    ret[i][i] = 1;
  for (; p; p >>= 1) {
    if (p & 1) ret = b * ret;
    b = b * b;
  }
  return ret;
}
} a;
inline int calc(int x, int y) {
  return x + y * n;
}
int main() {
  scanf("%d%lld", &n, &t);
  m = n * 9;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 8; ++j)
      a[calc(i, j)][calc(i, j - 1)] = 1;
    scanf("%s", s + 1);
    for (int j = 1; j <= n; ++j) {
      int x = s[j] - '0';
      if (!x) continue;
      a[i][calc(j, x - 1)] = 1;
    }
  }
  a = a.pow(t);
  printf("%d", a[1][n]);
}

/*
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 505, MOD = 2009;
int n, cnt; 
ll t; char s[N];
struct Matrix {
int n, a[N][N];
int* operator [] (int x) {
  return a[x];
}
Matrix operator * (Matrix x) {
  Matrix ret;
  for (int i = 1; i <= cnt; ++i)
    for (int j = 1; j <= cnt; ++j) {
      int ans = 0;
      for (int k = 1; k <= cnt; ++k)
        ans = (ans + 1ll * a[i][k] * x[k][j]) % MOD;
      ret[i][j] = ans;
    }
  return ret;
}
inline Matrix pow(ll p) {
  Matrix ret, b = *this;
  for (int i = 1; i <= cnt; ++i)
    ret[i][i] = 1;
  for (; p; p >>= 1) {
    if (p & 1) ret = b * ret;
    b = b * b;
  }
  return ret;
}
} a;
inline void addedge(int u, int v, int w) {
  int x = u;
  for (int i = 1; i < w; ++i)
    a[x][++cnt] = 1, x = cnt;
  a[x][v] = 1;
}
int main() {
  scanf("%d%lld", &n, &t);
  cnt = n;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; ++j) {
      int x = s[j] - '0';
      if (!x) continue;
      addedge(i, j, x);
    }
  }
  a = a.pow(t);
  printf("%d", a[1][n]);
}
 */