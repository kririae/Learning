// by kririae 2018/2/27
// poj2002...为啥要判4次...2次就WA

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <deque>

using namespace std;

namespace solve
{

inline int read()
{
    char c = getchar();
    int ret = 0, f = 1;

    for (; !isdigit(c);
         f = c == '-' ? -1 : 1, c = getchar());

    for (; isdigit(c);
         ret = ret * 10 + c - '0', c = getchar());

    return ret * f;
}

const int maxn = 1005;
const int mod = 105;
int n;
int a, b;
vector<pair<int, int> > lst[mod];
vector<pair<int, int> > all;

inline int hash(pair<int, int> p)
{
    int x = (long long)(p.first * p.second) % mod;
    int s = (p.first + p.second) % mod;
    return abs(x + s) % mod;
}

inline void insert(pair<int, int> p)
{
    lst[hash(p)].push_back(p);
}

inline bool exist(pair<int, int> p)
{
    int hashrs = hash(p);

    for (int i = 0; i < lst[hashrs].size(); ++i)
        if (lst[hashrs][i] == p) return true;

    return false;
}

inline void solve()
{
    for (;;)
    {
        n = read();

        if (n == 0) break;

        int cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            a = read(), b = read();
            all.push_back(make_pair(a, b));
            insert(make_pair(a, b));
        }

        for (register int i = 0; i < all.size(); ++i)
        {
            for (register int j = i + 1; j < all.size(); ++j)
            {
                // emmmmmmmmmmmmm...
                bool ext = false;

                pair<int, int>& p1 = all[i];
                pair<int, int>& p2 = all[j];

                int suby = p2.second - p1.second;
                int subx = p2.first - p1.first;

                int tempx = p1.first + suby;
                int tempy = p1.second - subx;
                int tempx1 = p2.first + suby;
                int tempy1 = p2.second - subx;

                if (exist(make_pair(tempx, tempy)) &&
                    exist(make_pair(tempx1, tempy1))) ++cnt;

                tempx = p1.first - suby;
                tempy = p1.second + subx;
                tempx1 = p2.first - suby;
                tempy1 = p2.second + subx;

                if (exist(make_pair(tempx, tempy)) &&
                    exist(make_pair(tempx1, tempy1))) ++cnt;
            }
        }

        cout << cnt / 4 << endl;

        for (int i = 0; i < mod; ++i) lst[i].resize(0);

        all.resize(0);
    }
}
}
int main()
{
    solve::solve();
    return 0;
}