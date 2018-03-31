// by kririae
// 背包类树形dp
// STATUS: todo
#include <bits/stdc++.h>

using namespace std;

namespace TYVJ1051
{
const int maxn = 305;
const int maxm = 305;

int n, m, ki, s[maxn], f[maxn][maxm];
vector<int> son[maxn];
vector<int> root;
// i为根，选j门课的最大学分
inline void dp(int x)
{
    f[x][0] = 0;
    for (int i = 0; i < son[x].size(); ++i)
    {
        int curr = son[x][i];
        dp(curr);
        // 组内物品
        for (int t = m; t >= 0; --t) 
        {
            for (int j = t; j >= 0; --j)
                if(t - j >= 0)
                    f[x][t] = max(f[x][t], f[x][t - j] + f[y][j]);
        }
        if(x != 0)
            for (int t = m; t > 0; --t)
                f[x][t] = f[x][t - 1] + s[x];
    }
}

inline void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ki >> s[i];
        if(ki == 0) root.push_back(i);
        son[ki].push_back(i);
    }

    for (int i = 0; i < root.size(); ++i) dp(0);

    cout << f[0][m] << endl;
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    TYVJ1051::solve();
    return 0;
}