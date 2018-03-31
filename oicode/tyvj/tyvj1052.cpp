#include <bits/stdc++.h>

using namespace std;

namespace CODEVS1380
{
const int maxn = 6005;

int n, h[maxn], l, k, f[maxn][2];
vector<int> son[maxn];
bitset<maxn> hf;

inline void dp(int x)
{
    f[x][1] = h[x]; // 如果自己要参加的话，那么首先自己会很高兴
    for (int i = 0; i < son[x].size(); ++i)
    {
        int s = son[x][i]; // 对于每一个自己的下属
        dp(s); // 求出自己下属的最大的满意值
        f[x][0] += max(f[s][0], f[s][1]); // 如果自己不参加，下属都可以选择性参加
        f[x][1] += f[s][0]; // 如果自己参加，那么下属不能参加
        // 是通过维护多个转移信息来保证题中条件
        // 和lr讲的一样，维护的信息需要可以转移。
    } 
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> h[i];
    for (int i = 1; i < n; ++i)
    {
        cin >> l >> k;
        son[k].push_back(l);
        hf[l] = 1;
    }

    int root;
    for (int i = 1; i <= n; ++i) 
        if(!hf[i])
        {
            root = i;
            break;
        }

    dp(root);
    cout << max(f[root][0], f[root][1]) << endl;
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    CODEVS1380::solve();
    return 0;
}