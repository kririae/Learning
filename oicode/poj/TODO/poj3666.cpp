#include <bits/stdc++.h>

using namespace kririae;

namespace kririae
{
const int maxn = 2005;
int n, a[maxn], b[maxn], f[maxn][maxn];

inline void sovle()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i], b[i] = a[i];

    sort(b + 1, b + n + 1);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            // 现在脑子糊的...不能做dp
        }
    }
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    kririae::solve();
    return 0;
}