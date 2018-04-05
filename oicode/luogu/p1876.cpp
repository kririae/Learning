// by kririae
#include <bits/stdc++.h>

using namespace std;

namespace CORNFIELDS
{
const int maxn = 12;
int m, n, a[maxn + 1][maxn], l[maxn + 1], f[maxn + 1][1 << maxn];
vector<int> p;

inline void solve()
{
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j])
                l[i] |= (1 << j);

    for (int i = 0; i < (1 << n); ++i)
    {
        bool flag = true;
        for (int j = 0; j < n - 1; ++j)
            if (i & (1 << j) && i & (1 << j + 1))
                flag = false, j = n;
        if (flag)
            p.push_back(i);
    }

    for (int j = 0; j < (1 << n); ++j)
        f[0][j] = 1;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p.size(); ++j)
            if ((l[i] & p[j]) == p[j])
                for (int k = 0; k < p.size(); ++k)
                    if (((l[i + 1] & p[k]) == p[k]) && ((p[k] & p[j]) == 0))
                        f[i + 1][p[k]] = (f[i + 1][p[k]] + f[i][p[j]]) % 100000000;
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i)
    {
        ans = (ans + f[m][i]) % 100000000;
    }
    cout << ans << endl;
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    CORNFIELDS::solve();
    return 0;
}