/*
 * by kririae
 * 2018/2/23
 * get_hash
 * SnowflakeSnowSnowflakes
 * poj3349
 */

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

namespace solve
{

    template <typename T>
    inline T min(T a, T b)
    {
        return a < b ? a : b;
    }

    template <typename T>
    inline T max(T a, T b)
    {
        return a < b ? b : a;
    }

    inline char read()
    {
        static const int IN_LEN = 1000000;
        static char buf[IN_LEN], *s, *t;
        s == t ? t = (s = buf) +
                     fread(buf, 1, IN_LEN, stdin) : 0;
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
            if (c == -1) return;
            c == '-' ? iosig = true : 0;
        }
        for (x = 0; isdigit(c);
                c = read())
            x = (x + (x << 2) << 1) + (c ^ '0');
        iosig ? x = -x : 0;
    }

    const int p = 99991;
    class Snowflake 
    {
        public:
        int val[6];
        int get_hash()
        {
            // initalize get_hash value
            int sum = 0, mul = 1;
            for (int i = 0; i < 6; ++i)
            {
                sum = (sum + val[i]) % p;
                mul = (long long)mul * val[i] % p;
            }
            return (sum + mul) % p;
        }

        bool operator==(const Snowflake (&a)) const
        {
            bool eql = true;
            for (int i = 0; i < 6; ++i)
            {
                for (int j = 0; j < 6; ++j) 
                for (int k = 0; k < 6; ++k) 
                if(val[(i + k) % 6] != a.val[(j + k) % 6]) eql = false;
            }
            return eql;
        }
    };

    const int maxn = 1e4 + 5;
    int n;
    int tot = 0;
    vector<Snowflake> t[p];

    inline bool insert(const Snowflake (&val))
    {
        int get_hash_res = val.get_hash();
        for (int i = 0; i < t[get_hash_res].size(); ++i)
            if(val == t[get_hash_res][i]) return true;
        t[get_hash_res].push_back(val);
        return false;
    }

    inline void init()
    {
        read(n);
        int a, b, c, d, e, f;
        Snowflake current;
        for (int i = 1; i <= n; ++i)
        {
            // 循环展开加速
            read(current.val[0]), read(current.val[1]), read(current.val[2]),
            read(current.val[3]), read(current.val[4]), read(current.val[5]);
            if (insert(current))
            {
                puts("Twin Snowflakes found.");
                return 0;
            }
        }
        puts("No two Snowflakes are alike.");
    }

    inline void solve()
    {
        init();
    }
}

int main()
{
    solve::solve();
    return 0;
}