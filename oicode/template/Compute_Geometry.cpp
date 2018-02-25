// by kririae
// Kririae's Compute Geometry Library

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <deque>

using std::cin;
using std::endl;
using std::cout;

namespace Basic
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
}

namespace Compute_Geometry
{
    using namespace Basic;
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
        Vector(T a, T b) :x(a), y(b){}

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
        return Point(double(a), double(b));
    }

    bool parallel(Point a1, Point a2, Point b1, Point b2)
    {
        return abs((a2.x - a1.x) * (b2.y - b1.y) - (b2.x - b1.x) * (a2.y - a1.y)) < eps;
    }

    std::ostream &operator<<(std::ostream &os, const Point &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    bool a_left(Point a, Point b)
    {
        return a * b < -eps;
    }

    double area(Point a, Point b, Point c)
    {
        return abs((a - c) * (b - c) / 2.0);
    }

    Point inter(Point a1, Point a2, Point b1, Point b2)
    {
        double s1 = area(b1, b2, a1), s2 = area(b1, b2, a2);
        return (a1 - a2) / (s1 + s2) * s2 + a2;
    }

    inline bool eql(double a, double b)
    {
        if(abs(a - b) < eps) return true;
        return false;
    }
    
    bool intersect(Point a1, Point a2, Point b1, Point b2)
    {
        Vector v(a1, a2);
        if((v * Vector(a1, b1)) * (v * Vector(a1, b2)) < eps) return true;
        return false;
    }
    double dis(const Point &a, const Point &b)
    {
        return sqrt((a.x - b.x) * (a.x - b.x)
                    + (a.y - b.y) * (a.y - b.y));
    }

    std::pair<int, int> manhattan_dis(const Point &a, const Point &b) // []
    {
        return std::make_pair(abs(a.x - b.x), abs(a.y - b.y));
    }

    namespace algorithms
    {

        // inline bool angle_compare
        // (Compute_Geometry::Point a, Compute_Geometry::Point b)
        // {
        //  return std::atan2(a.y, a.x) < std::atan2(b.y, b.x);
        // }

        inline std::vector<Compute_Geometry::Point>
        convex_package(std::vector<Compute_Geometry::Point> a)
        {
            // 是否利用极角排序 -> type(未测试)
            using std::vector;
            using std::deque;
            using namespace Compute_Geometry;
            static deque<Point> ret;

            // if (type) sort(a.begin(), a.end(), angle_compare);
            // else sort(a.begin(), a.end());
            // sort(a.begin(), a.end());
            for (int i = 0; i < a.size(); ++i)
            {
                while(ret.size() > 1 && a_left(
                            ret[ret.size() - 1] - ret[ret.size() - 2],
                            a[i] - ret[ret.size() - 1]))
                    ret.pop_back();
                ret.push_back(a[i]);
            }
            int size = ret.size();
            for (int i = a.size() - 2; i >= 0; --i)
            {
                while(ret.size() > size && a_left(
                            ret[ret.size() - 1] - ret[ret.size() - 2],
                            a[i] - ret[ret.size() - 1]))
                    ret.pop_back();
                ret.push_back(a[i]);
            }
            return vector<Point>(ret.begin(), ret.end());
            // 有序输出
        }

        inline double
        polygon_area(const std::vector<Compute_Geometry::Point> &a)
        {
            double tot = 0;
            for (int i = 1; i < a.size() - 1; ++i)
                tot += area(a[0], a[i], a[i + 1]);
            return tot;
        }
    }
}

namespace solve
{
    using namespace Compute_Geometry;
    using namespace std;

    inline void init()
    {
    }

    inline void solve()
    {
        init();

    }
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    solve::solve();
    return 0;
}