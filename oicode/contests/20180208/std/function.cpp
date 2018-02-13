#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1000009;
const int MOD = 1000000007;

struct data
{
    int a, b, c;
} seq[N];
int qi[N], qx[N], head[N], nxt[N], id[N], ans;

inline int read()
{
    char c = getchar();
    int ret = 0, f = 1;
    for (; c < '0' || c > '9'; f = c == '-' ? -1 : 1, c = getchar())
        ;
    for (; '0' <= c && c <= '9'; ret = ret * 10 + c - '0', c = getchar())
        ;
    return ret * f;
}

inline void AddQuery(int pos, int num)
{
    static int cnt = 0;
    nxt[++cnt] = head[pos];
    head[pos] = cnt;
    id[cnt] = num;
}

void update(int i, int j)
{
    if (j <= seq[i].c)
    {
        update(seq[i].c, j);
        seq[i].b = ((LL)seq[i].a * seq[seq[i].c].b + seq[i].b) % MOD;
        seq[i].a = (LL)seq[i].a * seq[seq[i].c].a % MOD;
        seq[i].c = seq[seq[i].c].c;
    }
}

int main()
{
    freopen("function.in", "r", stdin);
    freopen("function.out", "w", stdout);
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
    {
        seq[i].a = read();
        seq[i].b = read();
        seq[i].c = read();
    }
    for (int i = 1; i <= m; ++i)
    {
        qi[i] = read();
        AddQuery(read(), i);
        qx[i] = read();
    }
    for (int w = n, ci, cqi; w; --w)
    {
        for (int i = head[w]; ci = id[i]; i = nxt[i])
        {
            update(cqi = qi[ci], w);
            ans ^= ((LL)seq[cqi].a * qx[ci] + seq[cqi].b) % MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}