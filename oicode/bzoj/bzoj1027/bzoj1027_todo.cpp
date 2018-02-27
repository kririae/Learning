// JSOI2007
// TODO
#include <bits/stdc++.h>

using namespace std;

namespace solve
{
struct node
{
    double x, y, z;
    node()
    {}
    template<typename T>
    node(T a, T b): x(double(a)), y(double(b)), z(double(1 - a - b))
    {}
    template<typename T>
    node(T a, T b, T c): x(a), y(b), z(c)
    {}

    double operator* (const node& a)
    {
        return x * a.y - a.x * y;
    }
};

node vec(node a, node b)
{
    return node(a.x - b.x, a.y - b.y);
}

template<typename T>
inline bool eql(T a, T b)
{
    return fabs(a - b) < eps;
}

const int maxn = 505;
node a[maxn], b[maxn];
int f[maxn][maxn];
int m, n;

inline void init()
{
    cin >> m >> n;
    for (register int i = 1; i <= m; ++i) cin >> a[i].x >> a[i].y >> a[i].z;
    for (register int i = 1; i <= n; ++i) cin >> b[i].x >> b[i].y >> b[i].z;    
}

inline void solve()
{
    init();
    register int i, j, k;
    for (i = 1; i <= m; ++i) 
    {
        for (j = 1; j <= m; ++j)
        {
            bool flag = false;
        }
    }
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve::solve();
}