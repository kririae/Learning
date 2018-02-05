#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 14, S = 150, MOD = 998244353;

int n, m, a[N], b[N], c[N];

i64 get(const int cur[], int tot) {
  static int temp[N];
  std::copy(cur, cur + tot, temp);
  std::sort(temp, temp + tot);
  i64 res = 0;
  for (int i = 0; i < tot; ++i) (res <<= 4) |= temp[i];
  return res;
}

i64 calc(const int cur[]) {
  static int temp[N];
  static bool flag[N];
  std::fill(flag, flag + n, false);
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    if (flag[i]) continue;
    int cnt = 0;
    for (int j = i; !flag[j]; j = cur[j]) flag[j] = true, ++cnt;
    temp[tot++] = cnt;
  }
  return get(temp, tot);
}

std::vector<i64> state;

int pos(i64 x) { return std::lower_bound(state.begin(), state.end(), x) - state.begin(); }

int trans[S][S];

void dfs(int dep, int val, int sum) {
  static int cur[N];
  if (sum == n) {
    state.push_back(get(cur, dep));
    return;
  }
  for (; sum + val <= n; ++val) {
    cur[dep] = val;
    dfs(dep + 1, val, sum + val);
  }
}

int inv(int x) { return x == 1 ? 1 : (((i64)MOD - MOD / x) * inv(MOD % x) % MOD); }

int ed;

void init() {
  static int p[N];
  for (int i = 0; i < n; ++i) p[b[i]] = i;
  for (int i = 0; i < n; ++i) c[i] = p[a[i]];
  state.clear();
  dfs(0, 1, 0);
  std::sort(state.begin(), state.end());
  state.erase(std::unique(state.begin(), state.end()), state.end());
  static int temp[N];
  for (int i = 0; i < n; ++i) temp[i] = i;
  ed = pos(calc(temp));
  for (int i = 0, t = inv(n * (n - 1) * (n - 2)); i < state.size(); ++i) {
    if (i == ed) {
      trans[i][i] = 1;
      continue;
    }
    static int cur[N];
    for (i64 temp = state[i], tot = 0; temp; temp >>= 4) {
      int val = temp & 0xf;
      for (int j = 0; j < val; ++j) cur[tot + j] = tot + (j + 1) % val;
      tot += val;
    }
    for (int a = 0; a < n; ++a) {
      for (int b = 0; b < n; ++b) {
        if (a == b) continue;
        for (int c = 0; c < n; ++c) {
          if (a == c || b == c) continue;
          static int temp[N];
          std::copy(cur, cur + n, temp);
          int x = temp[a], y = temp[b], z = temp[c];
          temp[a] = y, temp[b] = z, temp[c] = x;
          i64 s = calc(temp);
          (trans[i][pos(s)] += t) %= MOD;
        }
      }
    }
  }
}

void mul(int lhs[][S], const int rhs[][S]) {
  static int res[S][S];
  memset(res, 0, sizeof res);
  for (int i = 0; i < state.size(); ++i)
    for (int k = 0; k < state.size(); ++k)
      for (int j = 0; j < state.size(); ++j)
        res[i][j] = (res[i][j] + (i64)lhs[i][k] * rhs[k][j]) % MOD;
  memcpy(lhs, res, sizeof res);
}

void power(int base[][S], int exp) {
  static int res[S][S];
  memset(res, 0, sizeof res);
  for (int i = 0; i < state.size(); ++i) res[i][i] = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) mul(res, base);
    mul(base, base);
  }
  memcpy(base, res, sizeof res);
}

int main() {
	freopen("goodbye.in","r",stdin);
	freopen("goodbye.out","w",stdout);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), --a[i];
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]), --b[i];
  init();
  int st = pos(calc(c));
  if (st == ed) return puts("1"), 0;
  power(trans, m);
  printf("%d\n", trans[st][ed]);
  return 0;
}
