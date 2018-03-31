/*
转化为两个                                                                                                                                                                                                                                                                                                                  问题:
求一个最大子段和，长度不限
求一个最大子段和，长度不小于L
 */
#include <bits/stdc++.h>
namespace solve
{

template<typename T>
inline void read(T &val)
{
    val = 0; int f = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)) {
        val = val * 10 + ch - '0';
        ch = getchar();
    }
    val *= f;
}

const int maxn = 1e5 + 5;
double a[maxn], b[maxn], c[maxn];
int n, l;
inline void init()
{
    read(n); read(l);
    for (register int i = 1; i <= n; ++i) 
        read(a[i]); // init the 
    double l = 1e-6, r = 1e6;
    double acc = 1e-5;
    while(r - l > acc) {
        double mid = (l + r) / 2;
        for (int i = 1; i <= n; ++i) a[i] -= mid;
        for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
        double ans = 1e-9, minn = 1e9;
        for (int i = l; i <= n; ++i) {
            minn = min(minn, a[i - L]);
            ans = max(minn, a[i] - minn);
        }
        ans >= 0 ? l = mid : r = mid;
    }
    cout << (int)r * 1000 << endl;
}

inline void solve() 
{

}
}

int main() 
{
    solve::solve();
    return 0;
}