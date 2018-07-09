#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000010;

bitset<maxn> vis;
int prm[maxn], cnt;


int n, m;

inline void init()
{
    for (R int i = 2; i <= n + 5; ++i)
    {
        if(!vis[i]) prm[++cnt] = i;
        for (R int j = 1; j <= cnt; ++j)
        {
            if(i * prm[j] > n) break;
            vis[i * prm[j]] = 1;
            if((i % prm[j]) == 0) break;
        }
    }
}

int val;

int main()
{
    scanf("%d%d", &n, &m);
    init();
    vis[1] = 1, vis[0] = 1;
    for (R int i = 1; i <= m; ++i)
    {
        scanf("%d", &val);
        if(!vis[val]) puts("Yes");
        else puts("No");
    }
    return 0;
}