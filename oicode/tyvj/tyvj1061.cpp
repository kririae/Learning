// by kririae
// status: WA
#include <bits/stdc++.h>

using namespace std;

namespace kririae
{
const int maxl = 205;
const int maxn = 1005;

int p[maxn], c[maxl][maxl], f[3][maxl][maxl];
int l, n, q;

inline void swap(int &a, int &b)
{
    int c = a; a = b; b = c;
}

inline void solve()
{
    cin >> l >> n;
    for  (int i = 1; i <= l; ++i)
        for (int j = 1; j <= l; ++j)
            cin >> c[i][j];
    for (int i = 1; i <= n; ++i) cin >> p[i];
    memset(f, 0x3f, sizeof(f));
    f[1][1][2] = 0;
    int a = 2, b = 1;
    for (int i = 1; i <= n; ++i)
    {
        swap(a, b);
        memset(f[b], 0x3f, sizeof(f[b]));
        for (int j = 1; j <= l; ++j)
        {
            for (int k = 1; k <= l; ++k)
            {
                if(p[i] != j && p[i] != k)
                    f[b][j][k] = min(f[b][j][k], f[a][j][k] + c[p[i]][p[i + 1]]);
                if(j != p[i])
                    f[b][p[i]][k] = min(f[b][p[i]][k], f[a][j][k] + c[j][p[i + 1]]);
                if(k != p[i])
                    f[b][j][p[i]] = min(f[b][j][p[i]], f[a][j][k] + c[k][p[i + 1]]);
            }
        }
    }
    int res = 1e9;
    for (int i = 1; i <= l; ++i) 
        for (int j = 1; j <= l; ++j)
            res = min(res, f[1][i][j]);
    for (int i = 1; i <= l; ++i) 
        for (int j = 1; j <= l; ++j)
            res = min(res, f[2][i][j]);
    cout << res << endl;
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    kririae::solve();
    return 0;
}