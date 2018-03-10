/*
    Treap[Merge,Split]
    by Memphis
*/

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;
#define maxn 2000005
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)

struct Treap
{
    Treap* l, *r;
    int fix, key, size;
    Treap(int key_): fix(rand()), key(key_), l(NULL),
        r(NULL), size(1) {}

    inline void updata()
    {
        size = 1 + (l ? l->size : 0) + (r ? r->size : 0);
    }
}* root;
typedef pair<Treap*, Treap*>
Droot; //用来Split返回两个根

inline int Size(Treap* x)
{
    return x ? x->size :
           0;   //这样求size可以防止访问空指针
}

Treap* Merge(Treap* A, Treap* B) //合并操作
{
    if (!A)return B;

    if (!B)return A;

    if (A->fix < B->fix)
    {
        A->r = Merge(A->r, B);
        A->updata();
        return A;
    }

    else
    {
        B->l = Merge(A, B->l);
        B->updata();
        return B;
    }
}

Droot Split(Treap* x, int k) //拆分操作
{
    if (!x)return Droot(NULL, NULL);

    Droot y;

    if (Size(x->l) >= k)
    {
        y = Split(x->l, k);
        x->l = y.second;
        x->updata();
        y.second = x;
    }

    else
    {
        y = Split(x->r, k - Size(x->l) - 1);
        x->r = y.first;
        x->updata();
        y.first = x;
    }

    return y;
}

Treap* Build(int* a) //建造操作
{
    static Treap* stack[maxn], *x, *last;
    int p = 0;
    rep(i, 1, a[0])
    {
        x = new Treap(a[i]);
        last = NULL;

        while (p && stack[p]->fix > x->fix)
        {
            stack[p]->updata();
            last = stack[p];
            stack[p--] = NULL;
        }

        if (p) stack[p]->r = x;

        x->l = last;
        stack[++p] = x;
    }

    while (p) stack[p--]->updata();

    return stack[1];
}

int Findkth(int k) //查找第K小
{
    Droot x = Split(root, k - 1);
    Droot y = Split(x.second, 1);
    Treap* ans = y.first;
    root = Merge(Merge(x.first, ans), y.second);
    return ans->key;
}

int Getkth(Treap* x,
           int v) //询问一个数是第几大
{
    if (!x)return 0;

    return v < x->key ? Getkth(x->l, v) : Getkth(x->r,
            v) + Size(x->l) + 1;
}

void Insert(int v) //插入操作
{
    int k = Getkth(root, v);
    Droot x = Split(root, k);
    Treap* n = new Treap(v);
    root = Merge(Merge(x.first, n), x.second);
}

void Delete(int k) //删除操作
{
    Droot x = Split(root, k - 1);
    Droot y = Split(x.second, 1);
    root = Merge(x.first, y.second);
}

int a[maxn], M, x, y;

int main()
{
    freopen("bst.in", "r", stdin);
    freopen("bst.out", "w", stdout);

    scanf("%d", a);
    rep(i, 1, a[0]) scanf("%d", a + i);
    sort(a + 1, a + 1 + a[0]);
    root = Build(a);

    scanf("%d", &M);

    while (M--)
    {
        char ch = getchar();

        while (ch != 'Q' && ch != 'A' &&
               ch != 'D') ch = getchar();

        scanf("%d", &x);

        if (ch == 'Q') printf("%d\n", Findkth(x));

        if (ch == 'A') Insert(x);

        if (ch == 'D') Delete(x);
    }
}