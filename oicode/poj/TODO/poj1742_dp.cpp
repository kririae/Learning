// tle version
// TAGS: DP
#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>

using namespace std;

namespace POJ1742
{
const int maxn = 100010;
bitset<maxn> f;
int n, m, a[maxn], c[maxn];
int used[maxn];

inline void init()
{
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    f.reset();
}

inline void solve_tle()
{
    for (;;) 
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> c[i];
        f[0] = 1;
        
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= c[i]; ++j)
                for (int k = m; k >= a[i]; --k)
                    f[k] = f[k - a[i]] | f[k];
                    
        int ans = 0;
        for (int i = 1; i <= m; ++i) ans += f[i];
        cout << ans << endl;
        init();
    }
}

inline void solve()
{
    for (;;)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> c[i];
        
        // 背包的骚操作
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j) used[j] = 0;
            for (int j = a[i]; j <= m; ++j)
            {

            }
        }
        for (int i = 1; i <= m; ++i) cout << used[i] << " ";
        cout << used[m] << endl;
    }
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    POJ1742::solve();
    return 0;
}