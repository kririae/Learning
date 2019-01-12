// test2018 - 10 - 18”÷øºµΩ¡À... 
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int A[2005][2005], num[2005][2005], val[2005][2005];
int R[5000456], D[5000456];
const int bas = 2001;

void spawning() {
  int P, Q, R, S, Mod;
  scanf("%d%d%d%d%d", &P, &Q, &R, &S, &Mod);
  int T = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      T = (T + (1ll * (i + j) * P + 1ll * i * j * Q + 1ll * i * R + 1ll * j * S) % Mod + Mod) % Mod;
      A[i][j] = T;
    }
  A[P % n + 1][P % m + 1] ^= 1;
  A[P % n + 1][Q % m + 1] ^= 1;
  A[P % n + 1][R % m + 1] ^= 1;
  A[P % n + 1][S % m + 1] ^= 1;
  A[Q % n + 1][P % m + 1] ^= 1;
  A[Q % n + 1][Q % m + 1] ^= 1;
  A[Q % n + 1][R % m + 1] ^= 1;
  A[Q % n + 1][S % m + 1] ^= 1;
  A[R % n + 1][P % m + 1] ^= 1;
  A[R % n + 1][Q % m + 1] ^= 1;
  A[R % n + 1][R % m + 1] ^= 1;
  A[R % n + 1][S % m + 1] ^= 1;
  A[S % n + 1][P % m + 1] ^= 1;
  A[S % n + 1][Q % m + 1] ^= 1;
  A[S % n + 1][R % m + 1] ^= 1;
  A[S % n + 1][S % m + 1] ^= 1;
}

void checker() {
  long long Pin = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      Pin += (1ll * i * n + j) * A[i][j];
    }
  }
  printf("%lld\n", Pin);
}

void Out() {
  for (int i = 1; i <= n; i++) {
    int nowx, nowy, now = num[i][0];
    for (int j = 1; j <= m; j++) {
      now = R[now];
      nowy = now % bas;
      nowx = now / bas;
      A[i][j] = val[nowx][nowy];
    }
  }
}

int main() {
  freopen("havefun.in", "r", stdin);
  freopen("havefun.out", "w", stdout);

  scanf("%d%d%d", &n, &m, &k);
  spawning();
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= m + 1; j++)
      num[i][j] = i * bas + j;
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= m + 1; j++) {
      R[num[i][j]] = num[i][j + 1];
      D[num[i][j]] = num[i + 1][j];
      val[i][j] = A[i][j];
    }
  int x1, x2, y1, y2, w, h, now1, now2, now3, now4, t;
  while (k--) {
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &h, &w);
    now1 = num[x1][0];
    now2 = num[x2][0];
    for (int j = 1; j < y1; j++) now1 = R[now1];
    for (int j = 1; j < y2; j++) now2 = R[now2];
    now3 = R[now1];
    now4 = R[now2];
    for (int j = 1; j < w; j++) now3 = R[now3], now4 = R[now4];
    for (int i = 0; i < h; i++) {
      swap(R[now1], R[now2]);
      swap(R[now3], R[now4]);
      now1 = D[now1];
      now2 = D[now2];
      now3 = D[now3];
      now4 = D[now4];
    }
    now1 = num[0][y1];
    now2 = num[0][y2];
    for (int j = 1; j < x1; j++) now1 = D[now1];
    for (int j = 1; j < x2; j++) now2 = D[now2];
    now3 = D[now1];
    now4 = D[now2];
    for (int j = 1; j < h; j++) now3 = D[now3], now4 = D[now4];
    for (int i = 0; i < w; i++) {
      swap(D[now1], D[now2]);
      swap(D[now3], D[now4]);
      now1 = R[now1];
      now2 = R[now2];
      now3 = R[now3];
      now4 = R[now4];
    }
  }
  Out();
  checker();
  return 0;
}
