#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

template<typename T>
inline void exgcd(T a, T b, T &x, T &y)
{
	!b ? (x = 1, y = 0) : (exgcd(b, a % b, y, x), y -= (a / b) * x);
}   
template<typename T>
inline T gcd(T a, T b) {
	return b ? gcd(b, a % b) : a;
}

template<typename T>
inline T abs(T val) {
	return val < 0 ? -val : val;
}

long long x, y, m, n, l;
long long  xi, yi;
int main() {
	cin >> x >> y >> m >> n >> l;
	long long a = x - y, b = m - n;
	if(b < 0) a = -a, b = -b;
	long long muv = gcd(b, l);
	if(a % muv != 0) // 假如说不能整除，代表无解
		cout << "Impossible" << endl;
	exgcd(b, l, xi, yi);
	cout << ((xi * a / muv) % (l / muv) + (l / r)) % (l / r) << endl;
}