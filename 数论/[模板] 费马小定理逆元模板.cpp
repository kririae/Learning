// po
#pragma GCC optimize("Ofast")
#define ll int
#define R register
#include <bits/stdc++.h>

using namespace std;

inline ll pow1(ll a, ll p)
{
    ll ans = 1;
    a %= (p + 2);
    for (R ll k = p + 2; p; p >>= 1)
    {
        if(p & 1) ans = (1ll * ans * a) % k;
        a = (1ll * a * a) % k;
    }
    return ans;
}

ll n, p;
int main()
{
    scanf("%d%d", &n, &p);
    puts("1");
    for (R ll i = 2; i <= n; ++i)
        printf("%d\n", pow1(i, p - 2));
}