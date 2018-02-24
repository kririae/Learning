// by kririae
// 2018/2/23



// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

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
    using std::ostream;
	const double eps = 1e-8;
	class Point
	{
	public:
		double x;
		double y;

		Point() {}
		Point(double a, double b):
		x(a), y(b) {}
		
		friend ostream& operator<<(ostream &os, const Point &p); 

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
			return abs(x - a.x) < eps ? y - a.y : x < a.x;
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

    ostream& operator<<(ostream &os, const Point &p){  
        os << "(" << p.x << ", " <<p.y << ")";  
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

	Point inter(Point a1, Point &a2, Point b1, Point b2)
	{
		// intersection
		double s1 = area(b1, b2, a1), s2 = area(b1, b2, a2);
		return (a1 - a2) / (s1 + s2) * s2 + a2;
	}

	double dis(const Point &a, const Point &b)
	{
		return sqrt((a.x - b.x) * (a.x - b.x)
		+ (a.y - b.y) * (a.y - b.y));
	}

	std::pair<int, int> manhattan_dis(const Point &a, const Point &b)
	{
		return std::make_pair(abs(a.x - b.x), abs(a.y - b.y));
	}
	
	template<typename T>
	inline Point make_point(T a, T b)
	{
	    return Point(double(a), double(b));
	}
}

inline std::vector<Compute_Geometry::Point> 
convex_package(std::vector<Compute_Geometry::Point> a)
{
    using std::vector;
    using std::deque;
	using namespace Compute_Geometry;
	static deque<Point> ret;
	sort(a.begin(), a.end());
	// auto st = a[0]; start point(the leftest point)
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
}

int main()
{
	// luogu 测试成功
    using namespace std;
    using namespace Compute_Geometry;
    cin.tie(0);
    ios::sync_with_stdio(false);
	int n;
	cin >> n;
	double a, b;
	vector<Point> t;
	for (register int i = 0; i < n; ++i) 
	{
	    cin >> a >> b;
	    t.push_back(make_point(a, b));
	}
	auto res = convex_package(t);
	double tot = 0;
	for (int i = 0; i < res.size() - 1; ++i)
	{
	    tot += dis(res[i], res[i + 1]);
	    // cout << res[i].x << " " << res[i].y << endl;
	    // cout << res[i] << " -> " << res[i + 1] << " " << dis(res[i], res[i + 1]) << endl;
	}
	printf("%.2lf\n", tot);
	return 0;
}