#include <bits/stdc++.h>
using namespace std;

namespace kririae
{
inline char read()
{
    static const int IN_LEN = 1000000;
    static char buf[IN_LEN], *s, *t;
    s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
    return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T& x)
{
    static char c;
    static bool iosig;
    for (c = read(), iosig = false; !isdigit(c); c = read())
    {
        if (c == -1) return;
        c == '-' ? iosig = true : 0; 
    }
    for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
    iosig ? x = -x : 0;
}

int n, m, q, u, v, t, val, cnt;
long long add;
double p;
priority_queue<int> q1;
deque<int> q2, q3;
vector<int> res;

inline void init()
{
    read(n), read(m), read(q), 
    read(u), read(v), read(t);
    p = double(u) / double(v);
    for (int i = 1; i <= n; ++i)
    {
        read(val);
        q1.push(val);
    }
}

inline int gmax()
{
    int tmp = 0;
    tmp = q1.empty() ? tmp : q1.top();
    tmp = q2.empty() ? tmp : max(q2.front(), tmp);
    tmp = q3.empty() ? tmp : max(q3.front(), tmp);
    if(!q1.empty() && tmp == q1.top()) { q1.pop(); return tmp + add; }
    if(!q2.empty() && tmp == q2.front()) { q2.pop_front(); return tmp + add; }
    if(!q3.empty() && tmp == q3.front()) { q3.pop_front(); return tmp + add; }
}

inline void solve()
{
    init();
    for (int i = 1; i <= m; ++i, add += q)
    {
        int tmp = gmax();
        if(i % t == 0) cout << tmp << " ";
        q2.push_back(int(tmp * p) - q - add);
        q3.push_back(tmp - int(tmp * p) - q - add);
    }
    cout << endl;
    for (int i = 0; i < q2.size(); ++i) res.push_back(q2[i] + add);
    for (int i = 0; i < q3.size(); ++i) res.push_back(q3[i] + add);
    int si = q1.size();
    for (int i = 0; i < si; ++i) { res.push_back(q1.top()); q1.pop(); }
    sort(res.begin(), res.end(), [](int a, int b){ return a > b; });
    for (int i = 0; i < (n + m); ++i) 
    {
        if((i + 1) % t == 0) cout << res[i] << " ";
    }
}
}

int main()
{
    kririae::solve();
    return 0;
}