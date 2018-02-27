#include <bits/stdc++.h>

using namespace std;

namespace CG
{
template<typename T>
inline T abs(T val) { return val < 0 ? -val : val; }

const double eps = 1e-8;

class Point
{
public:
    double x, y;
    Point() {}
    Point(double a, double b): x(a), y(b)
    {}
    Point operator+ (const Point& a) { return Point(x + a.x, y + a.y); }
    Point operator- (const Point& a) { return Point(x - a.x, y - a.y); }
    Point operator* (const double& a) { return Point(x * a, y * a); }
    Point operator/ (const double& a) { return Point(x / a, y / a); }
    Point operator= (const Point& a) { x = a.x, y = a.y; return Point(x, y); }
    double operator* (const Point& a) { return x * a.y - y * a.x; }
    bool operator< (const Point& a)
    { return fabs(x - a.x) < eps ? y < a.y : x < a.x; }
    bool operator== (const Point& a)
    { return fabs(x - a.x) < eps && fabs(y - a.y) < eps; }
};

class Segments
{
public:
    double a, b;
    int index;
    Segments() {}
    Segments(double x, double y): a(x), b(y)
    {}
    Segments(double x, double y, int i): a(x), b(y), index(i)
    {}
    Segments operator= (const Segments& x)
    { a = x.a, b = x.b, index = x.index; return Segments(x.a, x.b); }
    bool operator== (const Segments& x)
    { return fabs(a - x.a) < eps && fabs(b - x.b) < eps; }
    bool operator< (const Segments& x)
    { return fabs(a - x.a) < eps ? b < x.b : a < x.a; }
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Segments& p)
{
    os << "(" << p.a << ", " << p.b << ")";
    return os;
}

inline Point inter(Segments x, Segments y)
{
    double rex = (double)(x.b - y.b) / (double)(y.a - x.a);
    double rey = x.a * rex + x.b;
    return Point(rex, rey);
}
}

namespace solve
{
using namespace CG;

inline int read()
{
    char c = getchar();
    int ret = 0, f = 1;

    for (; !isdigit(c); f = c == '-' ? -1 : 1, c = getchar());

    for (; isdigit(c); ret = ret * 10 + c - '0', c = getchar());

    return ret * f;
}

template<typename T>
inline bool eql(T a, T b) {
    return fabs(a - b) < eps;
}

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
    solve::solve();
}