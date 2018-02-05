#include <cstdio>
#include <cstring>
#include <numeric>

typedef long long i64;

const int N = 100 + 10, MOD = 20000116;

int k, cur[N], s;

i64 sqr(i64 x) { return x * x; }

void inc() {
  ++cur[0];
  if (++s == k) s = 0;
  for (int i = 0; cur[i] == k; ++i) {
    cur[i] = 0;
    ++cur[i + 1];
    if (++s == k) s = 0;
  }
}

int main() {
	freopen("fantasy.in","r",stdin);
	freopen("fantasy.out","w",stdout);
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    i64 l, r;
    scanf("%d%lld%lld", &k, &l, &r);
    memset(cur, 0, sizeof cur);
    int tot = 0;
    for (i64 t = l; t; t /= k) cur[tot++] = t % k;
    s = std::accumulate(cur, cur + tot, 0) % k;
    unsigned ans = 0;
    int j = l % MOD;
    for (i64 i = l; i <= r; inc()) {
      unsigned h = ((i64)j * j + i + 804) / 233;
      ans += h * s;
      ++i;
      if (++j == MOD) j = 0;
    }
    printf("%u\n", ans);
  }
  return 0;
}
