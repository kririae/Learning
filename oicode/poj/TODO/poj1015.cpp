// poj1015
// by kririae
// status: ???
#include <bits/stdc++.h>

using namespace std;

namespace JuryPromise
{
const int maxn = 205;
const int maxm = 25;

int n, m, sub, x, y;
int a[maxn], b[maxn], f[maxm][405], d[maxm][405];
vector<int> res;

inline void init()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(f, 0, sizeof(f));
    memset(d, 0, sizeof(d));
    n = m = sub = x = y = 0;
}

inline void dfs(int i, int j)
{
    if(i == 0 && j == 0) return;
    res.push_back(d[i][j]);
    x += a[d[i][j]];
    y += b[d[i][j]];
    dfs(i - 1, d[i - 1][j - (a[d[i][j]] - b[d[i][j]])]);
}

inline void solve()
{
    for (;;)
    {
        cin >> n >> m;
        
        if(n == 0) break;
    
        for (int i = 1; i <= n; ++i)
            cin >> a[i] >> b[i];
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int ai = a[i], bi = b[i];
            for (int j = m; j >= 0; --j)
            {
                for (int k = 0; k <= 405; ++k)
                {
                    f[j][k] = max(f[j][k], f[j - 1][k - a[i] + b[i]] + a[i] + b[i]);
                }
            }
        }
        init();
    }
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    JuryPromise::solve();
    return 0;
}