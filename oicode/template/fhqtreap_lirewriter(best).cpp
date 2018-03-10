// lirewriter ver
// 全无脑merge split 我喜欢
#include <bits/stdc++.h>
#define ls t[k].son[0]
#define rs t[k].son[1]
using namespace std;

namespace fhqtreap
{
const int maxn = 1e5 + 5;

struct node
{
    int size, val, key;
    int son[2];
    node() {}
};

node t[maxn];
int cnt, root;

inline void pushup(int k)
{
    t[k].size = t[ls].size + t[rs].size + 1;
}

inline void make_heap(int& k, int val)
{
    k = ++cnt, t[k].val = val, t[k].size = 1, t[k].key = rand();
}

inline void merge(int& k, int a, int b)
{
    if (!a || !b) { k = a + b; return; } // 取有值的一个
    if (t[a].key < t[b].key) k = a, merge(rs, rs, b);
    else k = b, merge(ls, a, ls);
    pushup(k);
}

inline void split(int k, int& a, int& b, int key)
{
    if (!k) { a = b = 0; return; }
    if (t[k].val <= key) a = k, split(rs, rs, b, key);
    else b = k, split(ls, a, ls, key);
    pushup(k);
}

inline void insert(int val)
{
    int k; make_heap(k, val);
    // 把新加入的点放到索引k上
    int a, b; a = b = 0;
    split(root, a, b, val); // 以val分割到左子树和右子树
    // 以val split到a, b上
    merge(a, a, k); // 把小的一边和它合并
    merge(root, a, b); // 把a, b合并到root上
}

inline void del(int val)
{
    int k, a, b; k = a = b = 0;
    split(root, a, b, val); // 按照val分割到a, b
    split(a, a, k, val - 1); // 按照val - 1把a子树分割到a, k上
    merge(k, ls, rs); // 删除当前节点
    merge(a, a, k); // 无脑合并
    merge(root, a, b);
}

inline int getrank(int val)
{
    int a, b; a = b = 0;
    split(root, a, b, val - 1);
    int ans = t[a].size + 1;
    merge(root, a, b);
    return ans;
}

inline int getkth(int k, int val)
{
    for (;;)
    {
        if (t[ls].size >= val) k = ls;
        else if (t[ls].size + 1 == val) return k;
        else val -= (t[ls].size + 1), k = rs;
    }
}

inline int pre(int val)
{
    int a, b; a = b = 0;
    split(root, a, b, val - 1);
    int ans = getkth(a, t[a].size);
    merge(root, a, b);
    return ans;
}

inline int nxt(int val)
{
    int a, b; a = b = 0;
    split(root, a, b, val);
    int ans = getkth(b, 1);
    merge(root, a, b);
    return ans;
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    using namespace fhqtreap;
    srand(19260817);
    return 0;
}