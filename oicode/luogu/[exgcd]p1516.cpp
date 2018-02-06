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
long long k, tempo;
int main() {
	cin >> x >> y >> m >> n >> l;
	long long a = abs(x - y), b = abs(m - n);
	if(b % gcd(a, l)) cout << "Impossible" << endl;
	exgcd(b, l, k, tempo);
	// kb - l\alpha = -a
	cout << k << endl;
}