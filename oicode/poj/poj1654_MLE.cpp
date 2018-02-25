/*
 * by kririae
 * 2018/2/25
 * statuc: MLE...GIVEUP
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

namespace solve
{

}

namespace Compute_Geometry
{
    using namespace solve;
    const double eps = 1e-8;

    class Point
    {
    public:
        double x;
        double y;

        Point() {}

        template<typename T>
        Point(T a, T b):
            x(double(a)), y(double(b)) {}

        friend std::ostream &operator<<(std::ostream &os, const Point &p);

        bool operator== (const Point &a)
        {
            return abs(x - a.x) < eps && abs(y - a.y) < eps;
        }

        Point operator+ (const Point &a)
        {
            return Point(x + a.x, y + a.y);
        }

        Point operator- (const Point &a)
        {
            return Point(x - a.x, y - a.y);
        }

        bool operator< (const Point &a)
        {
            return abs(x - a.x) < eps ? y < a.y : x < a.x;
        }

        double operator* (const Point &a)
        {
            return x * a.y - a.x * y;
        }

        Point operator* (double val)
        {
            return Point(x * val, y * val);
        }

        Point operator/ (double val)
        {
            return Point(x / val, y / val);
        }
    };

    class Vector
    {
    public:
        double x;
        double y;

        Vector(Point a, Point b)
        {
            x = b.x - a.x, y = b.y - a.y;
        }

        template<typename T>
        Vector(T a, T b) : x(a), y(b) {}

        Vector operator+ (const Vector &a)
        {
            return Vector(x + a.x, y + a.y);
        }

        Vector operator- (const Vector &a)
        {
            return Vector(x - a.x, y - a.y);
        }

        double operator* (const Vector &a)
        {
            return x * a.y - a.x * y;
        }
    };

    template<typename T>
    inline Point make_point(T a, T b)
    {
        return Point((double)(a), (double)(b));
    }

    std::ostream &operator<<(std::ostream &os, const Point &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    double area(const Point &a, const Point &b, const Point &c)
    {
        return std::fabs((double)((a - c) * (b - c)) / 2.0);
    }

    namespace algorithms
    {
        inline double
        polygon_area(const std::vector<Compute_Geometry::Point> &a)
        {
            double tot = 0;
            for (int i = 1; i < a.size() - 1; ++i)
            {
                tot += area(a[0], a[i], a[i + 1]);
            }
            return tot;
        }
    }
}

namespace solve
{
    template<typename T>
    inline T abs(T val)
    {
        return val < 0 ? -val : val;
    }

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

    inline int read(int x[])
    {
        static char c;
        int cnt = 0;
        for(;;)
        {
            c = getchar();
            if(c == '5') return 0;
            x[++cnt] = c - '0';
        }
        return cnt;
    }

    inline void read(int &x)
    {
        static char c;
        static bool iosig;
        for (c = getchar(), iosig = false;
                !isdigit(c); c = getchar())
        {
            if (c == -1) return;
            c == '-' ? iosig = true : 0;
        }
        for (x = 0; isdigit(c);
                c = getchar())
            x = (x + (x << 2) << 1) + (c ^ '0');
        iosig ? x = -x : 0;
    }
    using namespace Compute_Geometry;
    using namespace std;
    using namespace Compute_Geometry::algorithms;
    const int maxn = 1000005;
    int t;
    char a[maxn];

    inline void init()
    {
        cin >> t;
    }

    vector<Point> vet;

    inline void solve()
    {
        init();
        while(t--)
        {
            cin >> a;
            int cnt = std::strlen(a);
            vet.push_back(make_point(0, 0));
            int sx = 0, sy = 0;
            double tot = 0;
            for (register int i = 1; i <= cnt; ++i)
            {
                switch(a[i])
                {
                case '8':
                    ++sy;
                    break;
                case '2':
                    --sy;
                    break;
                case '6':
                    ++sx;
                    break;
                case '4':
                    --sx;
                    break;
                case '9':
                    ++sx;
                    ++sy;
                    break;
                case '7':
                    --sx;
                    ++sy;
                    break;
                case '3':
                    ++sx;
                    --sy;
                    break;
                case '1':
                    --sx;
                    --sy;
                    break;
                }
                vet.push_back(make_point(sx, sy));
            }
            // for (int i = 0; i < vet.size(); ++i)
            //      cout << vet[i] << endl;
            cout << polygon_area(vet) << endl;
            memset(a, 0, sizeof(a));
            vector<Point>().swap(vet);
        }
    }
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    solve::solve();
    return 0;
}