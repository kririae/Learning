#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int n, a[maxn], b[maxn], f[maxn], g[maxn];
vector<int> p[maxn], rep;

int main()
{
    scanf("%d", &n);
    for (R int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (R int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    for (R int i = 1; i <= n; ++i) p[a[i]].push_back(i);
    for (R int i = 1; i < maxn; ++i) reverse(p[i].begin(), p[i].end());
    for (R int i = 1; i <= n; ++i) 
        for (R int j = 0; j < p[b[i]].size(); ++j) rep.push_back(p[b[i]][j]);
    memset(g, 0x3f, sizeof(g));
    int ans = 0;
    for (R int i = 0; i < rep.size(); ++i)
    {
        int pos = lower_bound(g + 1, g + 1 + n, rep[i]) - g;
        g[pos] = rep[i], ans = max(ans, pos);
    }
    cout << ans << endl;
}