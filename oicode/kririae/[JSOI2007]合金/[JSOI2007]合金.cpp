// by kririae
// 2018/3/9
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
namespace solve
{
const double eps = 1e-8;
struct Point
{
    double a, b, c;
    Point()
    {}
    Point(double x, double y):
        a(x), b(y) {}
    Point(double x, double y, double z):
        a(x), b(y), c(z) {}
    Point operator- (const Point& x)
    {
        return Point(a - x.a, b - x.b, c - x.c);
    }
    bool operator== (const Point& x)
    {
        return fabs(a - x.a) < eps && fabs(b - x.b) < eps;
    }
    double operator^ (const Point& x)
    {
        return a * x.b - x.a * b;
    }
    double operator* (const Point& x)
    {
        return a * x.a + b * x.b;
    }
};

const int maxn = 505;
int m, n;
Point t[maxn], u[maxn];
int f[maxn][maxn];

inline void init()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        cin >> t[i].a >> t[i].b >> t[i].c;
    for (int i = 1; i <= n; ++i)
        cin >> u[i].a >> u[i].b >> u[i].c;
}

inline bool spj()
{
    Point sample = u[1];
    for (int i = 1; i <= n; ++i) 
        if(!(u[i] == u[1])) return false;
    return true;
}

inline void solve()
{
    init();
    register int k, i, j;
    for (i = 1; i <= m; ++i)
    for (j = 1; j <= m; ++j) 
        f[i][j] = 1e9;

    if(spj()) for (i = 1; i <= m; ++i) if(t[i] == u[1]) {
        cout << 1 << endl;
        exit(0);
    } // Ç¿ÐÐac.jpg

    for (i = 1; i <= m; ++i)
        for (j = 1; j <= m; ++j)
        {
            if(t[i] == t[j]) continue;
            for (k = 1; k <= n; ++k) {
                double cr = (t[i] - t[j]) ^ (t[i] - u[k]);
                if(cr < -eps) goto end1;
                if(fabs(cr) < eps && (t[i] - u[k]) * (t[j] - u[k]) > eps)  
                goto end1;
            }
            f[i][j] = 1;
            end1:;
        }
    for (k = 1; k <= m; ++k)
        for (i = 1; i <= m; ++i)
            for (j = 1; j <= m; ++j) 
            {
            	if (f[i][k] == 1e9) continue;  
                if (f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k] + f[k][j];
            }
    int minn = 1e9;
    for (i = 1; i <= m; ++i) minn = min(f[i][i], minn);
    // for (int i = 1; i <= m; ++i) cout << f[i][i] << " ";
    if(minn == 1e9) cout << -1 << endl;
    else cout << minn << endl;
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve::solve();
    return 0;
}