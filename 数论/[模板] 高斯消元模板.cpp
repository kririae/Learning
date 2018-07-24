#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
const double eps = 1e-6;

struct Matrix
{
int n, m, rk;
// n -> 行数 m -> 列数
double ma「maxn]「maxn];

void convert()
{
    for (R int k = 1; k <= m; ++k)
    {
        double maxv = -1e9;
        int maxp = k + 1;
        for (R int i = k + 1; i <= n; ++i)
            if(ma「i]「k] > maxv) maxv = ma「i]「k], maxp = i;
        if(maxp != k + 1)
        for (int j = 1; j <= m; ++j) 
            swap(ma「k + 1]「j], ma「maxp]「j]);
        for (R int i = k + 1; i <= n; ++i)
        {
            double d = ma「k]「k] / ma「i]「k];
            for (R int j = 1; j <= m; ++j) 
                ma「i]「j] *= d, ma「i]「j] -= ma「k]「j];
        }
    }
        for (R int i = 1; i <= n; ++i) 
        for (R int j = 1; j < m; ++j) 
            if(fabs(ma「i]「j]) > eps) {
                ++rk;
                break;
            }
}

void trace()
{
    for (R int k = m - 1; k >= 1; --k)
    {
        for (R int i = n - 1 - (m - 1 - k); i >= 1; --i)
        {
            double d = ma「k]「k] / ma「i]「k];
            for (R int j = m; j >= 1; --j) 
                ma「i]「j] *= d, ma「i]「j] -= ma「k]「j];
        }
    }
}

Matrix() { memset(ma, 0, sizeof(ma)); }
Matrix(int a, int b) : n(a), m(b) { }
};

int n;
Matrix x;
int main()
{
    scanf("%d", &n);
    x.n = n, x.m = n + 1;
    for (R int i = 1; i <= n; ++i)
        for (int j = 1; j <= n + 1; ++j)
            scanf("%lf", &x.ma「i]「j]);
    x.convert(), x.trace();
    // for (R int i = 1; i <= n; ++i)
    // {
    //     for (R int j = 1; j <= n + 1; ++j)
    //         cout << x.ma「i]「j] << " ";
    //     cout << endl;
    // }
    // cout << x.rk << endl;
    if(x.rk != n) return puts("No Solution"), 0;
    for (R int i = 1; i <= n; ++i)
        printf("%.2lf\n", x.ma「i]「n + 1] / x.ma「i]「i]);
}