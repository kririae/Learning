// 快速幂最开始的时候要%= mod!!!!!!!!!
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const ll MOD = 1000000007;

inline ll fast_pow(ll a, ll p, ll mod)
{
    ll ans = 1; a %= mod;
    for (; p; p >>= 1)
    {
        if(p & 1) ans = (ans * a) % mod;
        a = (a * a) % mod; 
    }
    return ans;
}

ll a, b;
int main()
{
    scanf("%lld%lld", &a, &b);
    printf("%lld", fast_pow(a, fast_pow(a, b - 1, MOD - 1), MOD));
    return 0;
}