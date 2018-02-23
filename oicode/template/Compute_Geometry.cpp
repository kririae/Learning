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

	const double eps = 1e-8;
	class Point
	{
	public:
		double x;
		double y;

		Point() {}
		Point(double a, double b):
		x(a), y(b) {}

		bool operator== (const Point &a)
		{
			return abs(x - a.x) < eps && abs(y - a.y) < eps;
		}

		Point operator+ (const Point &a)
		{
			return Point(x + a.x, y + a.y)
		}

		Point operator- (const Point &a)
		{
			return Point(x - a.x, y - a.y);
		}

		Point operator< (const Point &a)
		{
			return x == a.x ? y < a.y : x < a.x;
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
	}


	bool a_left(const Point &a, const Point &b)
	{
		return a * b < -eps;
	}

	double area(const Point &a, const Point &b, Point c)
	{
		return abs((a - c) * (b - c) / 2.0);
	}

	Point inter(const Point &a1, const Point &a2, const Point &b1, const Point &b2)
	{
		// intersection
		double s1 = area(b1, b2, a1), s2 = area(b1, b2, a2);
		return (a1 - a2) / (s1 + s2) * s2 + a2;
	}

	double dis(const Point &a, const Point &b)
	{
		return sqrt((a.x - b.x) * (a.x * b.x)
		+ (a.y - b.y) * (a.y - b.y));
	}

	double qdis(const Point &a, const Point &b)
	{
		double number = (a.x - b.x) * (a.x * b.x)
		+ (a.y - b.y) * (a.y - b.y);
		long long i;
		double half = number * 0.5, ret;
		const float threehalfs = 1.5F;
		ret = number;
		i = (long long)(ret);   
		i = 0x5f3759df - (i >> 1);              
		ret = double(i);
		ret = ret * (1.5 - (half * ret * ret ));  
		return 1 / ret;
	}
#if __cplusplus < 201103L  
	std::pair<int, int> manhattan_dis(const Point &a, const Point &b)
	{
		return std::make_pair(abs(a.x - b.x), abs(a.y - b.y));
	}
#elif
	std::vector<int> manhattan_dis(const Point &a, const Point &b)
	{
		return {abs(a.x - b.x), abs(a.y - b.y)};
	}
#endif
}

int main()
{
	// 未测试
	return 0;
}