#define ls t[k].son[0]
#define rs t[k].son[1]
#include <bits/stdc++.h>

using namespace std;

namespace SegmentTree
{
const int maxn = 1e6 + 5;
struct Node
{
    int l, r, add, son[2]；
    long long sum;
    Node() {}
};

Node t[maxn << 2];
int cnt;

inline void pushup(int k)
{
    t[k].sum = t[ls].sum + t[rs].sum;
}

inline void pushdown(int k)
{
    if(!t[k].add) return;
    
}

inline void buildTree(int &k, int l, int r)
{
    k = ++cnt;
    t[k].l = l, t[k].r = r, t[k].sum = 0, t[k].add = 0;
    if(l == r) { t[k].sum = a[l]; return; }
    int mid = (l + r) >> 1;
    buildTree(ls, l, mid), buildTree(rs, mid + 1, r);
    pushup(k);
}

inline void add(int k, int ql, int qr, int val)
{
    if(t[k].l == ql && t[k].r == qr)
    {
        t[k].add += val;
        t[k].summ += (t[k].r - t[k].l + 1) * val;
    }
    pushdown(k);
    int mid = (ql + qr) >> 1;
    if(qr <= mid) add(ls, ql, qr, val);
    if(ql >= mid + 1) add(rs, ql, qr, val);
    if(qr > mid && ql <= mid) add(ls, ql, mid, val), add(rs, mid + 1, qr, val);
    pushup(k);
}

inline void solve()
{
    
}
}

int main()
{
}