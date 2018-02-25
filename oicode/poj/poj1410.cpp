// poj1410
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
    
    std::ostream &operator<<(std::ostream &os, const Vector &p)
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
    
    bool intersect_with_line(Point a1, Point a2, Point b1, Point b2) // 线段和直线
    {
        Vector v(a1, a2);
        cout << v << endl;
        if((v * Vector(a1, b1)) * (v * Vector(a1, b2)) < eps) return true;
        return false;
    }
    
    bool intersect_with_segment(Point a1, Point a2, Point b1, Point b2) // 线段和线段
    {
        return (Vector(b1, b2) * Vector(b1, a1)) * (Vector(b1, b2) * Vector(b1, a2)) <= 0 &&
        (Vector(a1 , a2) * Vector(a1, b2)) * (Vector(a1, a2) * Vector(a1, b1)) <= 0;
    }
    
    bool point_on_segment(Point x, Point a1, Point a2)
    {
        Vector v1(a1, a2), v2(a1, x);
        if(abs(v1 * v2) < eps && x.x >= min(a1.x, a2.x) && x.x <= max(a1.x, a2.x)
        && x.y >= min(a1.y, a2.y) && x.y <= max(a1.y, a2.y)) return true;
        return false;
    }
    
    bool intersect(Point a1, Point a2, Point b1, Point b2) // 线段和线段
    {
        if(point_on_segment(a1, b1, b2) || point_on_segment(a2, b1, b2)
        || point_on_segment(b1, a1, a2) || point_on_segment(b2, a1, a2)) return true;
        if(a1.x >= min(b1.x, b2.x) && a1.x <= max(b1.x, b2.x)
        && a1.y >= min(b1.y, b2.y) && a1.y <= max(b1.y, b2.y)
        && a2.x >= min(b1.x, b2.x) && a2.x <= max(b1.x, b2.x)
        && a2.y >= min(b1.y, b2.y) && a2.y <= max(b1.y, b2.y)) return true;
        return (Vector(b1, b2) * Vector(b1, a1)) * (Vector(b1, b2) * Vector(b1, a2)) < 0 &&
        (Vector(a1 , a2) * Vector(a1, b2)) * (Vector(a1, a2) * Vector(a1, b1)) < 0;
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
        inline std::vector<Compute_Geometry::Point>
        convex_package(std::vector<Compute_Geometry::Point> a)
        {
            // 是否利用极角排序 -> type(未测试)
            using std::vector;
            using std::deque;
            using namespace Compute_Geometry;
            static deque<Point> ret;

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
        polygon_area(std::vector<Compute_Geometry::Point> a)
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
    int t;
    int xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
    inline void init()
    {
        cin >> t;
    }

    inline void solve()
    {
        init();
        while(t--)
        {
            cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop >> xright >> ybottom;
            if(xleft > xright) std::swap(xleft, xright);
            if(ybottom > ytop) std::swap(ybottom, ytop);
            Point s(xstart, ystart), e(xend, yend); // 相交的直线。
            Point zs(xleft, ytop), zx(xleft, ybottom), ys(xright, ytop), yx(xright, ybottom);
            if(intersect(s, e, zs, ys) ||
               intersect(s, e, zs, zx) || 
               intersect(s, e, ys, yx) || 
               intersect(s, e, zx, yx) ||
               intersect(s, e, zx, ys))
                cout << "T" << endl;
            else cout << "F" << endl;
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