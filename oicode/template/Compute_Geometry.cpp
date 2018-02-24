// by kririae
// Kririae's Compute Geometry Library

#include <bits/stdc++.h>

<<<<<<< HEAD
namespace Basic {
template <typename T> inline T abs(T val) { return val < 0 ? -val : val; }

template <typename T> inline T min(T a, T b) { return a < b ? a : b; }

template <typename T> inline T max(T a, T b) { return a < b ? b : a; }
} // namespace Basic

namespace Compute_Geometry {
using namespace Basic;

const double eps = 1e-8;
class Point {
public:
  double x;
  double y;

  Point() {}
  Point(double a, double b) : x(a), y(b) {}

  bool operator==(const Point &a) {
    return abs(x - a.x) < eps && abs(y - a.y) < eps;
  }

  Point operator+(const Point &a){return Point(x + a.x, y + a.y)}

  Point
  operator-(const Point &a) {
    return Point(x - a.x, y - a.y);
  }

  Point operator<(const Point &a) { return x == a.x ? y < a.y : x < a.x; }

  double operator*(const Point &a) { return x * a.y - a.x * y; }

  Point operator*(double val) { return Point(x * val, y * val); }

  Point operator/(double val) { return Point(x / val, y / val); }
}


	bool a_left(const Point &a, const Point &b)
	{
  return a * b < -eps;
}

double area(const Point &a, const Point &b, Point c) {
  return abs((a - c) * (b - c) / 2.0);
}

Point inter(const Point &a1, const Point &a2, const Point &b1,
            const Point &b2) {
  // intersection
  double s1 = area(b1, b2, a1), s2 = area(b1, b2, a2);
  return (a1 - a2) / (s1 + s2) * s2 + a2;
}

double dis(const Point &a, const Point &b) {
  return sqrt((a.x - b.x) * (a.x * b.x) + (a.y - b.y) * (a.y - b.y));
}

double qdis(const Point &a, const Point &b) {
  double number = (a.x - b.x) * (a.x * b.x) + (a.y - b.y) * (a.y - b.y);
  long long i;
  double half = number * 0.5, ret;
  const float threehalfs = 1.5F;
  ret = number;
  i = (long long)(ret);
  i = 0x5f3759df - (i >> 1);
  ret = double(i);
  ret = ret * (1.5 - (half * ret * ret));
  return 1 / ret;
}
#if __cplusplus < 201103L
std::pair<int, int> manhattan_dis(const Point &a, const Point &b) {
  return std::make_pair(abs(a.x - b.x), abs(a.y - b.y));
}
#elif
std::vector<int> manhattan_dis(const Point &a, const Point &b) {
  return {abs(a.x - b.x), abs(a.y - b.y)};
=======
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
        Point(double a, double b):
            x(a), y(b) {}

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

    bool intersect(Point a1, Point a2, Point b1, Point b2) 
    {
        Point interse = inter(a1, a2, b1, b2);
        return parallel(interse, b2, b1, b2);
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

    template<typename T>
    inline Point make_point(T a, T b)
    {
        return Point(double(a), double(b));
    }

    namespace algorithms
    {
        inline std::vector<Compute_Geometry::Point>
        convex_package(std::vector<Compute_Geometry::Point> a) 
        {
            using std::vector;
            using std::deque;
            using namespace Compute_Geometry;
            static deque<Point> ret;
            sort(a.begin(), a.end());
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

        inline bool angle_compare
        (Compute_Geometry::Point a, Compute_Geometry::Point b)
        {
        	return atan2(a.y, a.x) < atan2(b.y, b.x);
        }

        inline double // without test
        polygon_area_without_sort(std::vector<Compute_Geometry::Point> a)
        {
        	// auto angle_compare = 
        	// [](Compute_Geometry::Point a, Compute_Geometry::Point b)
        	// { atan2(a.y, a.x) < atan2(b.y, b.x); };
        	sort(a.begin(), b.begin(), angle_compare)
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
        cout << intersect(Point(0, 2), Point(1, 1), Point(1, 0), Point(3, 3)) << endl;
    }
>>>>>>> cba2985724e624c5a8bf4e3dbcee36700254ff61
}
#endif
} // namespace Compute_Geometry

<<<<<<< HEAD
int main() {
  // 未测试
  return 0;
=======
int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    solve::solve();
    return 0;
>>>>>>> cba2985724e624c5a8bf4e3dbcee36700254ff61
}