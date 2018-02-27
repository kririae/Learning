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
    double maxx = -1e9;
    
    template<typename T>
    inline bool eql(T a, T b) {
        return fabs(a - b) < eps;
    }


    inline Segments the_next(Segments curr)
    {
        // 鑾峰彇鑳藉璧板埌鐨勪笅涓€涓?
        double minx, mina, minb;
        int minindex = 0;
        minx = mina = minb = 1e9;
        for (int i = 0; i < sg.size(); ++i)
        {	
            if(!used[sg[i].index] && !eql(curr.a, sg[i].a)) {
                Point ret = inter(curr, sg[i]);	
                if(ret.x <= maxx) continue;
                if(eql(ret.x, minx)) {
                    if (sg[i].a > mina) 
                        mina = sg[i].a, minindex = i;
                } else if (ret.x < minx) {
                    minx = ret.x, minindex = i;
                }
            }
        } // 鑾峰彇y鏈€澶х殑閭ｄ釜鐐瑰拰鎵€鏈夌洿绾裤€?
        used[sg[minindex].index] = true;
        maxx = max(maxx, minx);
        return sg[minindex];
    }

	double n, a, b;
	vector<Segments> sg;
	vector<int> res;
	bitset<100005> used;
	
	template<typename T>
	inline bool eql(T a, T b) {
		return fabs(a - b) < eps;
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
    涓や釜O(n)姹傚嚭鏈€宸﹁竟鐨勭鐐癸紝
    */
    inline void solve()
    {
        init();
        Segments seg_min(1e9, 1e9); // 鏈€灏廰鐨勭嚎娈?
        Segments seg_max(-1e9, -1e9); // 鏈€澶鐨勭嚎娈?
        for (int i = 0; i < sg.size(); ++i) 
        {
            if(eql(seg_min.a, sg[i].a)) {
                if(seg_min.b < sg[i].b)
                    seg_min = sg[i];
            } else if(seg_min.a > sg[i].a) {
                seg_min = sg[i];
            }
            if(eql(seg_max.a, sg[i].a)) {
                if(seg_max.b < sg[i].b) 
                    seg_max = sg[i];
            }
            else if(seg_max.a < sg[i].a) {
                seg_max = sg[i];
            }
        }
        // seg_min鏄枩鐜囨渶澶х殑绾挎
        res.push_back(seg_min.index);
        used[seg_min.index] = true;
        while(!(seg_max == (seg_min = the_next(seg_min)))) res.push_back(seg_min.index);
        res.push_back(seg_max.index);
        used[seg_max.index] = true;
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    }
}

int main()
{
    solve::solve();
}