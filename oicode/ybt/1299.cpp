#include <bits/stdc++.h>

using namespace std;

namespace tg
{
int n, k, a[105];
int f[105][105];
inline void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            f[i + 1][(f[i][j] + a[i + 1]) % k] = max(f[i + 1][(f[i][j] + a[i + 1]) % k], f[i][j] + a[i + 1]);
    
    cout << f[n][0] << endl;
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    tg::solve();
    return 0;
}