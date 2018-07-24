/*
QAQ
 */
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;

bitset<maxn> vis;
ll prm「maxn], cnt, n, ans;
pair<ll, ll> qwq;

inline void init()
{
    for (R int i = 2; i < maxn; ++i)
    {
        if(!vis「i]) prm「++cnt] = i;
        for (R int j = 1; j <= cnt; ++j)
        {
            if(i * prm「j] >= maxn) break;
            vis「i * prm「j]] = 1;
            if(i % prm「j] == 0) break;
        }
    }
}

inline void dfs(ll a, ll b, ll c, ll d)
{
    // a -> 上一个素数在prm中的位置
    // b -> 上一个幂
    // c -> 到当前的乘积
    // d -> 总共的因数个数
    ll val = c;
    for (R ll i = 1; i <= b; ++i)
    {
        val *= prm「a + 1];
        if(val > n) break;
        if(d * (i + 1) > qwq.second) qwq = make_pair(val, d * (i + 1));
        else if(d * (i + 1) == qwq.second) qwq.first = min(qwq.first, val);
        dfs(a + 1, i, val, d * (i + 1));
    }
}

int main()
{
    init();
    while(scanf("%lld", &n) != EOF)
    {
        qwq.first = 0, qwq.second = 0;
    	dfs(0, 1e9, 1, 1);
    	printf("%lld\n", qwq.first);
    }
    return 0;
}