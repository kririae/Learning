#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#define R register
#define IN inline
#define gc getchar()
#define W while
#define MX 500005
#define ls tree[now << 1]
#define rs tree[now << 1 | 1]

using namespace std;
template <typename T>
IN void in (T &x)
{
    x = 0;
    R char c = gc;
    W (!isdigit(c))c = gc;
    W (isdigit(c))
    {
        x = (x << 1) + (x << 3), x += c - 48, c = gc;
    }
}

struct Edge
{
    int nex, to;
} edge[MX];
struct Node
{
    int lef, rig, del, val, siz;
} tree[MX];
int dep[MX], top[MX], son[MX], head[MX], fat[MX], tot[MX], idx[MX];
int pre[MX], deal[MX];
int cnt/*to arrange the edge*/, id/*to arrange the tree node*/, MOD, dot, q, root;
IN void addedge(const int &from, const int &to)
{
    edge[++cnt] = (Edge)
    {
        head[from], to
    };
    head[from] = cnt;
}
int dfs1(int now, int fa, int deep)
{
    dep[now] = deep;
    fat[now] = fa;
    tot[now] = 1;
    int ms = -1;
    for (int i  = head[now]; i; i = edge[i].nex)
    {
        if(edge[i].to == fa) continue;
        tot[now] += dfs1(edge[i].to, now, deep + 1);
        if (tot[edge[i].to] > ms) ms = tot[edge[i].to], son[now] = edge[i].to;
    }
    return tot[now];
}
void dfs2(int now, int topf)
{
    idx[now] = ++id;
    deal[idx[now]] = pre[now];
    top[now] = topf;
    if(!son[now]) return;
    dfs2(son[now], topf);
    for (R int i = head[now]; i; i = edge[i].nex)
    {
        if(!idx[edge[i].to])
            dfs2(edge[i].to, edge[i].to);
    }
}
IN void pushup(const int &now)
{
    tree[now].val = (ls.val + rs.val + MOD) % MOD;
}
void build(int now, int l, int r)
{
    tree[now].lef = l, tree[now].rig = r, tree[now].siz = r - l + 1;
    if(l == r)
    {
        tree[now].val = deal[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(now << 1, l, mid);
    build(now << 1 | 1, mid + 1, r);
    pushup(now);
}
IN void pushdown(const int &now)
{
    if (!tree[now].del) return;
    ls.val += tree[now].del * ls.siz;
    ls.val %= MOD;
    rs.val += tree[now].del * rs.siz;
    rs.val %= MOD;
    ls.del += tree[now].del;
    ls.del %= MOD;
    rs.del += tree[now].del;
    rs.del %= MOD;
    tree[now].del = 0;
}
void add(const int &now, const int &lb, const int &rb, const int &delta)
{
    if(tree[now].lef >= lb && tree[now].rig <= rb)
    {
        tree[now].del += delta;
        tree[now].val += tree[now].siz * delta;
        return;
    }
    pushdown(now);
    int mid = (tree[now].lef + tree[now].rig) >> 1;
    if(lb <= mid) add(now << 1, lb, rb, delta);
    if(rb > mid) add(now << 1 | 1, lb, rb, delta);
    pushup(now);
}
int query(const int &now, const int &lb, const int &rb)
{
    int ans = 0;
    if(tree[now].lef >= lb && tree[now].rig <= rb) return tree[now].val;
    pushdown(now);
    int mid = (tree[now].lef + tree[now].rig) >> 1;
    if(lb <= mid) ans += query(now << 1, lb, rb) % MOD;
    ans %= MOD;
    if(rb > mid) ans += query(now << 1 | 1, lb, rb) % MOD;
    ans %= MOD;
    return ans;
}
IN void tree_add(int x, int y, const int &delta)
{
    W (top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        add(1, idx[top[x]], idx[x], delta);
        x = fat[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    add(1, idx[x], idx[y], delta);
}
IN int tree_sum(int x, int y)
{
    R int rt = 0;
    W (top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        rt = (rt + query(1, idx[top[x]], idx[x])) % MOD;
        x = fat[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    rt = (rt + query(1, idx[x], idx[y])) % MOD;
    return rt;
}
int main()
{
    int a, b, c, command;
    in(dot), in(q), in(root), in(MOD);
    for (R int i = 1; i <= dot; ++i) in(pre[i]);
    for (R int i = 1; i < dot; ++i)
    {
        in(a), in(b);
        addedge(a, b), addedge(b, a);
    }
    dfs1(root, 0, 1);
    dfs2(root, root);
    build(1, 1, dot);
    W (q--)
    {
        in(command);
        switch (command)
        {
        case 1:
        {
            in(a), in(b), in(c);
            tree_add(a, b, c % MOD);
            break;
        }
        case 2:
        {
            in(a), in(b);
            printf("%d\n", tree_sum(a, b) % MOD);
            break;
        }
        case 3:
        {
            in(a), in(b);
            add(1, idx[a], idx[a] + tot[a] - 1, b % MOD);
            break;
        }
        case 4:
        {
            in(a);
            printf("%d\n", query(1, idx[a], idx[a] + tot[a] - 1) % MOD);
        }
        }
    }
    return 0;
}