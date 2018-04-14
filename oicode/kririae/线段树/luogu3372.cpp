#define ls t[k].son[0]
#define rs t[k].son[1]
#include <iostream>
#include <cstdio>
 #include <cstring>#define ls t[k].son[0]
#define rs t[k].son[1]
#include <iostream>
#include <cstdio>
 #include <cstring>

using namespace std;

namespace SegmentTree
{
const int maxn = 100005;
struct Node
{
    int l, r, son[2];
	long long add, mul;
    long long sum;
    Node() {}
};

Node t[maxn << 2];
int cnt, p;
long long a[maxn];

inline void pushup(int k)
{
    t[k].sum = (t[ls].sum + t[rs].sum);
}

inline void pushdown(int k)
{
     if(t[k].mul != 1)
     {
         t[ls].add = (t[ls].add * t[k].mul);
         t[rs].add = (t[rs].add * t[k].mul);
         t[ls].mul = (t[ls].mul * t[k].mul);
         t[rs].mul = (t[rs].mul * t[k].mul);
         t[ls].sum = (t[ls].sum * t[k].mul);
         t[rs].sum = (t[rs].sum * t[k].mul);
         t[k].mul = 1;
     }
    if(t[k].add)
    {
        t[ls].add = (t[ls].add + t[k].add);
        t[rs].add = (t[rs].add + t[k].add);
         t[ls].sum = (t[ls].sum + t[k].add);
        t[ls].sum = (t[ls].sum + t[k].add * (t[ls].r - t[ls].l + 1));
        t[rs].sum = (t[rs].sum + t[k].add * (t[rs].r - t[rs].l + 1));
        t[k].add = 0;
    }
}

inline void buildTree(int &k, int l, int r)
{
    k = ++cnt;
    t[k].l = l, t[k].r = r, t[k].sum = 0, t[k].add = 0, t[k].mul = 1;
    if(l == r) { t[k].sum = a[l]; return; }
    int mid = (l + r) >> 1;
    buildTree(ls, l, mid), buildTree(rs, mid + 1, r);
    pushup(k);
}

 inline void mul(int k, int l, int r, int val)
 {
     if(t[k].l == l && t[k].r == r)
     {
         t[k].mul = (t[k].mul * val);
         t[k].add = (t[k].add * val);
         t[k].sum = (t[k].sum * val);
         return;
     }
    
     int mid = (t[k].l + t[k].r) >> 1;
     pushdown(k);
    
     if(r <= mid) return mul(ls, l, r, val);
     else if(l >= mid + 1) return mul(rs, l, r, val);
     else mul(ls, l, mid, val), mul(rs, mid + 1, r, val);

     pushup(k);
 }

inline void add(int k, int l, int r, int val)
{
     cout << k << " " << l << " " << r << endl;
    if(t[k].l == l && t[k].r == r)
    {
        t[k].add = (t[k].add + val);
        t[k].sum = (t[k].sum + val * (r - l + 1));
        return;
    }
    int mid = (t[k].l + t[k].r) >> 1;
    pushdown(k);
    
    if(r <= mid) add(ls, l, r, val);
    else if(l >= mid + 1) add(rs, l, r, val);
    else add(ls, l, mid, val), add(rs, mid + 1, r, val);
    
    pushup(k);
}

inline long long query(int k, int l, int r)
{
     cout << k << " " << l << " " << r << endl;
    pushdown(k);
    
    if(t[k].l == l && t[k].r == r)
        return t[k].sum;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    
    int mid = (t[k].l + t[k].r) >> 1;
    if(r <= mid) return query(ls, l, r);
    else if(l >= mid + 1) return query(rs, l, r);
    else return (query(ls, l, mid) + query(rs, mid + 1, r));
}

int n, m, root;
inline void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    buildTree(root, 1, n);
    for (int i = 1; i <= m; ++i)
    {
        char op;
		long long x, y, z;
        cin >> op;
        if(op == 'C')
        {
            cin >> x >> y >> z;
            add(root, x, y, z);
        }
        
        if(op == 'Q')
        {
            cin >> x >> y;
            cout << query(root, x, y) << endl;
        }
    }
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
    SegmentTree::solve();
}

