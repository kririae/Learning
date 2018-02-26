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
		Point operator+ (const Point &a) { return Point(x + a.x, y + a.y); }
		Point operator- (const Point &a) { return Point(x - a.x, y - a.y); }
		Point operator* (const double &a) { return Point(x * a, y * a); }
		Point operator/ (const double &a) { return Point(x / a, y / a); }
		Point operator= (const Point &a) { x = a.x, y = a.y; return Point(x, y); }
		double operator* (const Point &a) { return x * a.y - y * a.x; }
		bool operator< (const Point &a)
		{ return fabs(x - a.x) < eps ? y > a.y : x > a.x; }
		bool operator== (const Point &a)
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
		Segments operator= (const Segments &x) 
		{ a = x.a, b = x.b, index = x.index; return Segments(x.a, x.b); }
		bool operator== (const Segments &x)
		{ return fabs(a - x.a) < eps && fabs(b - x.b) < eps; }
		bool operator< (const Segments &x)
		{ return fabs(a - x.a) < eps ? b < x.b : a < x.a; }
	};
	
	std::ostream &operator<<(std::ostream &os, const Point &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    
    std::ostream &operator<<(std::ostream &os, const Segments &p)
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

	double n, a, b;
	vector<Segments> sg;
	vector<int> res;
	bitset<50005> used;
	
	template<typename T>
	inline bool eql(T a, T b) {
		return fabs(a - b) < eps;
	}
	inline void delete_all(double a)
	{
		for (int i = 0; i < sg.size(); ++i) {
			if(eql(sg[i].a, a)) used[sg[i].index] = true;
		}
	}
	inline Segments the_next(Segments curr)
	{
		// 获取能够走到的下一个
		double minx, mina, minb;
		int minindex = 0;
		minx = mina = minb = 1e9;
		for (int i = 0; i < sg.size(); ++i)
		{	
			if(!used[sg[i].index] && !eql(curr.a, sg[i].a)) {
				Point ret = inter(curr, sg[i]);	
				if(eql(ret.x, minx)) {
					if (sg[i].a > mina) 
						mina = sg[i].a, minindex = i;
				} else if (ret.x < minx) {
					minx = ret.x, minindex = i;
				}
			}
		} // 获取y最大的那个点和所有直线。
		used[sg[minindex].index] = true;
		delete_all(sg[minindex].a);
		return sg[minindex];
	}

	inline void init()
	{
		n = read();
		for (register int i = 1; i <= n; ++i)
		{
			a = read(); b = read();
			sg.push_back(Segments(a, b, i));
		}
	}
	/*
	两个O(n)求出最左边的端点，
	*/
	inline void solve()
	{
	    init();
		Segments cs(1e9, 1e9); // 最小a的线段
		Segments cm(-1e9, -1e9); // 最大a的线段
		for (int i = 0; i < sg.size(); ++i) 
		{
			if(eql(cs.a, sg[i].a)) {
				if(cs.b < sg[i].b)
					cs = sg[i];
			} else if(cs.a > sg[i].a) {
				cs = sg[i];
			}
			if(eql(cm.a, sg[i].a)) {
				if(cm.b < sg[i].b) 
					cm = sg[i];
			}
			else if(cm.a < sg[i].a) {
				cm = sg[i];
			}
		}
		// cs是斜率最大的线段
		res.push_back(cs.index);
		used[cs.index] = true;
		delete_all(cs.a);
		while(!(cm == (cs = the_next(cs)))) res.push_back(cs.index);
		res.push_back(cm.index);
		used[cm.index] = true;
		delete_all(cm.a);
		sort(res.begin(), res.end());
		for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
    solve::solve();
}

/*

8
2 3 
1 5 
0 4
6 3 
-1 -7 
-1 -6
1 7
6 5

*/
