#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 5000009;
const int MOD = 1000000007;

int f[N];

inline int read() {
    char c = getchar(); int ret = 0, f = 1;
    for (; c < '0' || c > '9'; f = c == '-'? -1: 1, c = getchar());
    for (; '0' <= c && c <= '9'; ret = ret * 10 + c - '0', c = getchar());
    return ret * f;
}

int main() {
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    int n = read(), mx = 0, ans = 0;
    for (int i = 1, w; i <= n; i++) {
        f[w = read()]++;
        mx = max(mx, w);
    }
    for (int i = 1; i <= mx; i++) {
        for (int j = i + i; j <= mx; j += i) {
            f[i] += f[j];
        }
    }
    for (int i = mx; i; i--) {
        f[i] = (LL)f[i] * f[i] % MOD;
        for (int j = i + i; j <= mx; j += i) {
            (f[i] -= f[j]) %= MOD;
        }
        ans = ((LL)i * (i - 1) * f[i] + ans) % MOD;
    }
    cout<<(ans + MOD) % MOD<<endl;
    return 0;
}