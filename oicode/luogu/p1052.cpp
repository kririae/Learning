#include <bits/stdc++.h>

using namespace std;

namespace river
{
const int mod = 23333;
int l, s, t, m;
int a[mod + 5], f[mod + 5];
inline void solve()
{
    cin >> l;
    cin >> s >> t >> m;
    
    if(s == t)
    {
        int cnt = 0;
        for (int i = 1; i <= m; ++i)
        {
            int val;
            cin >> val;
            if(val % t == 0) ++cnt;
        }
        cout << cnt << endl;
        exit(0);
    }
    
    for (int i = 1; i <= m; ++i)
    {
        int val; cin >> val;
        a[val % mod] = 1;
    }
    
    memset(f, 0x3f, sizeof(f));
    
    f[0] = a[0];
    for (int i = 0; i <= mod; ++i)
        for (int j = s; j <= t; ++j)
            f[i + j] = min(f[i + j], f[i] + a[i]);
    
    cout << f[mod] << endl;
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    river::solve();
    return 0;
}