using namespace std;

namespace SegmentTree
{
const int maxn = 100005;
struct Node
{
    int l, r, son[2];
	long long add, mul;
    long long sum;
    Node() {}
};

Node t[maxn << 2];
int cnt, p;
long long a[maxn];

inline void pushup(int k)
{
    t[k].sum = (t[ls].sum + t[rs].sum);
}

inline void pushdown(int k)
{
     if(t[k].mul != 1)
     {
         t[ls].add = (t[ls].add * t[k].mul);
         t[rs].add = (t[rs].add * t[k].mul);
         t[ls].mul = (t[ls].mul * t[k].mul);
         t[rs].mul = (t[rs].mul * t[k].mul);
         t[ls].sum = (t[ls].sum * t[k].mul);
         t[rs].sum = (t[rs].sum * t[k].mul);
         t[k].mul = 1;
     }
    if(t[k].add)
    {
        t[ls].add = (t[ls].add + t[k].add);
        t[rs].add = (t[rs].add + t[k].add);
         t[ls].sum = (t[ls].sum + t[k].add);
        t[ls].sum = (t[ls].sum + t[k].add * (t[ls].r - t[ls].l + 1));
        t[rs].sum = (t[rs].sum + t[k].add * (t[rs].r - t[rs].l + 1));
        t[k].add = 0;
    }
}

inline void buildTree(int &k, int l, int r)
{
    k = ++cnt;
    t[k].l = l, t[k].r = r, t[k].sum = 0, t[k].add = 0, t[k].mul = 1;
    if(l == r) { t[k].sum = a[l]; return; }
    int mid = (l + r) >> 1;
    buildTree(ls, l, mid), buildTree(rs, mid + 1, r);
    pushup(k);
}

 inline void mul(int k, int l, int r, int val)
 {
     if(t[k].l == l && t[k].r == r)
     {
         t[k].mul = (t[k].mul * val);
         t[k].add = (t[k].add * val);
         t[k].sum = (t[k].sum * val);
         return;
     }
    
     int mid = (t[k].l + t[k].r) >> 1;
     pushdown(k);
    
     if(r <= mid) return mul(ls, l, r, val);
     else if(l >= mid + 1) return mul(rs, l, r, val);
     else mul(ls, l, mid, val), mul(rs, mid + 1, r, val);

     pushup(k);
 }

inline void add(int k, int l, int r, int val)
{
     cout << k << " " << l << " " << r << endl;
    if(t[k].l == l && t[k].r == r)
    {
        t[k].add = (t[k].add + val);
        t[k].sum = (t[k].sum + val * (r - l + 1));
        return;
    }
    int mid = (t[k].l + t[k].r) >> 1;
    pushdown(k);
    
    if(r <= mid) add(ls, l, r, val);
    else if(l >= mid + 1) add(rs, l, r, val);
    else add(ls, l, mid, val), add(rs, mid + 1, r, val);
    
    pushup(k);
}

inline long long query(int k, int l, int r)
{
     cout << k << " " << l << " " << r << endl;
    pushdown(k);
    
    if(t[k].l == l && t[k].r == r)
        return t[k].sum;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    
    int mid = (t[k].l + t[k].r) >> 1;
    if(r <= mid) return query(ls, l, r);
    else if(l >= mid + 1) return query(rs, l, r);
    else return (query(ls, l, mid) + query(rs, mid + 1, r));
}

int n, m, root;
inline void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    buildTree(root, 1, n);
    for (int i = 1; i <= m; ++i)
    {
        char op;
		long long x, y, z;
        cin >> op;
        if(op == 'C')
        {
            cin >> x >> y >> z;
            add(root, x, y, z);
        }
        
        if(op == 'Q')
        {
            cin >> x >> y;
            cout << query(root, x, y) << endl;
        }
    }
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
    SegmentTree::solve();
}