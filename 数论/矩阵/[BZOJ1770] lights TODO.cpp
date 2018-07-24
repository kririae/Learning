// TODO
#define ull unsigned long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 35 + 5;

namespace BZOJ1770
{
int n, m, a, b, ans = 0;

bitset<40> ma[40];

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (R int i = 1; i <= m; ++i) 
        scanf("%d%d", &a, &b), ma[a][b] = 1, ma[b][a] = 1;
    for (R int i = 1; i <= n; ++i) ma[i][n + 1] = 1, ma[i][i] = 1;
    // Gauss
    for (R int k = 1; k <= n; ++k)
    {
        for (R int i = k + 1; i <= n; ++i)
            if(ma[i][k]) swap(ma[i], ma[k]), i = n + 1;
        for (R int i = k + 1; i <= n; ++i)
            if(ma[i][k]) ma[i] ^= ma[k];
    }
    // trace back
    for (R int k = n; k >= 1; --k)
        for (R int i = n - 1 - (n - k); i >= 1; --i)
            if(ma[i][k]) ma[i] ^= ma[k];
    for (R int i = 1; i <= n; ++i)
        if(ma[i][i] && ma[i][i] == ma[i][n + 1]) ++ans;
    printf("%d\n", ans);
}
}

int main()
{
    return BZOJ1770::solve(), 0;
}