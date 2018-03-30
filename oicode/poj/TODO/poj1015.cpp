// poj1015
// by kririae
// status: ???
#include <bits/stdc++.h>

using namespace std;

namespace JuryPromise
{
const int maxn = 205;
const int maxm = 25;

int n, m, sub;
int a[maxn], b[maxn], f[maxm][405];

inline void init()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(f, 0, sizeof(f));
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
        
        for (int i = n; i >= 1; --i)
        {
            cout << "qwq" << endl;
            for (int j = 0; j < 402; ++j)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - (a[i] - b[i])] + a[i] + b[i]);
            }   
        }
        
        for (int i = 0; i <= 400; ++i) cout << f[m][i] << endl;
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