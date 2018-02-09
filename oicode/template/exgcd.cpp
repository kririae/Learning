template<typename T>
inline void exgcd(T a, T b, T &g, T &x, T &y)
{
	!b ? (x = 1, y = 0, g = a) : (exgcd(b, a % b, g, y, x), y -= (a / b) * x);
}   
