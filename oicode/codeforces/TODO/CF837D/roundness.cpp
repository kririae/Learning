#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::endl;

template<typename T>
inline T max(T a, T b) {
	return a > b ? a : b;
}
template<typename T>
inline T min(T a, T b) {
	return a < b ? a : b;
}

inline long long read()
{
	long long x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
const int maxn = 205 * 65;

long long n, k;
long long ai;
long long f[205][maxn];  // 选k个，其中有i个2，总共->个5
int main() {
	f[0][0] = 0;
	n = read(); k = read();
	for (int rp = 0; rp < n; ++rp) {
		ai = read();
		long long c2 = 0, c5 = 0;
		long long tprf = ai, tprs = ai;
		while(tprf % 5 == 0) ++c5, tprf /= 5;
		while(tprs % 2 == 0) ++c2, tprs /= 2;
		for (int i = k; i >= 0; --i) {
			for (int j = maxn - 1; j >= 0; --j) {
			    if(j - c2 >= 0 && i - 1 >= 0)
				f[i][j] = max(f[i - 1][j - c2] + c5, f[i][j]);
			}
		}
	}
	long long res = 0;
	for (long long i = 0; i <= maxn; ++i) {
		res = max(min(f[k][i], i), res);
	}
	cout << res << endl;
	return 0;
}
