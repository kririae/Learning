// 状压dp例题
#include <bits/stdc++.h>

using namespace std;

namespace MixedUpCows
{
const int maxn = 16;

int n, k, s[maxn], p[maxn];
long long f[1 << maxn][maxn], ans;
inline void solve()
{
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i)
        cin >> s[i], f[1 << i][i] = 1;
    
    register int S, i, j;
    for (S = 0; S < (1 << n); ++S)
        for (i = 0; i < n; ++i)
            if(S & (1 << i)) 
                for (j = 0; j < n; ++j)
                    if(!(S & (1 << j)) && abs(s[j] - s[i]) > k)
                        f[S | (1 << j)][j] += f[S][i];
    
    for (int i = 0; i < n; ++i) {
        ans += f[(1 << n) - 1][i];
    }
    cout << ans << endl;
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    MixedUpCows::solve();
    return 0;
}