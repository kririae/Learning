#include <bits/stdc++.h>
using namespace std;

namespace IO
{
inline char read()
{
    static const int IN_LEN = 1000000;
    static char buf[IN_LEN], *s, *t;
    s == t ? t = (s = buf) +
                 fread(buf, 1, IN_LEN, stdin)
           : 0;
    return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
    static char c;
    static bool iosig;
    for (c = read(), iosig = false;
         !isdigit(c); c = read())
    {
        if (c == -1)
            return;
        c == '-' ? iosig = true : 0;
    }
    for (x = 0; isdigit(c);
         c = read())
        x = (x + (x << 2) << 1) + (c ^ '0');
    iosig ? x = -x : 0;
}
}

namespace kririae
{
const int maxn = 400005;

int n, m, belong[maxn];
unsigned long long res;
unsigned long long a[maxn], s[maxn];
unsigned long long q[maxn];

pair<unsigned long long, unsigned long long> b[maxn];

struct block
{
    int l, r, add; // add -> time
    unsigned long long val, set;
    unsigned long long sum;

    inline pair<int, int> get(int ll, int lr)
    {
        return make_pair(ll >= l && ll <= r ? ll : l,
                         lr >= l && lr <= r ? lr : r);
    }

    inline void set_to(int ll, int lr, int val)
    {
        pair<int, int> ret = get(ll, lr);
        if (ret.first == l && ret.second == r)
        {
            set = val;
        }
        else
        {
            if (add)
            {
                for (int i = l; i <= ret.first - 1; ++i)
                    s[i] += add * a[i];
                for (int i = ret.second + 1; i <= l; ++i)
                    s[i] += add * a[i];
            }
            for (int i = ret.first; i <= ret.second; ++i)
                s[i] = val;
        }
        add = 0;
    }

    inline void add_range(int ll, int lr, int val)
    {
        pair<int, int> ret = get(ll, lr);
        if (set)
            for (int i = l; i <= r; ++i)
                s[i] = set;
        if (ret.first == l && ret.second == r)
        {
            add = val;
        }
        else
        {
            for (int i = ret.first; i <= ret.second; ++i)
                s[i] += (add * a[i]);
        }
    }

    inline unsigned long long get_max()
    {
        return set ? set + (unsigned long long)(add * a[r]) : (unsigned long long)s[r] + (unsigned long long)(add * a[r]);
    }
};

block t[635];

inline void modify_range(int l, int r)
{
    for (int i = belong[l]; i <= belong[r]; ++i)
        ;
}

inline unsigned long long get_point(int val)
{
    int blo = belong[val];
    if (t[blo].set)
        return t[blo].set;
    else
        return s[val] + (a[val] * t[blo].add);
}

inline void solve()
{
    using namespace IO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    //    for (int i = 1; i <= n; ++i)
    //        q[i] = q[i - 1] + a[i];
    //    sort(a + 1, a + n + 1);
    //    int bs = sqrt(n); // init block size
    //    cout << n << " " << bs << endl;
    //    int bn = n / bs + 1;
    //
    //    for (int i = 1; i <= bn; ++i)
    //    {
    //        t[i].l = t[i - 1].r + 1;
    //        t[i].r = t[i].l + bs - 1;
    //    }
    //    t[bn].r = n;
    //
    //    for (int i = 1; i <= bn; ++i)
    //        for (int j = t[i].l; j <= t[i].r; ++j)
    //            belong[j] = i;
    //
    //    for (int i = 1; i <= m; ++i)
    //        cin >> b[i].first >> b[i].second;
    //
    //    for (int rp = 1; rp <= m; ++rp)
    //    {
    //        unsigned long long summ = 0;
    //        int sub = b[rp].first - b[rp - 1].first;
    //        for (int i = 1; i <= bn; ++i) t[i].add_range(1, n, sub); // add range
    //        for (int i = 1; i <= bn; ++i)
    //        {
    //            if(t[i].get_max() >= b[i].second) {
    //                for (int j = t[i].l; j <= t[i].r; ++j)
    //                    if(get_point(j) >= b[i].second) {
    //                        for (int k = j; k <= t[i].r; ++k) summ += (get_point(k) - b[i].second);
    //                        t[i].set_to(j, t[i].r, b[i].second);
    //                        break;
    //                    }
    //                for (int j = i + 1; j <= bn; ++j)
    //                {
    //                    summ += (t[j].sum - b[i].second * (t[j].r - t[j].l + 1));
    //                    t[j].set_to(1, n, b[i].second);
    //                }
    //                break;
    //            }
    //        }
    //        cout << summ << endl;
    //    }
}
}

int main()
{
    kririae::solve();
    return 0;
}