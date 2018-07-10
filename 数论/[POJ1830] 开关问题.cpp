#define ull unsigned long long
#define R register
#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

const int maxn = 35 + 5;

namespace POJ1830
{
int t, n, a, b, ans = 0;

bitset<35> ma[35];

inline void solve()
{
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        for (R int i = 1; i <= n; ++i) ma[i].reset();
        scanf("%d", &n);
        for (R int i = 1; i <= n; ++i) 
            scanf("%d", &a), ma[i][n + 1] = a, ma[i][i] = 1;
        for (R int i = 1; i <= n; ++i) scanf("%d", &a), ma[i][n + 1] = a ^ ma[i][n + 1];
        while(~scanf("%d%d", &a, &b) && a && b)
            ma[b][a] = 1;
        // Gauss
        for (R int k = 1; k <= n; ++k)
        {
            for (R int i = k + 1; i <= n; ++i)
                if(ma[i][k]) swap(ma[i], ma[k]), i = n + 1;
            for (R int i = k + 1; i <= n; ++i)
                if(ma[i][k]) ma[i] ^= ma[k];
        }
        // trace back
        for (R int i = 1; i <= n; ++i)
            if(ma[i].count() == 1 && ma[i][n + 1]) return puts("Oh,it's impossible~!!"), void();
        for (R int i = 1; i <= n; ++i)
            if(!ma[i].count()) ++ans;
        printf("%d\n", 1 << ans);
    }
}
}

int main()
{
    return POJ1830::solve(), 0;
}