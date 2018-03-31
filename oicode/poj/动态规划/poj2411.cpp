// by kririae
// POJ2411
// status: AC
#include <iostream>

using namespace std;

namespace POJ2411
{
int n, m;
long long f[12][1 << 11];
bool od[1 << 11];

inline void solve()
{
    for (;;) 
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        // 预处理可以放偶数个的整数
        // 状压dp通常有预处理
        // for (int i = 0; i < (1 << m); ++i)
        // {
        //     int cnt = 0;
        //     for (int j = 0; j < m; ++j)
        //     {
        //         // 如果第i位是0
        //         if(i >> j & 1) 
        //             if(cnt % 2 == 1) goto end1; 
        //             else cnt = 0;
        //         else ++cnt;
        //     }
        //     od[i] = true;
        //     end1: ;
        // }
        
        for (int i = 0; i < 1 << m; ++i)
        {
            // 这部分处理不知道咋个搞...就抄lyd上的了orz
            bool cnt = 0, has_odd = 0;
            for (int j = 0; j < m; ++j)
            {
                if(i >> j & 1) has_odd |= cnt, cnt = 0;
                else cnt ^= 1;
            }
            od[i] = has_odd | cnt ? 0 : 1;
        }

        f[0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < (1 << m); ++j)
            {
                f[i][j] = 0;
                for (int k = 0; k < 1 << m; ++k)
                    if((j & k) == 0 && od[j | k])
                        f[i][j] += f[i - 1][k];
            }
        cout << f[n][0] << endl;
    }
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    POJ2411::solve();
    return 0;
}