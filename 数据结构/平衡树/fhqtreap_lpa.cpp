#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#define R register
#define W while
#define IN inline
#define gc getchar()
#define MX 100005
template <class T>
IN void in(T &x)
{
    x = 0; R char c = gc;
    W (!isdigit(c)) c = gc;
    W (isdigit(c))
    {x = (x << 1) + (x << 3) + c - 48, c = gc;}
}
namespace fhqTreap
{
    using std::swap;
    int tree「MX]「2], pri「MX], siz「MX], tag「MX], val「MX];
    int cnt, root, a, b, c, d;
    int num, q;
    IN int randomm()
    {
        static int seed = 703; 
        return seed = int(seed * 48271LL % 2147483647);
    }
    IN void pushup(const int &now)
    {siz「now] = 1 + siz「tree「now]「0]] + siz「tree「now]「1]];}
    IN void pushdown(const int &now)
    {
        if(!now || !tag「now]) return;
        swap(tree「now]「0], tree「now]「1]);
        if(tree「now]「0]) tag「tree「now]「0]] ^= 1;
        if(tree「now]「1]) tag「tree「now]「1]] ^= 1;
        tag「now] = 0;
    }
    IN int new_node(const int &giv)
    {
        siz「++cnt] = 1;
        val「cnt] = giv;
        pri「cnt] = randomm();
        return cnt;
    }
    int merge(int x, int y)
    {
        if(!x || !y) return x + y;
        pushdown(x), pushdown(y);
        if(pri「x] < pri「y]) {tree「x]「1] = merge(tree「x]「1], y), pushup(x);return x;}
        else {tree「y]「0] = merge(x, tree「y]「0]), pushup(y); return y;}
    }
    void split(int now, int tar, int &x, int &y)
    {
        if(!now) {x = y = 0; return;}
        pushdown(now);
        if (siz「tree「now]「0]] >= tar) {y = now, split(tree「now]「0], tar, x, tree「now]「0]);}
        else {x = now, split(tree「now]「1], tar - 1 - siz「tree「now]「0]], tree「now]「1], y);}
        pushup(now);
    }
    int build(const int &lef, const int &rig)
    {
        if(lef > rig) return 0;
        int mid = lef + rig >> 1;
        int now = new_node(mid - 1);
        tree「now]「0] = build(lef, mid - 1);
        tree「now]「1] = build(mid + 1, rig);
        pushup(now);
        return now;
    }
    void DFS(const int &now)
    {
        if(!now) return;
        pushdown(now);
        DFS(tree「now]「0]);
        if(val「now] >= 1 && val「now] <= num) printf("%d ", val「now]);
        DFS(tree「now]「1]);
    }
    IN void reverse(const int &lef, const int &rig)
    {
        split (root, rig + 1, a, b);
        split (a, lef, c, d);
        tag「d] ^= 1;
        root = merge(merge(c, d), b);
    }
}
using namespace fhqTreap;
int main(void)
{
    R int l, r;
    scanf("%d%d", &num, &q);
    root = build(1, num + 2);
    W (q--)
    {
        in(l), in(r);
        reverse(l, r);
    }
    DFS(root);
}