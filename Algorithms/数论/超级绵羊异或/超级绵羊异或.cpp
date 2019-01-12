#include<bits/stdc++.h>
#define LL long long
using namespace std;

inline int read()
{
    char c = getchar();
    int ret = 0, f = 1;
    while (c < '0' || c > '9')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while (c <= '9' && c >= '0')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret * f;
}

LL cal(LL a, LL b, LL c, LL n)
{
    if (a >= c) return (((n - 1) * n / 2) * (a / c) & 1) ^ cal(a % c, b, c, n);
    if (b >= c) return (n * (b / c) & 1) ^ cal(a, b % c, c, n);
    if (!a) return (b / c) * n & 1;
    LL nw = (a * (n - 1) + b) / c;
    return ((n - 1) * nw & 1) ^ cal(c, c - b - 1, a, nw);
}

int main()
{
    for (int T = read(), a, b, n; T; T--)
    {
        n = read();
        b = read();
        a = read();
        LL c = 1, ans = 0;
        if (!b)
        {
            printf("%d\n", (n & 1) ? a : 0);
            continue;
        }
        for (int i = 0; i <= 60; i++, c <<= 1)
            ans += cal(a, b, c, n) * c;
        printf("%lld\n", ans);
    }
    return 0;
}